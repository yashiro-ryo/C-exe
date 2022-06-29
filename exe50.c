#include <stdio.h>

int functional(int number)
{
  // 1の場合はそのまま計算せずに返却,1以外の場合は再帰計算
  return number == 1 ? number : number * functional(number - 1);
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
5 3
10
*/