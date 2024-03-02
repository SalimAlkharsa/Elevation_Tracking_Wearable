import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class DeviceRegisterPage extends StatefulWidget {
  const DeviceRegisterPage({super.key});

  @override
  State<DeviceRegisterPage> createState() => _DeviceRegisterPageState();
}

class _DeviceRegisterPageState extends State<DeviceRegisterPage> {
  @override

  String username = db.user;

  Widget build(BuildContext context) {
    print("Reg Username: $username");
    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text("Stats"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: [
            FloatingActionButton.extended(
              heroTag: "Weekly",
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics/weekly');
              },
              label: Text("Weekly Report", style: style.buttonTextStyle),
              backgroundColor: style.mainColor,
              foregroundColor: style.backgroundColor,
            ),
            FloatingActionButton.extended(
              heroTag: "Daily",
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics/daily');
              },
              label: Text("Daily Report", style: style.buttonTextStyle),
              backgroundColor: style.mainColor,
              foregroundColor: style.backgroundColor,
            ),
            FloatingActionButton.extended(
              heroTag: "Compare",
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics/compare');
              },
              label: Text("Compare Values", style: style.buttonTextStyle),
              backgroundColor: style.mainColor,
              foregroundColor: style.backgroundColor,
            ),
            FloatingActionButton.extended(
              heroTag: "Tracker",
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/metrics/tracker');
              },
              label: Text("Floor Tracker", style: style.buttonTextStyle),
              backgroundColor: style.mainColor,
              foregroundColor: style.backgroundColor,
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
              onPressed: () {},
              child: Icon(Icons.bar_chart, size: 50, color: style.selectedColor),
            ),
          ],
        ),
      ),// This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
