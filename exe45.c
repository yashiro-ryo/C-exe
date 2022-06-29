#include <stdio.h>

// 閏年計算関数
int leap(int year)
{
  // 条件分岐
  return (year % 4 == 0 && !(year % 100 == 0 && !(year % 400 == 0)) ? 1 : 0);
}

// 月の日数計算関数
int days(int year, int month)
{
  switch (month)
  {
    // 0の場合はその年の日数を返す
  case 0:
    return 365 + leap(year);
    break;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
    break;
  case 2:
    return 28 + leap(year);
    break;
  default:
    return 0;
    break;
  }
}

// 何曜日かをIntで返す関数
int week(int year, int month, int day)
{
  // 1600年1月1日から昨年までの日数　
  int daysFrom1600ToLastYear = 0;
  // 今年の1月から先月までの日数
  int daysFromJantoLastMonth = 0;
  // 週
  int week = 0;
  for (int i = 1600; i < year; i++)
  {
    // 毎年日数を追加
    daysFrom1600ToLastYear += days(year, 0);
  }
  for (int i = 1; i < month; i++)
  {
    // 各月の日数を追加
    daysFromJantoLastMonth += days(year, month);
  }
  return (week = (daysFrom1600ToLastYear + daysFromJantoLastMonth) % 7);
}

int main()
{
  int year, month, day;
  printf("input year month day\n");
  scanf("%d %d %d", &year, &month, &day);
  switch (week(year, month, day))
  {
  case 0:
    printf("月曜日\n");
    break;
  case 1:
    printf("火曜日\n");
    break;
  case 2:
    printf("水曜日\n");
    break;
  case 3:
    printf("木曜日\n");
    break;
  case 4:
    printf("金曜日\n");
    break;
  case 5:
    printf("土曜日\n");
    break;
  case 6:
    printf("日曜日\n");
    break;
  }
}

/*
実行結果
input year month day
2000 9 15
金曜日
*/
