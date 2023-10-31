import 'package:application/Graphs/daily_line_chart.dart';
import 'package:application/Graphs/individual_point.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;

class DailyPage extends StatefulWidget {
  const DailyPage({super.key});

  @override
  State<DailyPage> createState() => _DailyPageState();
}

class _DailyPageState extends State<DailyPage> {
  List<IndividualPoint> hourlyAvgHR = [
    IndividualPoint(x: 3, y: 189),
    IndividualPoint(x: 3.1, y: 190),
    IndividualPoint(x: 3.5, y: 199),
    IndividualPoint(x: 3.9, y: 200),
    IndividualPoint(x: 4, y: 201),
    IndividualPoint(x: 4.3, y: 175),
    IndividualPoint(x: 4.4, y: 176),
    IndividualPoint(x: 4.5, y: 182),
    IndividualPoint(x: 4.6, y: 170),
    IndividualPoint(x: 5.1, y: 188),
    IndividualPoint(x: 5.5, y: 189),
    IndividualPoint(x: 5.6, y: 189),
    IndividualPoint(x: 6, y: 187),
  ];

  DateTime dateSelected = DateTime.now(); // Initialized to current date
  DateFormat dateFormat = DateFormat.MMMEd(); // Date formatter for the UI
  String currentDate = ""; // String form of the date for display
  bool isInitialized = false; // Tracks whether date has been initialized

  void initializeDate() {
    if (!isInitialized) {
      dateSelected = DateTime.now();
      currentDate = dateFormat.format(dateSelected);
      isInitialized = true;
    }
  }

  void tomorrow (){
    setState(() {
      dateSelected = dateSelected.add(const Duration(days: 1));

      currentDate = dateFormat.format(dateSelected);

      hourlyAvgHR = [
        IndividualPoint(x: 2, y: 189),
        IndividualPoint(x: 2.1, y: 190),
        IndividualPoint(x: 2.5, y: 199),
        IndividualPoint(x: 2.9, y: 200),
        IndividualPoint(x: 3, y: 201),
        IndividualPoint(x: 3.3, y: 175),
        IndividualPoint(x: 4.4, y: 176),
        IndividualPoint(x: 4.5, y: 182),
        IndividualPoint(x: 4.6, y: 170),
        IndividualPoint(x: 5.1, y: 188),
        IndividualPoint(x: 5.5, y: 189),
        IndividualPoint(x: 6.6, y: 189),
        IndividualPoint(x: 7, y: 187),
      ];
    });
  }

  void yesterday () {
    setState(() {
      dateSelected = dateSelected.subtract(const Duration(days: 1));

      currentDate = dateFormat.format(dateSelected);

      hourlyAvgHR = [
        IndividualPoint(x: 2.5, y: 200),
        IndividualPoint(x: 3.1, y: 192),
        IndividualPoint(x: 3.5, y: 191),
        IndividualPoint(x: 3.8, y: 184),
        IndividualPoint(x: 3.9, y: 177),
        IndividualPoint(x: 4, y: 177),
        IndividualPoint(x: 4.2, y: 177),
        IndividualPoint(x: 4.5, y: 181),
        IndividualPoint(x: 4.9, y: 175),
        IndividualPoint(x: 5.1, y: 198),
        IndividualPoint(x: 6.5, y: 201),
        IndividualPoint(x: 6.6, y: 215),
        IndividualPoint(x: 7.1, y: 201),
      ];
    });
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
            SizedBox(
              height: 200,
              width: MediaQuery.of(context).size.width * 0.9,
              child: DailyLineChart(data: hourlyAvgHR),
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
