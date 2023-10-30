import 'package:application/Graphs/weekly_bar_data.dart';
import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:application/style.dart' as style;

class WeeklyBarChart extends StatelessWidget {
  const WeeklyBarChart({
    super.key,
    required this.data,
  });

  final List data;

  @override
  Widget build(BuildContext context) {
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

    return BarChart(
      BarChartData(
        minY: 0,
        maxY: 250,
        gridData: FlGridData(show: false),
        borderData: FlBorderData(show: false),
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
        barGroups: weeklyBarData.data.map(
          (data) => BarChartGroupData(
            x: data.x,
            barRods: [BarChartRodData(
              toY: data.y,
              color: style.mainColor,
              width: 40,
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

Widget getBottomTitles (double value, TitleMeta meta) {
  const style = TextStyle(
    fontSize: 12,
  );

  Widget text;
  switch (value.toInt()) {
    case 0:
      text = const Text("Su", style: style);
      break;
    case 1:
      text = const Text("Mo", style: style);
      break;
    case 2:
      text = const Text("Tu", style: style);
      break;
    case 3:
      text = const Text("We", style: style);
      break;
    case 4:
      text = const Text("Th", style: style);
      break;
    case 5:
      text = const Text("Fr", style: style);
      break;
    case 6:
      text = const Text("Sa", style: style);
      break;
    default:
      text = const Text("Default", style: style);
      break;
  }
  
  return SideTitleWidget(axisSide: meta.axisSide, child: text);
}

