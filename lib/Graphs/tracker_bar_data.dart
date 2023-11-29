// IMPORTS

import 'individual_bar.dart';

// DEFINITION

// A basic class which contains a list of IndividualBars for the tracker chart
class TrackerBarData {
  List<IndividualBar> data = [];

  // Setter for the private data member
  void setData(List<IndividualBar> newData) {
    data = newData;
  }
}