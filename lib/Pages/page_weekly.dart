import 'package:application/Graphs/weekly_bar_chart.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;


class WeeklyPage extends StatefulWidget {
  const WeeklyPage({super.key});

  @override
  State<WeeklyPage> createState() => _WeeklyPageState();
}

class _WeeklyPageState extends State<WeeklyPage> {

  // TODO: Get real data from database
  List<double> weeklyData = [];

  DateTime dateSelected = DateTime.now(); // Current date and time
  DateTime dateNextSaturday = DateTime.now(); // Next saturday from selected date
  DateFormat dateFormat = DateFormat.MMMEd(); // Date formatter for the UI
  String nextSaturday = ""; // String form next saturday for display
  String thisSunday = ""; // String form of this sunday for display
  bool isInitialized = false; // Tracks whether date has been initialized
  int dateCorrection = 0; // Number used to calculate when next Saturday is relative to current date
  String type = "";
  double min = 0;
  double max = 0;

  void initializeDate() {
    if (!isInitialized) {
      setState(() {
        dateSelected = dateSelected.subtract(Duration(hours: dateSelected.hour, minutes: dateSelected.minute, seconds: dateSelected.second, milliseconds: dateSelected.millisecond));

        if (dateSelected.weekday == 7) {
          dateNextSaturday = dateSelected.add(const Duration(days: 6));
        } else if (dateSelected.weekday == 6) {
          dateNextSaturday = dateSelected;
        } else {
          dateNextSaturday =
              dateSelected.add(Duration(days: 6 - dateSelected.weekday));
        }

        nextSaturday = dateFormat.format(dateNextSaturday);
        thisSunday = dateFormat.format(dateNextSaturday.subtract(const Duration(days: 6)));

        type = "Average Heart Rate";
        updateData();

        isInitialized = true;
      });
    }
  }

  void nextWeek (){
    setState(() {
      dateNextSaturday = dateNextSaturday.add(const Duration(days: 7));

      nextSaturday = dateFormat.format(dateNextSaturday);
      thisSunday = dateFormat.format(dateNextSaturday.subtract(const Duration(days: 6)));
    });

    updateData();
  }

  void lastWeek () {
    setState(() {
      dateNextSaturday = dateNextSaturday.subtract(const Duration(days: 7));

      nextSaturday = dateFormat.format(dateNextSaturday);
      thisSunday = dateFormat.format(dateNextSaturday.subtract(const Duration(days: 6)));
    });

    updateData();
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
    DateTime dateStart = dateNextSaturday.subtract(const Duration(days: 6));
    DateTime dateNext = dateStart.add(const Duration(days: 1));

    List<double> newWeekly = [];

    if (type == "Average Heart Rate") {
      double total_hr = 0.0;

      for (int d = 0; d < 7; d++) {
        List<List<dynamic>> results = await db.connection.query(
            "SELECT hr FROM sensors WHERE user_id=0 AND timestamp>'$dateStart' AND timestamp<'$dateNext' ORDER BY timestamp");
        for (int i = 0; i < results.length; i++) {
          total_hr += results[i][0];
        }


        if (results.isNotEmpty) {
          newWeekly.add(total_hr / results.length);
        } else {
          newWeekly.add(0);
        }

        total_hr = 0;
        dateStart = dateNext;
        dateNext = dateNext.add(const Duration(days: 1));
      }
    } else {
      double floors_climbed = 0.0;
      int curr_amt = 0;
      String curr_direction = "";

      for (int d = 0; d < 7; d++) {
        List<List<dynamic>> results = await db.connection.query(
            "SELECT amt, direction FROM climbs WHERE user_id=0 AND timestamp>'$dateStart' AND timestamp<'$dateNext' ORDER BY timestamp");

        for (int i = 0; i < results.length; i++) {
          curr_amt = results[i][0];
          curr_direction = results[i][1];
          if (curr_direction == "up") {
            floors_climbed += curr_amt;
          } else {
            floors_climbed -= curr_amt;
          }
        }

        newWeekly.add(floors_climbed);

        floors_climbed = 0;

        dateStart = dateNext;
        dateNext = dateNext.add(const Duration(days: 1));

      }
    }

    setState(() {
      weeklyData = newWeekly;
    });
  }

  Widget buildChart() {
    if (weeklyData.isEmpty) {
      return Center(child: Text("Loading chart...", style: style.textStyle,),);
    } else {
      return WeeklyBarChart(data: weeklyData, min: findMin(), max: findMax() + 5);
    }
  }

  // This function finds the minimum of the data in the chart
  double findMin() {

    double min = weeklyData[0];

    for (int i = 1; i < weeklyData.length; i++) {
      if (min == 0) {
        min = weeklyData[i];
      } else if (weeklyData[i] < min) {
        min = weeklyData[i];
      }
    }

    if (type == "Average Heart Rate") {
      if (min > 5) {
        min -= 5;
      } else {
        min = 0;
      }
    } else if (type == "Floors Climbed") {
      if (min > 25) {
        min -= 25;
      } else if (min < 0 ) {
        min -= 10;
      } else {
        min = 0;
      }
    }

    return min;

  }

  // This function finds the maximum of the data in the chart
  double findMax() {

    double max = weeklyData[0];

    for (int i = 1; i < weeklyData.length; i++) {
      if (weeklyData[i] > max) {
        max = weeklyData[i];
      }
    }

    return max;

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
        title: const Text("Weekly Bar Chart"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
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
            Divider(
              color: style.subtextStyle.color,
            ),
            Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  IconButton(
                    onPressed: lastWeek,
                    icon: Icon(Icons.keyboard_arrow_left, color: style.iconColor),
                    splashRadius: 15.0,
                  ),
                  Text("$thisSunday - $nextSaturday", style: style.textStyle),
                  IconButton(
                    onPressed: nextWeek,
                    icon: Icon(Icons.keyboard_arrow_right, color: style.iconColor),
                    splashRadius: 15.0,
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
}
