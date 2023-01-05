#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANKING_SIZE (5)


//スコアと名前をセットする構造体
struct ranking_data_t{
    double ranking;
    char name[21];
};
//struct ranking_data_t a[10];

//ランキング表示関数
int print_ranking(struct ranking_data_t ranking_struct[RANKING_SIZE]){
    int junni;
    printf("Rank      Score\n");
    for(int i = 0; i < RANKING_SIZE; i++){
        printf("%2d  .... %f %s\n",i+1 ,ranking_struct[i].ranking, ranking_struct[i].name);
        junni = i+1;
        for(int j = i+1; ranking_struct[i].ranking == ranking_struct[j].ranking; j++){
            printf("%2d  .... %f %s\n",junni ,ranking_struct[j].ranking, ranking_struct[j].name); //junniと置く
            i++; //i+j=10にしたい
        }
    }
}

//スコアのランクを求める
int get_rank(struct ranking_data_t ranking_struct[RANKING_SIZE], double score){
    int rank;
    for(int k = 0; ranking_struct[k].ranking <= score; k++){
        rank = k + 1; //成り立った後の次の[]に入れる
        if(ranking_struct[k].ranking == score){
            rank = k; //同着の時
            break;
        }
    }
    return rank;  //main関数に自分の順位の情報を渡す必要がある
}

//ランキング更新
int update_ranking(struct ranking_data_t ranking_struct[RANKING_SIZE], double score, int rank){
    for(int j = 9; j > rank; j--){
        ranking_struct[j].ranking = ranking_struct[j-1].ranking; //1個ずつ下にずらす
    }
    ranking_struct[rank].ranking = score;
}

//使用可能文字の確認
int name_check(struct ranking_data_t ranking_struct[RANKING_SIZE], int rank){
    for(int i = 0; ranking_struct[rank].name[i] != '\0'; i++){ //null文字が出るまで確認 ➤ null文字が出てきたら終わる
        if(ranking_struct[rank].name[i] >= 65 && ranking_struct[rank].name[i] <= 90);
        else if(ranking_struct[rank].name[i] >= 97 && ranking_struct[rank].name[i] <= 122);
        else if(ranking_struct[rank].name[i] == 46);
        else if(ranking_struct[rank].name[i] >= 48 && ranking_struct[rank].name[i] <= 57);
        else
            return -1; //違反の有無
    }
    return 0; //違反なし
}

//名前更新関数
int name_update(struct ranking_data_t ranking_struct[RANKING_SIZE], int rank){
    for(int i = 9; i > rank; i--){
        for(int j = 0; j < 21; j++){
            ranking_struct[i].name[j] = ranking_struct[i-1].name[j];
        }
    }
}

int main(void){
    int random, input;
    int expect = 1;
    int sum = 0;
    double score = 0.0;
    int rank; //自分の順位‐1 (自分のスコアを入れるやつ）
    int next = 0;
    struct ranking_data_t ranking_struct[RANKING_SIZE] = {1.0,"a",2.0,"b",3.0,"c", 4.0, "d", 5.0, "e"};

    //ランキングに値を入れる
    /*for(int i = 1; i < RANKING_SIZE; i++){
        double plus = 1.0;
        ranking_struct[i].ranking = ranking_struct[i-1].ranking + plus;
    }*/

    print_ranking(ranking_struct);

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
    rank = get_rank(ranking_struct, score); //get_rankで求めた値をrankにいれた

    //ランキング更新
    update_ranking(ranking_struct, score, rank);

    if(rank <= RANKING_SIZE){
        printf("あなたは%d位です!\n",rank+1);
    } else {
        printf("雑魚\n");
    }

    name_update(ranking_struct, rank);

    //ランキングに名前入力
    if (rank <= RANKING_SIZE){
        do{
            printf("名前を入力してね(20文字以内):");
            scanf("%s",ranking_struct[rank].name);
        } while (name_check(ranking_struct,rank) == -1);  //使用不可能文字が含まれもう一度入力させる
    }

    //ランキング表示
    print_ranking(ranking_struct);
    
    do{
        printf("ゲームを続けますか? (Y:1 / N:0) > ");
        scanf("%d", &next);
        if (next == 0){
            return 0;
        }
    } while(next != 0 && next!= 1);
    }
}
