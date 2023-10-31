import 'package:application/Graphs/two_bar_data.dart';
import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:application/style.dart' as style;

class TwoBarChart extends StatelessWidget {
  const TwoBarChart({
    super.key,
    required this.data,
  });

  final List data;

  @override
  Widget build(BuildContext context) {
    TwoBarData twoBarData = TwoBarData(
        left: data[0],
        right: data[1],
    );
    twoBarData.initializeData();

    return BarChart(
      BarChartData(
        minY: 0,
        maxY: 250,
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
            bottomTitles: AxisTitles(sideTitles: SideTitles(showTitles: false,)),
        ),
        barGroups: twoBarData.data.map(
                (data) => BarChartGroupData(
              x: data.x,
              barRods: [BarChartRodData(
                  toY: data.y,
                  color: style.mainColor,
                  width: MediaQuery.of(context).size.width * 0.45,
                  borderRadius: BorderRadius.circular(1),
                  backDrawRodData: BackgroundBarChartRodData(
                    show: true,
                    toY: 250,
                    color: style.backgroundAccent,
                  )
              )],
            )
        ).toList(),
      ),
    );
  }
}

