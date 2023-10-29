import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

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
      appBar: AppBar(
        title: const Text("MAIN PAGE"),
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
                          child: const Text("Steps"),
                        ),
                        Stack(
                            alignment: Alignment.center,
                            children: [
                              const Icon(Icons.directions_run),
                              CircularProgressIndicator(
                                value: 1250/2000,
                                color: Colors.green[300],
                                strokeWidth: 4.0,
                              ),
                            ]
                        ),
                        Transform.scale(
                            scale: 0.4,
                            child: Column(
                                children: [
                                  Container(
                                    decoration: const BoxDecoration(
                                      border: Border(
                                        bottom: BorderSide(color: Colors.black),
                                      ),
                                    ),
                                    child: const Text("1250"),
                                  ),
                                  const Text("2000"),
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
                          child: const Text("Floors"),
                        ),
                        Stack(
                          alignment: Alignment.center,
                          children: [
                            const Icon(Icons.stairs_outlined),
                            CircularProgressIndicator(
                              value: 6/20,
                              color: Colors.blue[300],
                              strokeWidth: 4.0,
                            ),
                          ]
                        ),
                        Transform.scale(
                          scale: 0.4,
                          child: Column(
                            children: [
                              Container(
                                decoration: const BoxDecoration(
                                  border: Border(
                                    bottom: BorderSide(color: Colors.black),
                                  ),
                                ),
                                child: const Text("6"),
                              ),
                              const Text("20"),
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
              child: const Text("Average heart rate: 189"),
            ),
          ],
        ),
      ),
      // The bottom navigation bar allows for easy access to the three main pages of the application
      bottomNavigationBar: BottomAppBar(
        // This padding makes the icons look cleaner and increase readability for the user
        padding: const EdgeInsets.all(5.0),

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
              child: const Icon(Icons.settings, size: 50),
            ),
            TextButton(
              onPressed: () {},
              child: Icon(Icons.house, size: 50, color: Colors.blueGrey[800]),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics');
              },
              child: const Icon(Icons.bar_chart, size: 50),
            ),
          ],
        ),
      ),
    );
  }
}
