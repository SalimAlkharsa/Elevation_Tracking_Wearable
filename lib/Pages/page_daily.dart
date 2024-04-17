// IMPORTS

import 'package:application/Graphs/daily_line_chart.dart';
import 'package:application/Graphs/individual_point.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

// DEFINITION

// This class defines the daily data page, which houses a line chart which shows
// changes in values over the course of the selected date for multiple data types
class DailyPage extends StatefulWidget {
  const DailyPage({super.key});

  @override
  State<DailyPage> createState() => _DailyPageState();
}

class _DailyPageState extends State<DailyPage> {

  List<IndividualPoint> dailyData = []; // The list of points used to populate the line chart
  DateTime dateSelected = DateTime.now();// Initialized to current date
  DateFormat dateFormat = DateFormat.MMMEd(); // Date formatter for the UI
  String currentDate = ""; // String form of the date for display
  bool isInitialized = false; // Tracks whether data has been initialized
  String mode = ""; // A string to contain the type of data being compared
  String username = db.user;

  // This function initializes the data members to their required values
  void initializeDate() {

    // Checks if the data has already been initialized
    if (!isInitialized) {

      setState(() {

        // The page starts in floors climbed mode
        mode = "Floors Climbed";

        // This zeroes out the date gathered and formats it correctly, so that
        // data is tracked for the entire day, and not from the middle of the day to the end
        dateSelected = dateSelected.subtract(Duration(hours: dateSelected.hour, minutes: dateSelected.minute, seconds: dateSelected.second, milliseconds: dateSelected.millisecond));
        currentDate = dateFormat.format(dateSelected);

        // The data is then updated with the values for the current date
        updateData();

        // This is to keep the page from continuously initializing
        isInitialized = true;
      });
    }
  }

  // This function changes the selected date to 'tomorrow' relative to the current date
  void tomorrow () {

    setState(() {

      dateSelected = dateSelected.add(const Duration(days: 1));
      currentDate = dateFormat.format(dateSelected);

      // The data is then updated with the values for the current date
      updateData();
    });
  }

  // This function changes the selected date to 'yesterday' relative to the current date
  void yesterday () {

    setState(() {

      dateSelected = dateSelected.subtract(const Duration(days: 1));
      currentDate = dateFormat.format(dateSelected);

      // The data is then updated with the values for the current date
      updateData();
    });
  }


  Future<void> updateData() async {

    // Math cannot be done within strings so the edge of the date range must be initialized here
    DateTime nextDate = dateSelected.add(const Duration(days: 1));

    // Creating a new list and using setState at the end of the function makes updating
    // the data look more aesthetically pleasing, as both values are updated at once
    List<IndividualPoint> newDailyData = [];

    if (mode == "Floors Climbed") {

      String label = ""; // Stores the direction of the given climb
      int tot_amt = 0; // Sum of floors climbed over the course of the day

      // The current timestamp must be tracked in order to calculate the x value for each point
      DateTime curr_timestamp;

      // A double representing the exact hour you are in, hour 3.5 is 3:30
      double hour_val = 0.0;

      // The database is queried for climb data which happened on the given date
      List<List<dynamic>> results = await db.connection.query(
          "SELECT timestamp, label FROM data WHERE username='$username' AND timestamp>'$dateSelected' AND timestamp<'$nextDate' AND label!='walk' ORDER BY timestamp");

      for (int i = 0; i < results.length; i++) {

        curr_timestamp = results[i][0]; // Get the timestamp of the entry in the database
        label = results[i][1]; // Get the label of the the entry in the database

        // Calculate the hour_val using constants derived from how many minutes and seconds are in an hour
        hour_val = curr_timestamp.hour + (curr_timestamp.minute / 60) + (curr_timestamp.second / (60 * 60));

        // Update the total floors climbed according to the magnitude and the direction
        if (label == "up") {
          tot_amt += 1;
        } else if (label == "down") {
          tot_amt -= 1;
        }

        // Add the point to the chart
        newDailyData.add(IndividualPoint(x: hour_val, y: tot_amt.toDouble()));

      }

    } else if (mode == "Heart Rate") {

      double hr = 0.0; // Stores current heart rate

      // The current timestamp must be tracked in order to calculate the x value for each point
      DateTime curr_timestamp;

      // A double representing the exact hour you are in, hour 3.5 is 3:30
      double hour_val = 0.0;

      // The database is queried for heart rate sensor data which happened on the given date
      List<List<dynamic>> results = await db.connection.query(
          "SELECT timestamp, hr FROM data WHERE username='$username' AND timestamp>'$dateSelected' AND timestamp<'$nextDate' ORDER BY timestamp");

      for (int i = 0; i < results.length; i++) {

        curr_timestamp = results[i][0]; // Get the timestamp for the entry
        hr = double.parse(results[i][1].toString()); // Get the heart rate reading

        // Calculate the hour_val using constants derived from how many minutes and seconds are in an hour
        hour_val = curr_timestamp.hour + (curr_timestamp.minute / 60) + (curr_timestamp.second / (60 * 60));

        // Add the point to the chart
        newDailyData.add(IndividualPoint(x: hour_val, y: hr));

      }

    }

    // We update the data in the line chart
    setState(() {
      dailyData = newDailyData;
    });
  }

  // This function is used to do some error checking on the line chart
  Widget buildChart() {

    if (dailyData.isEmpty) {

      // If the data list is empty, there is no data at the date and the chart shouldn't be shown
      return SizedBox(
        height: 200,
        width: MediaQuery.of(context).size.width * 0.9, // MediaQuery is used for sizing relative to the page
        child: const Center(
          child: Text("No data for selected date."),
        )
      );

    } else {

      // If the data list has data, show the chart
      return SizedBox(
        height: 200,
        width: MediaQuery.of(context).size.width * 0.9, // MediaQuery is used for sizing relative to the page
        child: DailyLineChart(data: dailyData, min: findMin(), max: findMax()),
      );
    }
  }

  // This function finds the minimum of the data in the chart
  double findMin() {

    double min = dailyData[0].y;

    for (int i = 1; i < dailyData.length; i++) {
      if (dailyData[i].y < min) {
        min = dailyData[i].y;
      }
    }

    return min;

  }

  // This function finds the maximum of the data in the chart
  double findMax() {

    double max = dailyData[0].y;

    for (int i = 1; i < dailyData.length; i++) {
      if (dailyData[i].y > max) {
        max = dailyData[i].y;
      }
    }

    return max;

  }

  // This function calls setState to update and rebuild the page whenever
  // the dropdown menu choosing the data type is changed
  void updateMode(String? selectedValue) {

    // If the user somehow inputs a value which isn't a string, the type
    // won't be updated to prevent errors in updateData
    if (selectedValue is String) {
      setState(() {
        mode = selectedValue;
      });
      updateData();
    }
  }

  @override
  Widget build(BuildContext context) {

    // First we initialize the data
    initializeDate();

    // The style class is used throughout to maintain consistent style across
    // the entire app and to allow easy color theming from within the app
    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        title: const Text("Daily Line Chart"), // Title for the page
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // The DropdownButton class allows us to let a user pick a data type
            // without being able to freely enter anything into the box
            // This helps a lot with error catching, as the user is restricted
            // from putting in unexpected values
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
                  // This pair of buttons activates the code which changes the date
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
