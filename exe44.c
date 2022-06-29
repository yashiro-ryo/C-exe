#include <stdio.h>

int functional(int number)
{
  // 結果の初期値を設定
  int result = 1;
  // 階乗の計算
  for (int i = 0; i < number; i++)
  {
    result = result * (i + 1);
  }
  // 結果返却
  return result;
}

int main()
{
  // 各種変数定義
  int n, r, result;
  // 標準入力
  printf("input n, r\n");
  scanf("%d %d", &n, &r);
  // 計算
  result = functional(n) / (functional(r) * functional(n - r));
  // 結果表示
  printf("%d\n", result);
}

/*
実行結果
input n, r
10
3
120
*/