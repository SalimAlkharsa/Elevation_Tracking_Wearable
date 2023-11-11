import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;

class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
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
              scale: 3.2,
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Padding(
                    padding: const EdgeInsets.all(5.0),
                    child: Column(
                      children: [
                        Transform.scale(
                          scale: 0.5,
                          child: Text("Steps", style: style.textStyle),
                        ),
                        Stack(
                            alignment: Alignment.center,
                            children: [
                              Icon(Icons.directions_run, color: style.iconColor),
                              CircularProgressIndicator(
                                value: 1250/2000,
                                color: style.mainColor,
                                strokeWidth: 4.0,
                              ),
                            ]
                        ),
                        Transform.scale(
                            scale: 0.4,
                            child: Column(
                                children: [
                                  Container(
                                    decoration: BoxDecoration(
                                      border: Border(
                                        bottom: BorderSide(color: style.iconColor),
                                      ),
                                    ),
                                    child: Text("1250", style: style.textStyle),
                                  ),
                                  Text("2000", style: style.textStyle),
                                ]
                            )
                        ),
                      ]
                    )
                  ),
                  Padding(
                    padding: const EdgeInsets.all(5.0),
                    child: Column(
                      children: [
                        Transform.scale(
                          scale: 0.5,
                          child: Text("Floors", style: style.textStyle),
                        ),
                        Stack(
                          alignment: Alignment.center,
                          children: [
                            Icon(Icons.stairs_outlined, color: style.iconColor),
                            CircularProgressIndicator(
                              value: 21/20,
                              color: style.mainColor,
                              strokeWidth: 4.0,
                            ),
                          ]
                        ),
                        Transform.scale(
                          scale: 0.4,
                          child: Column(
                            children: [
                              Container(
                                decoration: BoxDecoration(
                                  border: Border(
                                    bottom: BorderSide(color: style.iconColor),
                                  ),
                                ),
                                child: Text("6", style: style.textStyle),
                              ),
                              Text("20", style: style.textStyle),
                            ]
                          )
                        ),
                      ]
                    )
                  ),
                ],
              ),
            ),
            Transform.scale(
              scale: 1.7,
              child: Text("Average heart rate: 189", style: style.textStyle),
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
}
