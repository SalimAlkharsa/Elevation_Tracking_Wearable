import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class SettingsPage extends StatefulWidget {
  const SettingsPage({super.key});

  @override
  State<SettingsPage> createState() => _SettingsPageState();
}

class _SettingsPageState extends State<SettingsPage> {
  // Initialize local data
  double userHeight = 0.0;
  double userWeight = 0.0;
  int stepGoal = 0;
  int floorGoal = 0;

  // The text editing controller is used to capture user input and pass it into
  // local copies of data through dialog boxes
  late TextEditingController controller;

  // initState() and dispose() need to be overridden to handle the controller
  @override
  void initState() {
    super.initState();

    controller = TextEditingController();

    initializeSettings();
  }

  @override
  void dispose() {
    controller.dispose();

    finalizeSettings();

    super.dispose();
  }

  Widget buildBody() {
    if (db.connection.isClosed) {
      return Center(child: Text("No connection. Please reconnect to the WiFi and restart the app. If this issue persists, contact support.", style: style.textStyle,),);
    } else {
      return ListView(
        children: <Widget>[
          // TODO: Explain sign out
          ListTile(
              title: Text("Sign Out", style: style.textStyle),
              trailing: IconButton (
                icon: Icon(Icons.logout, color: style.iconColor),
                // TODO: Implement sign out
                onPressed: () {
                  Navigator.pushReplacementNamed(context, '/');
                },
              )
          ),
          Divider(
            color: style.subtextStyle.color,
          ),
          // A simple switch widget for turning dark mode on and off
          // TODO: Explain handling dark mode
          ListTile(
            title: Text("Dark Mode", style: style.textStyle),
            trailing: Switch(
              activeColor: style.mainColor,
              activeTrackColor: style.tooltipColor,
              value: style.switchValue,
              onChanged: darkMode,
            ),
          ),
          Divider(
            color: style.subtextStyle.color,
          ),
          // These next four widgets allow you to update the height, weight, and daily goals for the user
          // Their title and subtitle is set relative to what value you are updating
          // When tapped, they open the openTextEntryDialog() function, which allows the user to update the entry
          // Once they receive the value from the text entry dialog, they attempt to update the local copy
          // The tryParse function returns null if the string cannot be properly converted to the data type necessary
          // If that happens, the error dialog for the corresponding data type is opened, alerting the user to the incorrect value
          // and returning from the function to prevent from updating with bad data both locally and to the database
          // If the error check passes, the local copy is updated, and so is the entry in the database
          // TODO: Explain database entry
          ListTile(
            title: Text("Set Height (in)", style: style.textStyle),
            subtitle: Text("$userHeight", style: style.subtextStyle),
            onTap: () async {
              final newHeight = await openTextEntryDialog();
              if (newHeight == null || newHeight.isEmpty || double.tryParse(newHeight) == null) {
                errorDoubleDialog();
                return;
              } else if (double.parse(newHeight) < 0) {
                errorSmallDialog(0);
                return;
              }

              setState(() => userHeight = double.parse(newHeight));
            },
          ),
          Divider(
            color: style.subtextStyle.color,
          ),
          ListTile(
            title: Text("Set Weight (lbs)", style: style.textStyle),
            subtitle: Text("$userWeight", style: style.subtextStyle),
            onTap: () async {
              final newWeight = await openTextEntryDialog();
              if (newWeight == null || newWeight.isEmpty || (double.tryParse(newWeight) == null)) {
                errorDoubleDialog();
                return;
              } else if (double.parse(newWeight) < 0) {
                errorSmallDialog(0);
                return;
              }

              setState(() => userWeight = double.parse(newWeight));
            },
          ),
          // Divider(
          //   color: style.subtextStyle.color,
          // ),
          // ListTile(
          //   title: Text("Set Step Daily Goal", style: style.textStyle),
          //   subtitle: Text("$stepGoal", style: style.subtextStyle),
          //   onTap: () async {
          //     final newGoal = await openTextEntryDialog();
          //     if (newGoal == null || newGoal.isEmpty || (int.tryParse(newGoal) == null)) {
          //       errorIntDialog();
          //       return;
          //     }
          //
          //     setState(() => stepGoal = int.parse(newGoal));
          //   },
          // ),
          Divider(
            color: style.subtextStyle.color,
          ),
          ListTile(
            title: Text("Set Floor Daily Goal", style: style.textStyle),
            subtitle: Text("$floorGoal", style: style.subtextStyle),
            onTap: () async {
              final newGoal = await openTextEntryDialog();
              if (newGoal == null || newGoal.isEmpty || (int.tryParse(newGoal) == null) ) {
                errorIntDialog();
                return;
              } else if (int.parse(newGoal) < 1) {
                errorSmallDialog(1);
                return;
              }

              setState(() => floorGoal = int.parse(newGoal));
            },
          ),
          Divider(
            color: style.subtextStyle.color,
          ),
        ],
      );
    }
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      backgroundColor: style.backgroundColor,

      // The app bar shows the title of the page the user is currently on
      appBar: AppBar(
        title: const Text("Settings"),
        backgroundColor: style.mainColor,
      ),

      // The list view allows for multiple ListTile widgets, which is the backbone of the settings page
      // The Divider widgets between each ListTile make the UI more readable for the user by cleanly
      // dividing each tile
      body: buildBody(),

      // The bottom navigation bar allows for easy access to the three main pages of the application
      bottomNavigationBar: BottomAppBar(
        // This padding makes the icons look cleaner and increase readability for the user
        padding: const EdgeInsets.all(5.0),

        // This color specification allows dark mode to function, as the theme settings in main
        // are only set when the application is initially started
        color: style.backgroundAccent,

        // The Row widget lines all of the children contained into a row
        child: Row(
          // Centers the icons in the navigation bar
          mainAxisAlignment: MainAxisAlignment.center,

          // Each TextButton calls the Navigator to navigate between the three main pages
          // The currently active page is given an onPressed value which is blank and are given a different color
          // This prevents the user from repeatedly pressing the button and causing performance issues
          // Pages which are not active use pushRaplacementNamed to push the new page onto the navigator stack
          // The internal names for each page are defined by the developer and can be found in main.dart
          children: [
            TextButton(
              onPressed: () {},
              child: Icon(Icons.settings, size: 50, color: style.selectedColor),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/main');
              },
              child: Icon(Icons.house, size: 50, color: style.mainColor),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics');
              },
              child: Icon(Icons.bar_chart, size: 50, color: style.mainColor),
            ),
          ],
        ),
      ),
    );
  }

  Future<String?> openTextEntryDialog() => showDialog<String>(
    context: context,
    builder: (context) => AlertDialog(
      title: Text("Edit value", style: style.textStyle),
      backgroundColor: style.backgroundAccent,
      content: TextField(
        decoration: InputDecoration(
          hintText: "Enter value here",
          hintStyle: style.subtextStyle,
        ),
        controller: controller,
        onSubmitted: (_) => submitText(),
        style: style.textStyle,
      ),
      actions: [
        TextButton(
            onPressed: submitText,
            style: TextButton.styleFrom(
              foregroundColor: style.mainColor,
            ),
            child: const Text("SUBMIT"),
        )
      ],
    ),
  );

  void submitText() {
    Navigator.of(context).pop(controller.text);

    controller.clear();
  }

  void errorDoubleDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Value must be a decimal value", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void errorIntDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Value must be an integer", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void errorSmallDialog(double min) => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Value must be equal to or greater than $min", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void close() {
    Navigator.of(context).pop(context);
  }

  void darkMode(bool value) {
    setState(() {
      style.switchValue = value;
    });

    if (style.switchValue) {
      style.mainColor = const Color(0xFF058842);
      style.selectedColor = const Color(0xFF0D5E32);
      style.backgroundColor = const Color(0xFF414141);
      style.backgroundAccent = const Color(0xFF3A3A3A);
      style.iconColor = const Color(0xFFAFAFAF);
      style.textStyle = const TextStyle(
        color: Color(0xFFAFAFAF),
      );
      style.subtextStyle = const TextStyle(
        color: Color(0xFF676767),
      );
      style.tooltipColor = const Color(0xFF282828);
    } else {
      style.mainColor = const Color(0xFF026C34);
      style.selectedColor = const Color(0xFF094824);
      style.backgroundColor = const Color(0xFFEFEFEF);
      style.backgroundAccent = const Color(0xFFD9D9D9);
      style.iconColor = const Color(0xFF676767);
      style.textStyle = const TextStyle(
        color: Color(0xFF343434),
      );
      style.subtextStyle = const TextStyle(
        color: Color(0xFF969696),
      );
      style.tooltipColor = const Color(0xFFBDBDBD);
    }
  }

  Future<void> initializeSettings() async {
    // await db.connection.open();

    List<List<dynamic>> results = await db.connection.query("SELECT * FROM users WHERE user_id=0");

    for (final row in results) {
      print(row[1]);
      print(row[2]);
      print(row[3]);
      print(row[4]);
      print(row[5]);
      print(row[6]);
    }

    setState(() {
      userHeight = results[0][1];
      userWeight = results[0][2];
      stepGoal = results[0][5];
      floorGoal = results[0][6];
    });

    // db.connection.close();
  }

  Future<void> finalizeSettings() async {
    // await db.connection.open();

    await db.connection.query("UPDATE users SET height=$userHeight, weight=$userWeight, daily_steps=$stepGoal, daily_floors=$floorGoal WHERE user_id=0");

    // db.connection.close();
  }
}


