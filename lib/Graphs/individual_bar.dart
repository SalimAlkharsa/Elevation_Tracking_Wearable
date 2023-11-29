// DEFINITION

// This is a class that contains the x and y values for a single bar on a bar chart
class IndividualBar {
  final int x; // Integer since bar chart positions can only be integers
  final double y; // Y value for the given bar

  IndividualBar({
    required this.x,
    required this.y,
  });
}