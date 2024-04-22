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

  int floorGoal = 0;
  double floorFraction = 0.0;
  String username = db.user;
  int floorTotal = 0;
  double averageHR = 0.0;

  DateTime today = DateTime.now();

  @override
  void initState() {
    super.initState();

    initializeGoals();

    getRealTimeData();
  }

  Widget buildBody() {
    if (db.connection.isClosed) {
      return Center(child: Text("No connection. Please reconnect to the WiFi and restart the app. If this issue persists, contact support.", style: style.textStyle,),);
    } else {
      return Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          verticalDirection: VerticalDirection.up,
          children: <Widget>[
            Transform.scale(
              scale: 2.5,
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
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
                                        child: Text("$floorTotal climbed today", style: style.textStyle),
                                      ),
                                      Text("$floorGoal daily goal", style: style.textStyle),
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
                child: Text("Average heart rate: $averageHR", style: style.textStyle),
              ),
            ),
            Padding (
              padding: const EdgeInsets.all(5.0),
              child: Transform.scale(
                scale: 1.7,
                child: Text("Welcome, $username", style: style.textStyle),
              ),
            ),
          ],
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        title: const Text("Home"),
        backgroundColor: style.mainColor,
      ),
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

    List<List<dynamic>> results = await db.connection.query("SELECT daily_floors FROM users WHERE username='$username'");

    setState(() {
      floorGoal = results[0][0];

      if (floorGoal != 0) {
        floorFraction = floorTotal / floorGoal;
      } else {
        floorFraction = 0.0;
      }

    });

    // db.connection.close();
  }

  Future<void> getRealTimeData() async {
    // await db.connection.open();

    setState(() {

      today = today.subtract(Duration(hours: today.hour, minutes: today.minute, seconds: today.second, milliseconds: today.millisecond));

    });

    List<List<dynamic>> results = await db.connection.query("SELECT label, hr FROM data WHERE username='$username' AND timestamp>'$today'");

    int newFloors = 0;
    double totalHR = 0.0;
    double newHR = 0.0;

    for (int i = 0; i < results.length; i++) {
      if (results[i][0] == "up") {
        newFloors += 1;
      }

      totalHR += results[i][1];
    }

    if (results.isNotEmpty) {
      newHR = (totalHR / results.length);
    } else {
      newHR = 0.0;
    }

    setState(() {

      floorTotal = newFloors;
      averageHR = newHR;

    });

    // db.connection.close();
  }

  void testFunc () {
    populateData();
  }

  void populateData () async {
    var rng = Random();
    DateTime timestamp = DateTime.now();
    String username = "humphrey";
    int hr = 0;
    String label = "";
    int chance = 0;
    for (int d = 0; d < 14; d++) {
      print("Day $d");
      for (int h = 0; h < 24; h++) {
        print("Hour $h");
        for (int m = 0; m < 60; m++) {
          timestamp = timestamp.subtract(const Duration(minutes: 1));
          hr = randHR(hr);
          chance = rng.nextInt(20);
          if (chance == 0 || chance == 1 || chance == 6) {
            label = "down";
          } else if (chance == 2 || chance == 3 || chance == 7) {
            label = "up";
          } else if (chance == 4) {
            label = "elevator_up";
          } else if (chance == 5) {
            label = "elevator_down";
          } else {
            label = "walk";
          }


          await db.connection.query(
              "INSERT INTO data (timestamp, username, hr, label) VALUES ('$timestamp', '$username', $hr, '$label')");
        }
      }
    }

    print("Done!");
  }

  // double testDouble (double curr) {
  //
  //   var rng = Random();
  //   int direction = 1;
  //
  //   if (curr >= 20.0) {
  //     direction = -1;
  //   } else if (curr <= -20.0) {
  //     direction = 1;
  //   } else {
  //     if (rng.nextInt(2) == 0) {
  //       direction = 1;
  //     } else {
  //       direction = -1;
  //     }
  //   }
  //
  //   return curr + (rng.nextDouble() * 2 * direction);
  // }

  int randHR (int curr) {

    var rng = Random();
    int direction = 1;

    if (curr >= 105) {
      direction = -1;
    } else if (curr <= 55) {
      direction = 1;
    } else {
      if (rng.nextInt(2) == 0) {
        direction = 1;
      } else {
        direction = -1;
      }
    }

    return curr + (rng.nextInt(3) * 2 * direction);
  }
}
