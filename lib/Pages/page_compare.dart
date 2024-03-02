// IMPORTS

import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;
import '../Graphs/two_bar_chart.dart';

// DEFINITION

// This class defines the compare data page, which houses a two bar chart where
// both the date for each bar and the data type to compare may be chosen
class ComparePage extends StatefulWidget {
  const ComparePage({super.key});

  @override
  State<ComparePage> createState() => _ComparePageState();
}

class _ComparePageState extends State<ComparePage> {

  List<double> compare = []; // The pair of values to be compared
  DateTime dateLeft = DateTime.now(); // Date for the left value
  DateTime dateRight = DateTime.now(); // Date for the right value
  DateFormat dateFormat = DateFormat.MMMEd(); // Date formatter for usability
  String leftDateStr = ""; // A string to contain the formatted left date
  String rightDateStr = ""; // A string to contain the formatted right date
  String type = ""; // A string to contain the type of data being compared
  bool isInitialized = false; // Prevents the page from continuously initializing
  String username = db.user;

  // This function initializes the data members to their required values
  void initializeDate() {

    // Checks if the data has already been initialized
    if (!isInitialized) {

      setState(() {

        // The left and right date should start at the current date
        dateLeft = DateTime.now();
        dateRight = DateTime.now();
        leftDateStr = dateFormat.format(dateLeft);
        rightDateStr = dateFormat.format(dateRight);

        // The type begins by tracking average heart rate for each day
        type = "Average Heart Rate";

        // The data is then updated with the values for the current date
        updateData();

        // This is to keep the page from continuously initializing
        isInitialized = true;
      });
    }
  }

  // This function calls setState to update and rebuild the page whenever
  // the dropdown menu choosing the data type is changed
  void updateType(String? selectedValue) {

    // If the user somehow inputs a value which isn't a string, the type
    // won't be updated to prevent errors in updateData
    if (selectedValue is String) {
      setState(() {
        type = selectedValue;
      });
      updateData();
    }
  }


  Future<void> updateData() async {

    // Math cannot be done within strings so the edge of both date ranges must be initialized here
    DateTime nextDateRight = dateRight.add(const Duration(days: 1));
    DateTime nextDateLeft = dateLeft.add(const Duration(days: 1));

    // Creating a new list and using setState at the end of the function makes updating
    // the data look more aesthetically pleasing, as both values are updated at once
    List<double> newCompare = [];

    if (type == "Average Heart Rate") {

      double total_hr = 0.0; // Sum of heart rates used for the average

      // The database is queried for all heart rate data which happened on the left date
      List<List<dynamic>> results = await db.connection.query("SELECT hr FROM sensors WHERE username='$username' AND timestamp>'$dateLeft' AND timestamp<'$nextDateLeft'");

      // We calculate the average heart rate which occurred on the left date
      // and add it to the new compare list
      for (int i = 0; i < results.length; i++) {
        total_hr += results[i][0];
      }
      newCompare.add(total_hr / results.length);

      // The heart rate sum is reset before the right value is calculated
      total_hr = 0;

      // The database is queried for all heart rate data which happened on the right date
      results = await db.connection.query("SELECT hr FROM sensors WHERE username='$username' AND timestamp>'$dateRight' AND timestamp<'$nextDateRight'");

      // We calculate the average heart rate which occurred on the left date
      // and add it to the new compare list
      for (int i = 0; i < results.length; i++) {
        total_hr += results[i][0];
      }
      newCompare.add(total_hr / results.length);

    } else if (type == "Floors Climbed") {

      double floors_climbed = 0.0; // Sum of floors climbed on the given date
      int curr_amt = 0; // Stores the magnitude of the given climb
      String curr_direction = ""; // Stores the direction of the given climb

      // The database is queried for all climb data which happened on the left date
      List<List<dynamic>> results = await db.connection.query("SELECT amt, direction FROM climbs WHERE username='$username' AND timestamp>'$dateLeft' AND timestamp<'$nextDateLeft'");

      for (int i = 0; i < results.length; i++) {

        curr_amt = results[i][0]; // Get the magnitude of the climb for the entry in the database
        curr_direction = results[i][1]; // Get the direction of the climb for the entry in the database

        // Update the total floors climbed according to the magnitude and the direction
        if (curr_direction == "up") {
          floors_climbed += curr_amt;
        } else {
          floors_climbed -= curr_amt;
        }
      }

      // Add the left value to the new compare list
      newCompare.add(floors_climbed);

      // The floors climbed sum is reset before the right value is calculated
      floors_climbed = 0;

      // The database is queried for all climb data which happened on the right date
      results = await db.connection.query("SELECT amt, direction FROM climbs WHERE username='$username' AND timestamp>'$dateRight' AND timestamp<'$nextDateRight'");

      for (int i = 0; i < results.length; i++) {
        curr_amt = results[i][0]; // Get the magnitude of the climb for the entry in the database
        curr_direction = results[i][1]; // Get the direction of the climb for the entry in the database

        // Update the total floors climbed according to the magnitude and the direction
        if (curr_direction == "up") {
          floors_climbed += curr_amt;
        } else {
          floors_climbed -= curr_amt;
        }
      }

      // Add the right value to the new compare list
      newCompare.add(floors_climbed);

    }

    // We update the data in the two bar chart
    setState(() {
      compare = newCompare;
    });
  }

