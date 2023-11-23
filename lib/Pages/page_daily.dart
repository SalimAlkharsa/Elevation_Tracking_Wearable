import 'package:application/Graphs/daily_line_chart.dart';
import 'package:application/Graphs/individual_point.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class DailyPage extends StatefulWidget {
  const DailyPage({super.key});

  @override
  State<DailyPage> createState() => _DailyPageState();
}

class _DailyPageState extends State<DailyPage> {
  List<IndividualPoint> dailyData = [];
  DateTime dateSelected = DateTime.now();// Initialized to current date
  DateFormat dateFormat = DateFormat.MMMEd(); // Date formatter for the UI
  String currentDate = ""; // String form of the date for display
  bool isInitialized = false; // Tracks whether date has been initialized
  String mode = "";

  void initializeDate() {
    if (!isInitialized) {
      setState(() {
        mode = "Floors Climbed";
        dateSelected = dateSelected.subtract(Duration(hours: dateSelected.hour, minutes: dateSelected.minute, seconds: dateSelected.second, milliseconds: dateSelected.millisecond));
        currentDate = dateFormat.format(dateSelected);
        updateData();
        isInitialized = true;
      });
    }
  }

  void tomorrow (){
    setState(() {
      dateSelected = dateSelected.add(const Duration(days: 1));

      currentDate = dateFormat.format(dateSelected);

      updateData();
    });
  }

  void yesterday () {
    setState(() {
      dateSelected = dateSelected.subtract(const Duration(days: 1));

      currentDate = dateFormat.format(dateSelected);

      updateData();
    });
  }

  Future<void> updateData() async {

    List<IndividualPoint> newDailyData = [];

    DateTime nextDate = dateSelected.add(const Duration(days: 1));

    if (mode == "Floors Climbed") {
      String curr_direction = "";
      int curr_amt = 0;
      int tot_amt = 0;

      DateTime curr_timestamp;
      double hour_val = 0.0;

      List<List<dynamic>> results = await db.connection.query("SELECT amt, direction, timestamp FROM climbs WHERE user_id=0 AND timestamp>'$dateSelected' AND timestamp<'$nextDate'");

      for (int i = 0; i < results.length; i++) {
        curr_amt = results[i][0];
        curr_direction = results[i][1];
        curr_timestamp = results[i][2];
        hour_val = curr_timestamp.hour + (curr_timestamp.minute / 60) + (curr_timestamp.second / (60 * 60));
        if (curr_direction == "up") {
          tot_amt += curr_amt;
        } else {
          tot_amt -= curr_amt;
        }
        newDailyData.add(IndividualPoint(x: hour_val, y: tot_amt.toDouble()));
      }
    } else if (mode == "Heart Rate") {

      double hr = 0.0;
      double hour_val = 0.0;
      DateTime curr_timestamp;

      print("Date range: $dateSelected - $nextDate");

      List<List<dynamic>> results = await db.connection.query("SELECT hr, timestamp FROM sensors WHERE user_id=0 AND timestamp>'$dateSelected' AND timestamp<'$nextDate'");

      for (int i = 0; i < results.length; i++) {
        hr = results[i][0];
        curr_timestamp = results[i][1];
        hour_val = curr_timestamp.hour + (curr_timestamp.minute / 60) + (curr_timestamp.second / (60 * 60));

        print("Adding point: $hour_val, $hr");

        newDailyData.add(IndividualPoint(x: hour_val, y: hr));
      }
    }

    setState(() {
      dailyData = newDailyData;
    });
  }

  Widget buildChart() {
    if (dailyData.isEmpty) {
      return SizedBox(
        height: 200,
        width: MediaQuery.of(context).size.width * 0.9,
        child: const Center(
          child: Text("No data for selected date."),
        )
      );
    } else {
      return SizedBox(
        height: 200,
        width: MediaQuery.of(context).size.width * 0.9,
        child: DailyLineChart(data: dailyData, min: findMin(), max: findMax()),
      );
    }
  }

  double findMin() {
    double min = dailyData[0].y;

    for (int i = 1; i < dailyData.length; i++) {
      if (dailyData[i].y < min) {
        min = dailyData[i].y;
      }
    }

    return min;
  }

  double findMax() {
    double max = dailyData[0].y;

    for (int i = 1; i < dailyData.length; i++) {
      if (dailyData[i].y > max) {
        max = dailyData[i].y;
      }
    }

    return max;
  }

  void updateMode(String? selectedValue) {
    if (selectedValue is String) {
      setState(() {
        mode = selectedValue;
      });
      updateData();
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
        title: const Text("Daily Line Chart"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            DropdownButton(
              items: const [
                DropdownMenuItem(
                    value: "Heart Rate",
                    child: Text("Heart Rate")
                ),
                DropdownMenuItem(
                    value: "Floors Climbed",
                    child: Text("Floors Climbed")
                ),
              ],
              value: mode,
              onChanged: updateMode,
              focusColor: style.backgroundColor,
            ),
            Divider(
              color: style.subtextStyle.color,
            ),
            Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  IconButton(
                    onPressed: yesterday,
                    icon: Icon(Icons.keyboard_arrow_left, color: style.iconColor),
                    splashRadius: 15.0,
                  ),
                  Text(currentDate, style: style.textStyle),
                  IconButton(
                    onPressed: tomorrow,
                    icon: Icon(Icons.keyboard_arrow_right, color: style.iconColor),
                    splashRadius: 15.0,
                  ),
                ]
            ),
            Divider(
              color: style.subtextStyle.color,
            ),
            buildChart(),
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
}
