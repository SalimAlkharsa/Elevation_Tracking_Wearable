import 'package:application/Graphs/individual_bar.dart';
import 'package:application/Graphs/tracker_bar_data.dart';
import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class TrackerBarChart extends StatelessWidget {
  const TrackerBarChart({
    super.key,
    required this.data,
  });

  final List<IndividualBar> data;

  @override
  Widget build(BuildContext context) {
    TrackerBarData trackerBarData = TrackerBarData();

    trackerBarData.setData(data);

    return BarChart(
      BarChartData(
        minY: -2,
        maxY: 10,
        gridData: FlGridData(show: false),
        borderData: FlBorderData(show: false),
        barTouchData: BarTouchData(
          touchTooltipData: BarTouchTooltipData(
            tooltipBgColor: style.tooltipColor,
          ),
        ),
        titlesData: FlTitlesData(
            show: true,
            topTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            rightTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            leftTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            bottomTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
        ),
        barGroups: trackerBarData.data.map(
                (data) => BarChartGroupData(
              x: data.x,
              barRods: [BarChartRodData(
                  toY: data.y,
                  color: style.mainColor,
                  width: MediaQuery.of(context).size.width * (1 / (trackerBarData.data.length + 0.25)),
                  borderRadius: BorderRadius.circular(1),
                  backDrawRodData: BackgroundBarChartRodData(
                    show: true,
                    toY: 10,
                    color: style.backgroundAccent,
                  )
              )],
            )
        ).toList(),
      ),
    );
  }
}