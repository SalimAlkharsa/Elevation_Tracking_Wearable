import 'individual_bar.dart';

class WeeklyBarData {
  final double sun;
  final double mon;
  final double tue;
  final double wed;
  final double thu;
  final double fri;
  final double sat;

  WeeklyBarData({
    required this.sun,
    required this.mon,
    required this.tue,
    required this.wed,
    required this.thu,
    required this.fri,
    required this.sat,
  });

  List<IndividualBar> data = [];

  void initializeData() {
    data = [
      IndividualBar(x: 0, y: sun),
      IndividualBar(x: 1, y: mon),
      IndividualBar(x: 2, y: tue),
      IndividualBar(x: 3, y: wed),
      IndividualBar(x: 4, y: thu),
      IndividualBar(x: 5, y: fri),
      IndividualBar(x: 6, y: sat),
    ];
  }
}