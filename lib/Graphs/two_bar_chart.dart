// IMPORTS

import 'package:application/Graphs/two_bar_data.dart';
import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:application/style.dart' as style;

// DEFINITION

// This class defines a bar chart with two bars which is intended for use in
// the comparing data page in the application
// Since only two values are compared, only two bars are needed
class TwoBarChart extends StatelessWidget {
  const TwoBarChart({
    super.key,
    required this.data,
    required this.min,
    required this.max,
  });

  final List data; // Data passed in to create the bar chart
  final double min; // The minimum value for the chart to draw
  final double max; // The maximum value for the chart to draw

  @override
  Widget build(BuildContext context) {

    // TwoBarData is initialized using the passed in values for efficient mapping
    TwoBarData twoBarData = TwoBarData(
        left: data[0],
        right: data[1],
    );
    twoBarData.initializeData();

    // fl_chart's BarChart widget
    return BarChart(
      BarChartData(
        minY: min, // Minimum Y value to draw
        maxY: max, // Maximum Y value to draw
        gridData: FlGridData(show: false), // Don't show the grid
        borderData: FlBorderData(show: false), // Don't show the border

        // This controls the data which is shown when the bars on the graph are touched
        barTouchData: BarTouchData(
          touchTooltipData: BarTouchTooltipData(
            tooltipBgColor: style.tooltipColor,
          ),
        ),

        // This controls what data is shown on the axes of the graph
        // For the compare graph the axis titles are unnecessary
        titlesData: FlTitlesData(show: false),

        // This controls the actual bars that are drawn on the graph
        // We use the map function to map the list of IndividualBar data types
        // to a list of BarChartGroupData containing BarChartRodData, which are
        // fl_chart's way of representing x and y values for bars on the graph
        barGroups: twoBarData.data.map((data) => BarChartGroupData(
              x: data.x,
              barRods: [
                BarChartRodData(
                  toY: data.y,
                  color: style.mainColor,

                  // MediaQuery is used to get the size of the page currently being used
                  // This allows us to size our bars relative to the size of the page
                  // The constant is derived from the fact that there are 2 bars
                  width: MediaQuery.of(context).size.width * 0.42,

                  // With their default radius, the bars look too rounded
                  // We specify a small radius to give them their signature rectangular shape
                  borderRadius: BorderRadius.circular(1),

                  // This controls the size and color of the background bars
                  // which are drawn behind the bars which have actual data
                  backDrawRodData: BackgroundBarChartRodData(
                    show: true,
                    toY: max,
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

