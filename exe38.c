#include <stdio.h>
#include <ctype.h> // 文字列処理ライブラリ

// 文字列を分類する関数
void classifyStrType(const char *str)
{
  // 結果表示用変数
  int upperStrNum = 0;
  int lowerStrNum = 0;
  int numberStrNum = 0;
  int otherStrNum = 0;
  // 文字列の終端まで照査
  while (*str)
  {
    if (isupper(*str))
    {
      //大文字判定
      upperStrNum++;
    }
    else if (islower(*str))
    {
      //小文字判定
      lowerStrNum++;
    }
    else if (isnumber(*str))
    {
      //数字判定
      numberStrNum++;
    }
    else
    {
      //other
      otherStrNum++;
    }
    //次の文字列を照査
    *str++;
  }
  //結果表示
  printf("ALPHABET = %d個\nalphabet = %d個\nnumeral = %d個\nothers = %d個\n", upperStrNum, lowerStrNum, numberStrNum, otherStrNum);
}

int main()
{
  // 入力用文字列
  char str[128];
  printf("input string\n");
  // 文字列入力
  scanf("%s", str);
  // 処理実装
  classifyStrType(str);
}

/**
 * 実行結果
 * input string
 * aiueoAIUEO1234@;:~`
 * ALPHABET = 5個
 * alphabet = 5個
 * numeral = 4個
 * others = 5個
 */