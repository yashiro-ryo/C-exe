#include <stdio.h>
int main()
{
  // 各種変数定義
  int i, j, temp, arrayLength;
  // 配列の長さを入力
  printf("input array length :");
  scanf("%d", &arrayLength);
  // 配列定義
  // TODO check null
  int s[arrayLength];
  // 数値入力
  for (i = 0; i < arrayLength; i++)
  {
    printf("s[%d] ? ", i);
    scanf("%d", s + i);
  }
  // ソート部
  for (i = 0; i < arrayLength; i++)
  {
    for (j = i + 1; j < arrayLength; j++)
      // 2つの値を比較し、大きい方を片方の後ろに代入する
      if (*(s + i) > *(s + j))
      {
        temp = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = temp;
      }
    // 結果表示
    printf("s[%d] = %d\n", i, *(s + i));
  }
}

/**
 * 実行結果
 * input array length :5
 * s[0] ? 12
 * s[1] ? 23
 * s[2] ? 32
 * s[3] ? 11
 * s[4] ? 9
 * s[0] = 9
 * s[1] = 11
 * s[2] = 12
 * s[3] = 23
 * s[4] = 32
 */
