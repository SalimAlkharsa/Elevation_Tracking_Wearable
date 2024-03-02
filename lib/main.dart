import 'package:application/Pages/page_account_register.dart';
import 'package:application/Pages/page_compare.dart';
import 'package:application/Pages/page_daily.dart';
import 'package:application/Pages/page_device_register.dart';
import 'package:application/Pages/page_login.dart';
import 'package:application/Pages/page_startup.dart';
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
        '/' : (BuildContext context) => const StartupPage(),
        '/startup/login' : (BuildContext context) => const LoginPage(),
        '/startup/register' : (BuildContext context) => const AccountRegisterPage(),
        '/settings' : (BuildContext context) => const SettingsPage(),
        '/settings/register' : (BuildContext context) => const DeviceRegisterPage(),
        '/metrics' : (BuildContext context) => const MetricsPage(),
        '/metrics/weekly' : (BuildContext context) => const WeeklyPage(),
        '/metrics/daily' : (BuildContext context) => const DailyPage(),
        '/metrics/compare' : (BuildContext context) => const ComparePage(),
        '/metrics/tracker' : (BuildContext context) => const TrackerPage(),
        '/main' : (BuildContext context) => const MainPage(),
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