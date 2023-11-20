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
          // Pages which are not active use pushRaplacementNamed to push the new page onto the navigator stack
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

  void testFunc () async {
    var rng = Random();
    int user_id = 0;
    int amt = 0;
    String direction = "";

    for(int i = 0; i < 20; i++) {
      user_id = rng.nextInt(7);
      amt = rng.nextInt(10);
      if (rng.nextInt(5) == 0) {
        direction = "down";
      } else {
        direction = "up";
      }

      await db.connection.query("INSERT INTO climbs (user_id, amt, direction) VALUES ($user_id, $amt, '$direction')");
    }
  }
}
