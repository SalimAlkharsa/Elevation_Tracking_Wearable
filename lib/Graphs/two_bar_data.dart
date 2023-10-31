import 'individual_bar.dart';

class TwoBarData {
  final double left;
  final double right;

  TwoBarData({
    required this.left,
    required this.right,
  });

  List<IndividualBar> data = [];

  void initializeData() {
    data = [
      IndividualBar(x: 0, y: left),
      IndividualBar(x: 1, y: right),
    ];
  }
}