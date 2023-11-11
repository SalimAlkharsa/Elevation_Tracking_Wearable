import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:application/style.dart' as style;

import '../Graphs/two_bar_chart.dart';

class ComparePage extends StatefulWidget {
  const ComparePage({super.key});

  @override
  State<ComparePage> createState() => _ComparePageState();
}

class _ComparePageState extends State<ComparePage> {

  List<double> dailyAvgHR = [
    189,
    201,
  ];
  DateTime dateLeft = DateTime.now();
  DateTime dateRight = DateTime.now();
  DateFormat dateFormat = DateFormat.MMMEd();
  String leftDateStr = "";
  String rightDateStr = "";
  String leftType = "Average HR";
  String rightType = "Average HR";
  bool isInitialized = false;

  void initializeDate() {
    if (!isInitialized) {
      dateLeft = DateTime.now();
      dateRight = DateTime.now();
      leftDateStr = dateFormat.format(dateLeft);
      rightDateStr = dateFormat.format(dateRight);
      isInitialized = true;
    }
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
        title: const Text("Compare Bar Chart"),
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
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  Column(
                    children: [
                      TextButton(
                        onPressed: () {},
                        child: Text(leftType, style: style.textStyle),
                      ),
                      TextButton(
                        onPressed: () async {
                          DateTime? newDate = await pickDate(dateLeft);

                          if (newDate == null) return;

                          setState(() {
                            dateLeft = newDate;
                            leftDateStr = dateFormat.format(dateLeft);
                          });
                        },
                        child: Text(leftDateStr, style: style.textStyle),
                      ),
                    ],
                  ),
                  Column(
                    children: [
                      TextButton(
                        onPressed: () {},
                        child: Text(rightType, style: style.textStyle),
                      ),
                      TextButton(
                        onPressed: () async {
                          DateTime? newDate = await pickDate(dateRight);

                          if (newDate == null) return;

                          setState(() {
                            dateRight = newDate;
                            rightDateStr = dateFormat.format(dateRight);
                          });
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
              child: TwoBarChart(data: dailyAvgHR),
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

  Future<DateTime?> pickDate(DateTime date) {
    Future<DateTime?> newDate = showDatePicker(
      context: context,
      initialDate: date,
      firstDate: DateTime(2000),
      lastDate: DateTime(2100),
      builder: (context, child) {
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: ColorScheme.light(
              primary: style.mainColor, // header background color
              onPrimary: Colors.white, // body text color
            ),
            textButtonTheme: TextButtonThemeData(
              style: TextButton.styleFrom(
                foregroundColor: style.mainColor, // button text color
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