  double findMin() {
    double min = compare[0] - 5;
    if (compare[1] < compare[0]) {
      min = compare[1] - 5;
    }

    return min;
  }

  double findMax() {
    double max = compare[0] + 5;
    if (compare[1] > compare[0]) {
      max = compare[1] + 5;
    }

    return max;
  }

  // This function is used to do some error checking on the two bar chart
  Widget buildChart() {

    // This list contains the indexes of the compare list which are null
    List<int> nulls = [];

    // Populate the nulls list, this happens when there are no entries
    // for an average heart rate, resulting in a divide by zero
    for (int i = 0; i < compare.length; i++) {
      if (compare[i].isNaN) {
        nulls.add(i);
      }
    }

    if (compare.isEmpty) {

      // If there is nothing in the compare list, the chart is loading
      return Center(child: Text("Loading chart...", style: style.textStyle));

    } else if (nulls.isEmpty) {

      // If there are no nulls, then the chart can be displayed
      return SizedBox(
        height: 200,
        width: MediaQuery.of(context).size.width, // MediaQuery is used for sizing relative to the page
        child: TwoBarChart(data: compare, min: findMin(), max: findMax()),
      );

    } else if (nulls.length == 1) {

      // If there is a null, we must determine which date lacks the necessary data
      if (nulls[0] == 0) {
        return SizedBox(
            height: 200,
            width: MediaQuery.of(context).size.width, // MediaQuery is used for sizing relative to the page
            child: const Center(
              child: Text("No data for the left date."),
            )
        );
      } else {
        return SizedBox(
            height: 200,
            width: MediaQuery.of(context).size.width, // MediaQuery is used for sizing relative to the page
            child: const Center(
              child: Text("No data for the right date."),
            )
        );
      }

    } else {

      // If we reach here, nulls is full, and both dates are invalid
      return SizedBox(
          height: 200,
          width: MediaQuery.of(context).size.width, // MediaQuery is used for sizing relative to the page
          child: const Center(
            child: Text("No data for either date."),
          )
      );
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
        title: const Text("Compare Bar Chart"), // Title for the page
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
                  // The DropdownButton class allows us to let a user pick a data type
                  // without being able to freely enter anything into the box
                  // This helps a lot with error catching, as the user is restricted
                  // from putting in unexpected values
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
                    // Each text button allows the user to pick a new date from the
                    // built in date picker, which helps with error catching as
                    // the user is restricted from putting in unexpected values
                    children: [
                      TextButton(
                        onPressed: () async {
                          DateTime? newDate = await pickDate(dateLeft);

                          // Don't update the date if none was picked
                          if (newDate == null) return;

                          setState(() {
                            dateLeft = newDate;
                            leftDateStr = dateFormat.format(dateLeft);
                          });

                          // Every time a date is updated, the data must be updated for the chart as well
                          updateData();
                        },
                        child: Text(leftDateStr, style: style.textStyle),
                      ),
                      TextButton(
                        onPressed: () async {
                          DateTime? newDate = await pickDate(dateRight);

                          // Don't update the date if none was picked
                          if (newDate == null) return;

                          setState(() {
                            dateRight = newDate;
                            rightDateStr = dateFormat.format(dateRight);
                          });

                          // Every time a date is updated, the data must be updated for the chart as well
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

  // This function describes the functionality of the date picker
  Future<DateTime?> pickDate(DateTime date) {

    // The new date is picked from the date picker
    Future<DateTime?> newDate = showDatePicker(

      context: context,

      // The date is initially set to the last date picked for usability purposes
      initialDate: date,

      // Data should never be picked from before the year 2000 or after the year 2100
      // Should this app outlive the year 2100, this constant would need to be changed
      firstDate: DateTime(2000),
      lastDate: DateTime(2100),

      builder: (context, child) {

        // This widget contains the theme data for the date picker
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: ColorScheme.light(
              primary: style.mainColor, // Header background color
              onPrimary: Colors.white, // Body text color
            ),
            textButtonTheme: TextButtonThemeData(
              style: TextButton.styleFrom(
                foregroundColor: style.mainColor, // Button text color
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
