// IMPORTS

import 'individual_bar.dart';

// DEFINITION

// A basic class which converts two passed in doubles to a pair of IndividualBars
class TwoBarData {
  final double left;
  final double right;

  TwoBarData({
    required this.left,
    required this.right,
  });

  List<IndividualBar> data = [];

  // Updates the private member data with the passed in values
  void initializeData() {
    data = [
      IndividualBar(x: 0, y: left),
      IndividualBar(x: 1, y: right),
    ];
  }
}