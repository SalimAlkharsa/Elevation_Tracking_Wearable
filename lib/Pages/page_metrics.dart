import 'package:application/Graphs/weekly_bar_chart.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;

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
  DateTime dateSelected = DateTime.now();
  DateTime dateNextSaturday = DateTime.now();
  DateFormat dateFormat = DateFormat.MMMEd();
  String nextSaturday = "";
  String thisSunday = "";
  bool isInitialized = false;
  int dateCorrection = 0;

  void initializeDate() {
    if (!isInitialized) {
      if (dateSelected.weekday == 7) {
        dateNextSaturday = dateSelected.add(const Duration(days: 6));
      } else if (dateSelected.weekday == 6) {
        dateNextSaturday = dateSelected;
      } else {
        dateNextSaturday =
            dateSelected.add(Duration(days: 6 - dateSelected.weekday));
      }
      nextSaturday = dateFormat.format(dateNextSaturday);
      thisSunday = dateFormat.format(dateNextSaturday.subtract(const Duration(days: 6)));
      isInitialized = true;
    }
  }

  void nextWeek (){
    setState(() {
      dateNextSaturday = dateNextSaturday.add(const Duration(days: 7));

      nextSaturday = dateFormat.format(dateNextSaturday);
      thisSunday = dateFormat.format(dateNextSaturday.subtract(const Duration(days: 6)));

      dailyAvgHR = [
        174,
        178,
        185,
        212,
        174,
        173,
        190
      ];
    });
  }

  void lastWeek () {
    setState(() {
      dateNextSaturday = dateNextSaturday.subtract(const Duration(days: 7));

      nextSaturday = dateFormat.format(dateNextSaturday);
      thisSunday = dateFormat.format(dateNextSaturday.subtract(const Duration(days: 6)));

      dailyAvgHR = [
        201,
        209,
        204,
        165,
        167,
        180,
        174
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
        title: const Text("Stats"),
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
                  onPressed: lastWeek,
                  icon: Icon(Icons.keyboard_arrow_left, color: style.iconColor),
                  splashRadius: 15.0,
                ),
                Text("$thisSunday - $nextSaturday", style: style.textStyle),
                IconButton(
                  onPressed: nextWeek,
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
              child: WeeklyBarChart(data: dailyAvgHR),
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
              onPressed: () {},
              child: Icon(Icons.bar_chart, size: 50, color: style.selectedColor),
            ),
          ],
        ),
      ),// This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
