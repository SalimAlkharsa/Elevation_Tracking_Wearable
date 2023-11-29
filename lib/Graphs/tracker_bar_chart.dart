// IMPORTS

import 'package:application/Graphs/individual_bar.dart';
import 'package:application/Graphs/tracker_bar_data.dart';
import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:application/style.dart' as style;

// DEFINITION

// This class defines a variable size bar chart which is intended for use in
// the live floor tracking page in the application
class TrackerBarChart extends StatelessWidget {
  const TrackerBarChart({
    super.key,
    required this.data,
    required this.min,
    required this.max,
  });

  final List<IndividualBar> data; // IndividualBar data passed in to create the bar chart
  final double min; // The minimum value for the chart to draw
  final double max; // The maximum value for the chart to draw

  @override
  Widget build(BuildContext context) {

    // TrackerBarData is initialized using the passed in values for efficient mapping
    TrackerBarData trackerBarData = TrackerBarData();
    trackerBarData.setData(data);

    // fl_chart's BarChart widget
    return BarChart(
      BarChartData(
        minY: min - 5, // Minimum Y value to draw, 5 is subtracted for aesthetics
        maxY: max + 5, // Maximum Y value to draw, 5 is added for aesthetics

        // This allows us to add a solid line at 0 so the user can easily tell
        // when someone has climbed down into the basement of a building (negative floors)
        extraLinesData: ExtraLinesData(
          horizontalLines: [
            HorizontalLine(
              y: 0,
            )
          ]
        ),

        gridData: FlGridData(show: false), // Don't show the grid
        borderData: FlBorderData(show: false), // Don't show the border

        // This controls the data which is shown when the bars on the graph are touched
        barTouchData: BarTouchData(
          touchTooltipData: BarTouchTooltipData(
            tooltipBgColor: style.tooltipColor,
          ),
        ),

        // This controls what data is shown on the axes of the graph
        // For the tracker graph, all data is shown in widgets outside
        // the graph, so the axis titles are unnecessary
        titlesData: FlTitlesData(show: false),

        // This controls the actual bars that are drawn on the graph
        // We use the map function to map the list of IndividualBar data types
        // to a list of BarChartGroupData containing BarChartRodData, which are
        // fl_chart's way of representing x and y values for bars on the graph
        barGroups: trackerBarData.data.map((data) => BarChartGroupData(
              x: data.x,
              barRods: [
                BarChartRodData(
                  toY: data.y,
                  color: style.mainColor,

                  // MediaQuery is used to get the size of the page currently being used
                  // This allows us to size our bars relative to the size of the page
                  width: MediaQuery.of(context).size.width * (1 / (trackerBarData.data.length + 0.25)),

                  // With their default radius, the bars look too rounded
                  // We specify a small radius to give them their signature rectangular shape
                  borderRadius: BorderRadius.circular(1),

                  // This controls the size and color of the background bars
                  // which are drawn behind the bars which have actual data
                  backDrawRodData: BackgroundBarChartRodData(
                    show: true,
                    fromY: min - 5,
                    toY: max + 5,
                    color: style.backgroundAccent,
                  )
                )
              ],
            )
        ).toList(),
      ),
    );
  }
}