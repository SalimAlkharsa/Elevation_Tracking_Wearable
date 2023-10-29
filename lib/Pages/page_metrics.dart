import 'package:application/Graphs/weekly_bar_chart.dart';
import 'package:flutter/material.dart';

class MetricsPage extends StatefulWidget {
  const MetricsPage({super.key});

  @override
  State<MetricsPage> createState() => _MetricsPageState();
}

class _MetricsPageState extends State<MetricsPage> {

  List<double> dailyAvgHR = [
    189,
    201,
    197,
    172,
    199,
    200,
    195
  ];
  DateTime dateNow = DateTime.now();

  @override
  Widget build(BuildContext context) {
    DateTime date1 = dateNow;
    DateTime date2 = date1.add(const Duration(days: 5));
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text("METRICS PAGE"),
      ),
      body: Center(
        child: Column(
          children: [
            Text("$date1"),
            Text("$date2"),
            SizedBox(
              height: 200,
              child: WeeklyBarChart(data: dailyAvgHR),
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
          // Pages which are not active use pushReplacementNamed to push the new page onto the navigator stack
          // The internal names for each page are defined by the developer and can be found in main.dart
          children: [
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/settings');
              },
              child: const Icon(Icons.settings, size: 50),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/');
              },
              child: const Icon(Icons.house, size: 50),
            ),
            TextButton(
              onPressed: () {},
              child: Icon(Icons.bar_chart, size: 50, color: Colors.blueGrey[800]),
            ),
          ],
        ),
      ),// This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
