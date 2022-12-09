#include <stdio.h>
#include <stdlib.h>　　//srand関数を使うため
#include <time.h>　　//timeを使うため1秒ごとに違う乱数が生成される

int main(void){
    int random;
    int expect;

    srand((unsigned)time(NULL));　//乱数を生成
    random = 1 + rand() % 100;　//乱数を呼び出す
    printf("%d\n",random);
    scanf("%d",&expect);

    if(expect - random <= 5 && -5 <= expect - random){
        printf("おしい！\n");
    } else if (expect - random <=10 && -10 <= expect - random){
        printf("もうちょいかな\n");
    } else {
        printf("ぜんぜんだめ\n");
    }
}
