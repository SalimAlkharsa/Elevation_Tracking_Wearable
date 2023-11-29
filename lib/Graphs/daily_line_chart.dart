// IMPORTS

import 'package:application/Graphs/daily_line_data.dart';
import 'package:application/Graphs/individual_point.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;

// DEFINITION

// This class defines a line chart which plots data for an entire day
class DailyLineChart extends StatelessWidget {
  const DailyLineChart({
    super.key,
    required this.data,
    required this.min,
    required this.max,
  });

  final List<IndividualPoint> data; // IndividualPoint data passed in to create the line chart
  final double min; // The minimum value for the chart to draw
  final double max; // The maximum value for the chart to draw

  @override
  Widget build(BuildContext context) {

    // DailyLineData is initialized using the passed in values for efficient mapping
    DailyLineData dailyLineData = DailyLineData(data: data);

    // fl_chart's LineChart widget
    return LineChart(
      LineChartData(
        minY: min, // Minimum Y value to draw
        maxY: max, // Maximum Y value to draw
        gridData: FlGridData(show: false), // Don't show the grid
        borderData: FlBorderData(show: false), // Don't show the border

        // This controls the data which is shown when the points on the graph are touched
        lineTouchData: LineTouchData(
          touchTooltipData: LineTouchTooltipData(
            tooltipBgColor: style.tooltipColor,
          ),
        ),

        // This controls what data is shown on the axes of the graph
        // For the line graph, we are only interested in the bottom axis
        titlesData: FlTitlesData(
            show: true,
            topTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            rightTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            leftTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            bottomTitles: AxisTitles(sideTitles: SideTitles(showTitles: true,))
        ),

        // This controls the actual data points that are drawn on the graph
        lineBarsData: [
          LineChartBarData(
            // We use the map function to map the list of IndividualPoint data types
            // to a list of FlSpot data types, which are fl_chart's way of drawing
            // points on a line chart
            spots: dailyLineData.data.map((data) => FlSpot(data.x, data.y)).toList(),
            isCurved: false, // Personal design choice, thought it looked more accurate to what we are representing
            dotData: FlDotData(show: false), // Don't show individual points when they are on the magnitude of hundreds
            color: style.mainColor,
          )
        ]
      ),
    );
  }
}