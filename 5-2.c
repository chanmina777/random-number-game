#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int random, input;
    int expect = 1;
    int sum = 0;
    double score = 0.0;

    srand((unsigned)time(NULL));

    for(int i = 1; i <= 3; i++){
        random = 1 + rand() % 100;
        printf("%d\n",random);
        printf("%dターンです\n",i);
        expect = 1;

        while (1){　   
            printf("第%d回予想>",expect++);
            scanf("%d",&input);

            if (input == random){
                printf("やったあ‼第%d回目で正解‼\n",--expect);
                break;
            } else if (input - random <= 5 && -5 <= input - random){
                printf("おしい！\n");
            } else if (input - random <=10 && -10 <= input - random){
                printf("もうちょいかな\n");
            } else {
                printf("ぜんぜんだめ\n");
            }

        }
        sum += expect;  //sumにexpectを1ターンが終わるごとに足していく
        
    }
    score = (double)sum / 3;　　//sumをはじめにintで宣言しているのでdoubleに直すことで小数点表示させている
    printf("%f\n",score); 
    
    if(score < 3){
        printf("天才だあ！");
    } else if (score < 5){
        printf("そこそこ！");
    } else {
        printf("あほおお!!");
    }
}
