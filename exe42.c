#include <stdio.h>
#include <stdlib.h>

int main()
{
  int **score;
  int *total;
  int i, j;
  int studentSum, subjectNum;
  // 標準入力
  printf("input student sum :");
  scanf("%d", &studentSum);
  printf("input subject sum :");
  scanf("%d", &subjectNum);
  // 2次元配列のポインタ領域の確保
  score = (int **)calloc(studentSum, sizeof(int *));
  // 1次元配列のポインタ領域確保
  total = (int *)calloc(subjectNum, sizeof(int));
  // 領域の確保チェック
  if (score == NULL || total == NULL)
  {
    printf("Not enough memory\n");
    exit(1);
  }

  // 標準入力部分
  for (i = 0; i < studentSum; i++)
  {
    // 二次元配列のポインタ領域確保
    score[i] = (int *)calloc(subjectNum, sizeof(int));
    // 領域の確保チェック
    if (score[i] == NULL)
    {
      printf("Not enough memory\n");
      exit(1);
    }
    // 結果の初期値を代入
    total[i] = 0;
    printf("No. %d\n", i + 1);
    // 標準入力
    for (j = 0; j < subjectNum; j++)
    {
      printf("score %d : ", j + 1);
      scanf("%d", &score[i][j]);
      total[i] += score[i][j];
    }
  }

  // 結果表示部のインデックスを作成
  printf("\n");
  printf("No.|");
  for (i = 0; i < subjectNum; i++)
  {
    printf("  s%d", i + 1);
  }
  printf(" | total\n");
  printf("---+");
  for (i = 0; i < subjectNum; i++)
  {
    printf("----");
  }
  printf("-+------\n");

  // 結果出力
  for (i = 0; i < studentSum; i++)
  {
    printf("%2d | ", i + 1);
    for (j = 0; j < subjectNum; j++)
    {
      printf("%3d ", score[i][j]);
    }
    printf("| %4d\n", total[i]);
  }
}

/*
実行結果は以下の通り
input student sum :5
input subject sum :5
No. 1
score 1 : 1
score 2 : 2
score 3 : 3
score 4 : 4
score 5 : 5
No. 2
score 1 : 1
score 2 : 2
score 3 : 3
score 4 : 4
score 5 : 5
No. 3
score 1 : 5
score 2 : 4
score 3 : 3
score 4 : 2
score 5 : 1
No. 4
score 1 : 2
score 2 : 3
score 3 : 4
score 4 : 5
score 5 : 6
No. 5
score 1 : 4
score 2 : 3
score 3 : 2
score 4 : 5
score 5 : 4

No.|  s1  s2  s3  s4  s5 | total
---+---------------------+------
 1 |   1   2   3   4   5 |   15
 2 |   1   2   3   4   5 |   15
 3 |   5   4   3   2   1 |   15
 4 |   2   3   4   5   6 |   20
 5 |   4   3   2   5   4 |   18
*/