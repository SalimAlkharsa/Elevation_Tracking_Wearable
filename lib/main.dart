import 'package:application/Pages/page_compare.dart';
import 'package:application/Pages/page_daily.dart';
import 'package:application/Pages/page_login.dart';
import 'package:application/Pages/page_weekly.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import 'Pages/page_main.dart';
import 'Pages/page_metrics.dart';
import 'Pages/page_settings.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

import 'Pages/page_tracker.dart';

void main() {
  db.initialize();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Frontend',
      routes: {
        '/login' : (BuildContext context) => const LoginPage(),
        '/settings' : (BuildContext context) => const SettingsPage(),
        '/metrics' : (BuildContext context) => const MetricsPage(),
        '/metrics/weekly' : (BuildContext context) => const WeeklyPage(),
        '/metrics/daily' : (BuildContext context) => const DailyPage(),
        '/metrics/compare' : (BuildContext context) => const ComparePage(),
        '/metrics/tracker' : (BuildContext context) => const TrackerPage(),
        '/' : (BuildContext context) => const MainPage(),
      },
      theme: ThemeData(
        appBarTheme: AppBarTheme(
          color: style.mainColor,
        ),
        bottomAppBarTheme: BottomAppBarTheme(
          color: style.backgroundAccent,
        ),
        textTheme: GoogleFonts.quicksandTextTheme()
      ),
    );
  }
}