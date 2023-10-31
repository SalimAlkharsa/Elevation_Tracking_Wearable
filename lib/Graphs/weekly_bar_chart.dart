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
        barTouchData: BarTouchData(
          touchTooltipData: BarTouchTooltipData(
            tooltipBgColor: style.tooltipColor,
          )
        ),
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
  TextStyle titleStyle = TextStyle(
    fontSize: 12,
    color: style.textStyle.color
  );

  Widget text;
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
      text = Text("Default", style: titleStyle);
      break;
  }
  
  return SideTitleWidget(axisSide: meta.axisSide, child: text);
}

