#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int random, input;
    int expect = 1;
    int sum = 0;
    double score = 0.0;
    int rank; //自分の順位‐1 (自分のスコアを入れるやつ）
    int next = 0;

    //ランキング表示
    double ranking[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}; //10個目の配列には0が格納
    printf("Rank      Score\n");
    for(int i = 0; i < 10; i++){
        printf("%2d  .... %f\n",i+1 ,ranking[i]); //i+1にすることで配列の1番目からスタートする
    }

    srand((unsigned)time(NULL));

    while (1){
        sum = 0;
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
        sum += expect; 
        
    }
    
    score = (double)sum / 3;
    printf("スコア(平均予想回数)は%fです\n",score);

    if(score < 3){
        printf("天才だあ！\n");
    } else if (score < 5){
        printf("そこそこ！\n");
    } else {
        printf("あほおお!!\n");
    }

    //自分の順位求める
    for(int k = 0; ranking[k] <= score; k++){
        rank = k + 1; //成り立った後の次の[]に入れる
        if(ranking[k] == score){
            rank = k; //同着の時
            break;
        }
    }

    //ランキング更新
    for(int j = 9; j > rank; j--){
        ranking[j] = ranking[j-1]; //1個ずつ下にずらす
    }
    ranking[rank] = score;

    if(rank <= 10){
        printf("あなたは%d位です!\n",rank+1);
    } else {
        printf("雑魚\n");
    }

    //更新後のランキング表示
    for(int i = 0; i < 10; i++){
        printf("%2d  .... %f\n",i+1 ,ranking[i]); //i+1にすることで配列の1番目からスタートする
    }
    
    
    do{
        printf("ゲームを続けますか? (Y:1 / N:0) >");
        scanf("%d", &next);
        if (next == 0){
            return 0;
        }
    } while(next != 0 && next!= 1);
    }
}
