import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

import '../Graphs/two_bar_chart.dart';

class ComparePage extends StatefulWidget {
  const ComparePage({super.key});

  @override
  State<ComparePage> createState() => _ComparePageState();
}

class _ComparePageState extends State<ComparePage> {

  List<double> compare = [];
  DateTime dateLeft = DateTime.now();
  DateTime dateRight = DateTime.now();
  DateFormat dateFormat = DateFormat.MMMEd();
  String leftDateStr = "";
  String rightDateStr = "";
  String type = "";
  double min = 0.0;
  double max = 0.0;
  bool isInitialized = false;

  void initializeDate() {
    if (!isInitialized) {
      setState(() {
        dateLeft = DateTime.now();
        dateRight = DateTime.now();
        leftDateStr = dateFormat.format(dateLeft);
        rightDateStr = dateFormat.format(dateRight);
        type = "Average Heart Rate";
        updateData();
        isInitialized = true;
      });
    }
  }

  void updateType(String? selectedValue) {
    if (selectedValue is String) {
      setState(() {
        type = selectedValue;
      });
      updateData();
    }
  }

  Future<void> updateData() async {
    DateTime nextDateRight = dateRight.add(const Duration(days: 1));
    DateTime nextDateLeft = dateLeft.add(const Duration(days: 1));
    List<double> newCompare = [];
    if (type == "Average Heart Rate") {
      double total_hr = 0.0;
      List<List<dynamic>> results = await db.connection.query("SELECT hr FROM sensors WHERE user_id=0 AND timestamp>'$dateLeft' AND timestamp<'$nextDateLeft'");

      for (int i = 0; i < results.length; i++) {
        total_hr += results[i][0];
      }

      newCompare.add(total_hr / results.length);

      total_hr = 0;

      results = await db.connection.query("SELECT hr FROM sensors WHERE user_id=0 AND timestamp>'$dateRight' AND timestamp<'$nextDateRight'");

      for (int i = 0; i < results.length; i++) {
        total_hr += results[i][0];
      }

      newCompare.add(total_hr / results.length);

      total_hr = 0;

      setState(() {
        min = 170.0;
        max = 210.0;
      });

    } else if (type == "Floors Climbed") {

      double floors_climbed = 0.0;
      int curr_amt = 0;
      String curr_direction = "";

      List<List<dynamic>> results = await db.connection.query("SELECT amt, direction FROM climbs WHERE user_id=0 AND timestamp>'$dateLeft' AND timestamp<'$nextDateLeft'");

      for (int i = 0; i < results.length; i++) {
        curr_amt = results[i][0];
        curr_direction = results[i][1];
        if (curr_direction == "up") {
          floors_climbed += curr_amt;
        } else {
          floors_climbed -= curr_amt;
        }
      }

      newCompare.add(floors_climbed);

      floors_climbed = 0;

      results = await db.connection.query("SELECT amt, direction FROM climbs WHERE user_id=0 AND timestamp>'$dateRight' AND timestamp<'$nextDateRight'");

      for (int i = 0; i < results.length; i++) {
        curr_amt = results[i][0];
        curr_direction = results[i][1];
        if (curr_direction == "up") {
          floors_climbed += curr_amt;
        } else {
          floors_climbed -= curr_amt;
        }
      }

      newCompare.add(floors_climbed);

      floors_climbed = 0;

      setState(() {
        min = 0.0;
        max = 30.0;
      });
    }

    setState(() {
      compare = newCompare;
    });
  }

  Widget buildChart() {

    List<int> nulls = [];

    for (int i = 0; i < compare.length; i++) {
      if (compare[i].isNaN) {
        nulls.add(i);
      }
    }

    if (nulls.isEmpty) {
      return SizedBox(
        height: 200,
        width: MediaQuery.of(context).size.width,
        child: TwoBarChart(data: compare, min: min, max: max),
      );
    } else if (nulls.length == 1) {
      if (nulls[0] == 0) {
        return SizedBox(
            height: 200,
            width: MediaQuery.of(context).size.width,
            child: const Center(
              child: Text("No data for the left date."),
            )
        );
      } else {
        return SizedBox(
            height: 200,
            width: MediaQuery.of(context).size.width,
            child: const Center(
              child: Text("No data for the right date."),
            )
        );
      }
    } else {
      return SizedBox(
          height: 200,
          width: MediaQuery.of(context).size.width,
          child: const Center(
            child: Text("No data for either date."),
          )
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    initializeDate();
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text("Compare Bar Chart"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Divider(
              color: style.subtextStyle.color,
            ),
            Column(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  DropdownButton(
                    items: const [
                      DropdownMenuItem(
                          value: "Average Heart Rate",
                          child: Text("Average Heart Rate")
                      ),
                      DropdownMenuItem(
                          value: "Floors Climbed",
                          child: Text("Floors Climbed")
                      ),
                    ],
                    value: type,
                    onChanged: updateType,
                    focusColor: style.backgroundColor,
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    children: [
                      TextButton(
                        onPressed: () async {
                          DateTime? newDate = await pickDate(dateLeft);

                          if (newDate == null) return;

                          setState(() {
                            dateLeft = newDate;
                            leftDateStr = dateFormat.format(dateLeft);
                          });

                          updateData();
                        },
                        child: Text(leftDateStr, style: style.textStyle),
                      ),
                      TextButton(
                        onPressed: () async {
                          DateTime? newDate = await pickDate(dateRight);

                          if (newDate == null) return;

                          setState(() {
                            dateRight = newDate;
                            rightDateStr = dateFormat.format(dateRight);
                          });

                          updateData();
                        },
                        child: Text(rightDateStr, style: style.textStyle),
                      ),
                    ],
                  ),
                ]
            ),
            Divider(
              color: style.subtextStyle.color,
            ),
            SizedBox(
              height: 200,
              child: buildChart(),
            ),
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
                Navigator.pushReplacementNamed(context, '/');
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

  Future<DateTime?> pickDate(DateTime date) {
    Future<DateTime?> newDate = showDatePicker(
      context: context,
      initialDate: date,
      firstDate: DateTime(2000),
      lastDate: DateTime(2100),
      builder: (context, child) {
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: ColorScheme.light(
              primary: style.mainColor, // header background color
              onPrimary: Colors.white, // body text color
            ),
            textButtonTheme: TextButtonThemeData(
              style: TextButton.styleFrom(
                foregroundColor: style.mainColor, // button text color
              ),
            ),
          ),
          child: child!,
        );
      },
    );

    return newDate;
  }
}
