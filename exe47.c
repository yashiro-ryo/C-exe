#include <stdio.h>
// 行列式計算
int calcDeterminant(int a11, int a12, int a21, int a22)
{
  return a11 * a22 - a12 * a21;
}

int main()
{
  // 各種変数宣言
  int a1[2], a2[2];
  int b[2];
  // 標準入力
  printf("input a1, a2\n");
  scanf("%d %d %d %d", &a1[0], &a1[1], &a2[0], &a2[1]);
  printf("input b1 b2\n");
  scanf("%d %d", &b[0], &b[1]);
  // クラメールの公式実行
  int x1 = calcDeterminant(b[0], a1[1], b[1], a2[1]) / calcDeterminant(a1[0], a1[1], a2[0], a2[1]);
  int x2 = calcDeterminant(a1[0], b[0], a2[0], b[1]) / calcDeterminant(a1[0], a1[1], a2[0], a2[1]);
  // 結果表示
  printf("result x1 = %d, x2 = %d\n", x1, x2);
}

/* 実行結果 
input a1, a2
1 2 2 2
input b1 b2
2 8
result x1 = 6, x2 = -2
*/
