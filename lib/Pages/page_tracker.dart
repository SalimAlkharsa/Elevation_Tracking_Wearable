import 'dart:async';

import 'package:application/Graphs/individual_bar.dart';
import 'package:application/Graphs/tracker_bar_chart.dart';
import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class TrackerPage extends StatefulWidget {
  const TrackerPage({super.key});

  @override
  State<TrackerPage> createState() => _TrackerPageState();
}

class _TrackerPageState extends State<TrackerPage> {

  // TODO: Get real data from database
  List<IndividualBar> trackerData = [];

  List<String> nameList = [];
  List<String> validNameList = [];
  List<Widget> textList = [];

  DateTime dateCursor = DateTime.now();

  double min = 0;
  double max = 0;

  bool initialized = false;

  // The text editing controller is used to capture user input and pass it into
  // local copies of data through dialog boxes
  late TextEditingController controller;

  late Timer polling;

  // initState() and dispose() need to be overridden to handle the controller
  @override
  void initState() {
    super.initState();

    setUpTimedFetch();

    controller = TextEditingController();
  }

  setUpTimedFetch() {
    polling = Timer.periodic(const Duration(seconds: 5), (timer) {
      setState(() {
        updateData();
      });
    });
  }

  @override
  void dispose() {
    controller.dispose();

    polling.cancel();

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {

    if (!initialized) {
      initializeData();
    }


    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text("Tracker Bar Chart"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            FloatingActionButton.extended(
              label: Text("Add User", style: style.buttonTextStyle),
              backgroundColor: style.mainColor,
              onPressed: () async {
                final newName = await openTextEntryDialog();
                if (newName == null || newName.isEmpty || !checkName(newName)) {
                  errorNameDialog();
                  return;
                }

                setState(() => nameList.add(newName));

                updateData();
              },
            ),
            Divider(color: style.subtextStyle.color),
            SizedBox(
              height: 200,
              child: TrackerBarChart(data: trackerData, min: min, max: max),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: textList,
            )
          ],
        ),
      ),

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
          // Pages which are not active use pushReplacementNamed to push the new page onto the navigator stack
          // The internal names for each page are defined by the developer and can be found in main.dart
          children: [
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/settings');
              },
              child: Icon(Icons.settings, size: 50, color: style.mainColor),
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
              child: Icon(Icons.bar_chart, size: 50, color: style.selectedColor),
            ),
          ],
        ),
      ),// This trailing comma makes auto-formatting nicer for build methods.
    );
  }

  void initializeData () async {

    List<List<dynamic>> results = await db.connection.query("SELECT first_name FROM users ORDER BY user_id");

    setState(() {
      dateCursor = dateCursor.subtract(const Duration(hours: 5));

      for (int i = 0; i < results.length; i++) {
        validNameList.add(results[i][0]);
      }

      initialized = true;
    });
  }

  void updateData () async {

    String curr_name = "";
    String curr_direction = "";
    int curr_amt = 0;
    int tot_amt = 0;
    double newMax = 0.0;
    double newMin = 0.0;

    setState(() {
      dateCursor = dateCursor.subtract(const Duration(minutes: 1));
    });

    print("$dateCursor");

    setState(() {
      textList.clear();

      for (int i = 0; i < nameList.length; i++) {
        textList.add(Text(nameList[i]));
      }

    });

    List<IndividualBar> newTrackerData = [];
    print("Date cursor: $dateCursor");

    for (int i = 0; i < nameList.length; i++) {

      curr_name = nameList[i];
      List<List<dynamic>> results = await db.connection.query(
          "SELECT amt, direction FROM climbs INNER JOIN users ON climbs.user_id = users.user_id WHERE first_name='$curr_name' AND timestamp>'$dateCursor'");

      for (int i = 0; i < results.length; i++) {
        curr_amt = results[i][0];
        curr_direction = results[i][1];
        if (curr_direction == "up") {
          tot_amt += curr_amt;
        } else {
          tot_amt -= curr_amt;
        }
      }

      if (tot_amt > newMax) {
        newMax = tot_amt.toDouble();
      }

      if (tot_amt < newMin) {
        newMin = tot_amt.toDouble();
      }

      newTrackerData.add(IndividualBar(x: i, y: tot_amt.toDouble()));

      tot_amt = 0;
    }

    setState(() {
      trackerData = newTrackerData;
      min = newMin;
      max = newMax;
    });
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

  void errorNameDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Not a valid name", style: style.textStyle),
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

  bool checkName(String name) {
    bool isValid = false;

    for (int i = 0; i < validNameList.length; i++) {
      if (name == validNameList[i]) {
        isValid = true;
      }
    }

    for (int i = 0; i < nameList.length; i++) {
      if (name == nameList[i]) {
        isValid = false;
      }
    }

    return isValid;
  }
}
