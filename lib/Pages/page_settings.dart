import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class SettingsPage extends StatefulWidget {
  const SettingsPage({super.key});

  @override
  State<SettingsPage> createState() => _SettingsPageState();
}

class _SettingsPageState extends State<SettingsPage> {
  // Initialize local data
  bool _switchValue = false;
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
  }

  @override
  void dispose() {
    controller.dispose();

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // The app bar shows the title of the page the user is currently on
      appBar: AppBar(
        title: Text("Settings"),
      ),

      // The list view allows for multiple ListTile widgets, which is the backbone of the settings page
      // The Divider widgets between each ListTile make the UI more readable for the user by cleanly
      // dividing each tile
      body: ListView(
        children: <Widget>[
          // TODO: Explain sign out
          ListTile(
            title: Text("Sign Out"),
            trailing: IconButton (
              icon: Icon(Icons.logout),
              // TODO: Implement sign out
              onPressed: () {},
            )
          ),
          Divider(),
          // A simple switch widget for turning dark mode on and off
          // TODO: Explain handling dark mode
          ListTile(
            title: Text("Dark Mode"),
            trailing: Switch(
              value: _switchValue,
              onChanged: (value) {
                setState(() {
                  _switchValue = value;
                });
              },
            ),
          ),
          Divider(),
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
            title: Text("Set Height (in)"),
            subtitle: Text("$userHeight"),
            onTap: () async {
              final newHeight = await openTextEntryDialog();
              if (newHeight == null || newHeight.isEmpty || double.tryParse(newHeight) == null) {
                errorDoubleDialog();
                return;
              }

              setState(() => userHeight = double.parse(newHeight));
              //TODO: Update database with new value
            },
          ),
          Divider(),
          ListTile(
            title: Text("Set Weight (lbs)"),
            subtitle: Text("$userWeight"),
            onTap: () async {
              final newWeight = await openTextEntryDialog();
              if (newWeight == null || newWeight.isEmpty || (double.tryParse(newWeight) == null)) {
                errorDoubleDialog();
                return;
              }

              setState(() => userWeight = double.parse(newWeight));
              //TODO: Update database with new value
            },
          ),
          Divider(),
          ListTile(
            title: Text("Set Step Daily Goal"),
            subtitle: Text("$stepGoal"),
            onTap: () async {
              final newGoal = await openTextEntryDialog();
              if (newGoal == null || newGoal.isEmpty || (int.tryParse(newGoal) == null)) {
                errorIntDialog();
                return;
              }

              setState(() => stepGoal = int.parse(newGoal));
              //TODO: Update database with new value
            },
          ),
          Divider(),
          ListTile(
            title: Text("Set Floor Daily Goal"),
            subtitle: Text("$floorGoal"),
            onTap: () async {
              final newGoal = await openTextEntryDialog();
              if (newGoal == null || newGoal.isEmpty || (int.tryParse(newGoal) == null)) {
                errorIntDialog();
                return;
              }

              setState(() => floorGoal = int.parse(newGoal));
              //TODO: Update database with new value
            },
          ),
          Divider(),
        ],
      ),

      // The bottom navigation bar allows for easy access to the three main pages of the application
      bottomNavigationBar: BottomAppBar(
        // This padding makes the icons look cleaner and increase readability for the user
        padding: const EdgeInsets.all(5.0),

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
              child: Icon(Icons.settings, size: 50, color: Colors.blueGrey[800]),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/');
              },
              child: const Icon(Icons.house, size: 50),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics');
              },
              child: const Icon(Icons.bar_chart, size: 50),
            ),
          ],
        ),
      ),
    );
  }

  Future<String?> openTextEntryDialog() => showDialog<String>(
    context: context,
    builder: (context) => AlertDialog(
      title: Text("Edit text"),
      content: TextField(
        decoration: InputDecoration(hintText: "Enter text here."),
        controller: controller,
        onSubmitted: (_) => submitText(),
      ),
      actions: [
        TextButton(
            onPressed: submitText,
            child: Text("SUBMIT"),
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
      title: Text("Error: Value must be a decimal value"),
      actions: [
        TextButton(
          onPressed: close,
          child: Text("OK"),
        )
      ],
    ),
  );

  void errorIntDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      title: Text("Error: Value must be an integer"),
      actions: [
        TextButton(
          onPressed: close,
          child: Text("OK"),
        )
      ],
    ),
  );

  void close() {
    Navigator.of(context).pop(context);
  }
}


