// IMPORTS

import 'package:application/Graphs/weekly_bar_data.dart';
import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:application/style.dart' as style;

// DEFINITION

// This class defines a bar chart with bars for each day of the week
class WeeklyBarChart extends StatelessWidget {
  const WeeklyBarChart({
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

    // WeeklyBarData is initialized using the passed in values for efficient mapping
    WeeklyBarData weeklyBarData = WeeklyBarData(
        sun: data[0],
        mon: data[1],
        tue: data[2],
        wed: data[3],
        thu: data[4],
        fri: data[5],
        sat: data[6]
    );
    weeklyBarData.initializeData();

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
        // For the weekly graph only the bottom titles are necessary
        titlesData: FlTitlesData(
          show: true,
          topTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
          rightTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
          leftTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
          bottomTitles: AxisTitles(sideTitles: SideTitles(
            showTitles: true,
            getTitlesWidget: getBottomTitles,
          ))
        ),

        // This controls the actual bars that are drawn on the graph
        // We use the map function to map the list of IndividualBar data types
        // to a list of BarChartGroupData containing BarChartRodData, which are
        // fl_chart's way of representing x and y values for bars on the graph
        barGroups: weeklyBarData.data.map((data) => BarChartGroupData(
            x: data.x,
            barRods: [
              BarChartRodData(
                toY: data.y,
                color: style.mainColor,

                // MediaQuery is used to get the size of the page currently being used
                // This allows us to size our bars relative to the size of the page
                // The constant is derived from the fact that there are 7 bars
                width: MediaQuery.of(context).size.width * 0.135,

                // With their default radius, the bars look too rounded
                // We specify a small radius to give them their signature rectangular shape
                borderRadius: BorderRadius.circular(1),

                // This controls the size and color of the background bars
                // which are drawn behind the bars which have actual data
                backDrawRodData: BackgroundBarChartRodData(
                  show: true,
                  fromY: min,
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

// This function returns the titles for the bottom axis of the chart
Widget getBottomTitles (double value, TitleMeta meta) {

  // This is a specific text style defined for the titles
  // since they need to be smaller than normal text
  TextStyle titleStyle = TextStyle(
    fontSize: 12,
    color: style.textStyle.color
  );

  Widget text; // Text for the title

  // This switch decides which day of the week abbreviation should
  // be put into the text widget based on the X value used for
  // the given bar
  switch (value.toInt()) {
    case 0:
      text = Text("Su", style: titleStyle);
      break;
    case 1:
      text = Text("Mo", style: titleStyle);
      break;
    case 2:
      text = Text("Tu", style: titleStyle);
      break;
    case 3:
      text = Text("We", style: titleStyle);
      break;
    case 4:
      text = Text("Th", style: titleStyle);
      break;
    case 5:
      text = Text("Fr", style: titleStyle);
      break;
    case 6:
      text = Text("Sa", style: titleStyle);
      break;
    default:
      // For error checking
      text = Text("Default", style: titleStyle);
      break;
  }
  
  return SideTitleWidget(axisSide: meta.axisSide, child: text);
}

