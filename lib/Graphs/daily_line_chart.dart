import 'package:application/Graphs/daily_line_data.dart';
import 'package:application/Graphs/individual_point.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;

class DailyLineChart extends StatelessWidget {
  const DailyLineChart({
    super.key,
    required this.data,
  });

  final List<IndividualPoint> data;

  @override
  Widget build(BuildContext context) {
    DailyLineData dailyLineData = DailyLineData(data: data);
    return LineChart(
      LineChartData(
        minY: 170,
        maxY: 250,
        gridData: FlGridData(show: false),
        borderData: FlBorderData(show: false),
        lineTouchData: LineTouchData(
          touchTooltipData: LineTouchTooltipData(
            tooltipBgColor: style.tooltipColor,
          ),
        ),
        titlesData: FlTitlesData(
            show: true,
            topTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            rightTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            leftTitles: AxisTitles(sideTitles: SideTitles(showTitles: false)),
            bottomTitles: AxisTitles(sideTitles: SideTitles(showTitles: true,))
        ),
        lineBarsData: [
          LineChartBarData(
            spots: dailyLineData.data.map((data) => FlSpot(data.x, data.y)).toList(),
            isCurved: false,
            dotData: FlDotData(show: false),
            color: style.mainColor,
          )
        ]
      ),
    );
  }
}