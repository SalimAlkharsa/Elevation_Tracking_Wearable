import 'dart:math';

import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {

  int stepGoal = 0;
  int floorGoal = 0;
  double stepFraction = 0.0;
  double floorFraction = 0.0;

  @override
  void initState() {
    super.initState();

    initializeGoals();
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        title: const Text("Home"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          verticalDirection: VerticalDirection.up,
          children: <Widget>[
            Transform.scale(
              scale: 2.5,
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  // Padding(
                  //   padding: const EdgeInsets.all(5.0),
                  //   child: Column(
                  //     children: [
                  //       Transform.scale(
                  //         scale: 0.5,
                  //         child: Text("Steps", style: style.textStyle),
                  //       ),
                  //       Stack(
                  //           alignment: Alignment.center,
                  //           children: [
                  //             Icon(Icons.directions_run, color: style.iconColor),
                  //             CircularProgressIndicator(
                  //               value: stepFraction,
                  //               color: style.mainColor,
                  //               strokeWidth: 4.0,
                  //             ),
                  //           ]
                  //       ),
                  //       Transform.scale(
                  //           scale: 0.4,
                  //           child: Column(
                  //               children: [
                  //                 Container(
                  //                   decoration: BoxDecoration(
                  //                     border: Border(
                  //                       bottom: BorderSide(color: style.iconColor),
                  //                     ),
                  //                   ),
                  //                   child: Text("250", style: style.textStyle),
                  //                 ),
                  //                 Text("$stepGoal", style: style.textStyle),
                  //               ]
                  //           )
                  //       ),
                  //     ]
                  //   )
                  // ),
                  Padding(
                    padding: const EdgeInsets.all(5.0),
                    child: Column(
                      children: [
                        Transform.scale(
                          scale: 0.5,
                          child: Text("Floors Today", style: style.textStyle),
                        ),
                        Stack(
                          alignment: Alignment.center,
                          children: [
                            Icon(Icons.stairs_outlined, color: style.iconColor),
                            CircularProgressIndicator(
                              value: floorFraction,
                              color: style.mainColor,
                              strokeWidth: 4.0,
                            ),
                          ]
                        ),
                        Transform.scale(
                          scale: 0.5,
                          child: Column(
                            children: [
                              Container(
                                decoration: BoxDecoration(
                                  border: Border(
                                    bottom: BorderSide(color: style.iconColor),
                                  ),
                                ),
                                child: Text("8", style: style.textStyle),
                              ),
                              Text("$floorGoal", style: style.textStyle),
                            ]
                          )
                        ),
                      ]
                    )
                  ),
                  // TODO: REMOVE TEST
                  // TextButton(
                  //   onPressed: testFunc,
                  //   child: const Text("TEST"),
                  // )
                ],
              ),
            ),
            Padding (
              padding: const EdgeInsets.all(5.0),
              child: Transform.scale(
                scale: 1.7,
                child: Text("Average heart rate: 189", style: style.textStyle),
              ),
            ),
            Padding (
              padding: const EdgeInsets.all(5.0),
              child: Transform.scale(
                scale: 1.7,
                child: Text("Welcome, Seth", style: style.textStyle),
              ),
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
              onPressed: () {},
              child: Icon(Icons.house, size: 50, color: style.selectedColor),
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

  Future<void> initializeGoals() async {
    // await db.connection.open();

    List<List<dynamic>> results = await db.connection.query("SELECT daily_steps, daily_floors FROM users WHERE user_id=0");

    setState(() {
      stepGoal = results[0][0];
      floorGoal = results[0][1];

      if (stepGoal != 0) {
        stepFraction = 250 / stepGoal;
      } else {
        stepFraction = 0.0;
      }

      if (floorGoal != 0) {
        floorFraction = 8 / floorGoal;
      } else {
        floorFraction = 0.0;
      }

    });

    // db.connection.close();
  }

  void testFunc () {
    populateSensors();
    populateClimbs();
  }

  void populateClimbs () async {
    var rng = Random();
    DateTime timestamp = DateTime.now();
    int user_id = 0;
    int amt = 0;
    String direction = "";
    for (int d = 0; d < 14; d++) {
      print("Day $d");
      for (int h = 0; h < 24; h++) {
        print("Hour $h");
        for (int m = 0; m < 60; m++) {
          user_id = rng.nextInt(7);
          timestamp = timestamp.subtract(const Duration(minutes: 1));
          amt = rng.nextInt(5);
          if (rng.nextInt(5) == 0) {
            direction = "down";
          } else {
            direction = "up";
          }


          await db.connection.query(
              "INSERT INTO climbs (timestamp, user_id, amt, direction) VALUES ('$timestamp', $user_id, $amt, '$direction')");
        }
      }
    }

    print("Done!");
  }

  void populateSensors () async {
    var rng = Random();
    DateTime timestamp = DateTime.now();
    int user_id = 0;
    double a_x = 0.0;
    double a_y = 0.0;
    double a_z = 0.0;
    double r_x = 0.0;
    double r_y = 0.0;
    double r_z = 0.0;
    double temperature = 0.0;
    double pressure = 0.0;
    double hr = 0.0;

    timestamp = timestamp.subtract(const Duration(days: 7));

    for (int d = 0; d < 7; d++) {
      print("Day $d");
      for (int u = 0; u < 5; u++) {
        user_id = rng.nextInt(7);

        for (int i = 0; i < 100; i++) {
          timestamp = timestamp.add(const Duration(seconds: 30));
          a_x = testDouble(a_x);
          a_y = testDouble(a_y);
          a_z = testDouble(a_z);
          r_x = testDouble(r_x);
          r_y = testDouble(r_y);
          r_z = testDouble(r_z);
          temperature = 40 + (rng.nextDouble() * 2);
          pressure = 30 + (rng.nextDouble() * 6);
          hr = testHR(hr);


          await db.connection.query(
              "INSERT INTO sensors (timestamp, user_id, a_x, a_y, a_z, r_x, r_y, r_z, temperature, pressure, hr) VALUES ('$timestamp', $user_id, $a_x, $a_y, $a_z, $r_x, $r_y, $r_z, $temperature, $pressure, $hr)");
        }
      }

      timestamp = timestamp.add(const Duration(days: 1));
      timestamp = timestamp.subtract(const Duration(minutes: 250));
    }

    print("Done!");
  }

  double testDouble (double curr) {

    var rng = Random();
    int direction = 1;

    if (curr >= 20.0) {
      direction = -1;
    } else if (curr <= -20.0) {
      direction = 1;
    } else {
      if (rng.nextInt(2) == 0) {
        direction = 1;
      } else {
        direction = -1;
      }
    }

    return curr + (rng.nextDouble() * 2 * direction);
  }

  double testHR (double curr) {

    var rng = Random();
    int direction = 1;

    if (curr >= 105.0) {
      direction = -1;
    } else if (curr <= 55.0) {
      direction = 1;
    } else {
      if (rng.nextInt(2) == 0) {
        direction = 1;
      } else {
        direction = -1;
      }
    }

    return curr + (rng.nextDouble() * 2 * direction);
  }
}
