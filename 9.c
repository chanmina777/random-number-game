#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANKING_SIZE (15)

double ranking[RANKING_SIZE] = {1.0};

//ランキング表示関数
int print_ranking(){
    printf("Rank      Score\n");
    for(int i = 0; i < RANKING_SIZE; i++){
        printf("%2d  .... %f\n",i+1 ,ranking[i]);
    }
}

//スコアのランクを求める
int get_rank(double score, int rank){
    for(int k = 0; ranking[k] <= score; k++){
        rank = k + 1; //成り立った後の次の[]に入れる
        if(ranking[k] == score){
            rank = k; //同着の時
            break;
        }
    }
    return rank;  //main関数に自分の順位の情報を渡す必要がある
}

//ランキング更新
int update_ranking(double score, int rank){
    for(int j = 9; j > rank; j--){
        ranking[j] = ranking[j-1]; //1個ずつ下にずらす
    }
    ranking[rank] = score;
}

int main(void){
    int random, input;
    int expect = 1;
    int sum = 0;
    double score = 0.0;
    int rank; //自分の順位‐1 (自分のスコアを入れるやつ）
    int next = 0;

    //ランキングに値を入れる
    for(int i = 1; i < RANKING_SIZE; i++){
        double plus = 1.0;
        ranking[i] = ranking[i-1] + plus;
    }

    print_ranking();

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

    //スコアのランクを求める
    rank = get_rank(score, rank); //get_rankで求めた値をrankにいれた

    //ランキング更新
    update_ranking(score,rank);

    if(rank <= RANKING_SIZE){
        printf("あなたは%d位です!\n",rank+1);
    } else {
        printf("雑魚\n");
    }

    //ランキング表示
    print_ranking();
    
    do{
        printf("ゲームを続けますか? (Y:1 / N:0) >");
        scanf("%d", &next);
        if (next == 0){
            return 0;
        }
    } while(next != 0 && next!= 1);
    }
}
