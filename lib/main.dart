import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import 'Pages/page_main.dart';
import 'Pages/page_metrics.dart';
import 'Pages/page_settings.dart';
import 'package:application/style.dart' as style;

void main() {
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
        '/' : (BuildContext context) => const MainPage(),
        '/settings' : (BuildContext context) => const SettingsPage(),
        '/metrics' : (BuildContext context) => const MetricsPage()
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