#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "parson.h"

// JSON 파일 가져오기.
// Input 설정

typedef struct Item
{
    char name[50];
    int price;
}Item;

// JSON 에서 코드 구현. 저장 시스템. Player 데이터를 저장, 최고 점수를 저장하는 시스템.

// (1) Player 정보를 저장 및 로드하는 시스템 구현

// (2) game에 score 를 저장하고 BestScore와 비교해서 저장하는 시스템


typedef struct GameScore
{
    char name[50];
    int score;
}GameScore;

typedef struct _Player
{
    char name[100];
    int level;
    int stage;
    int coin;
}Player_;

void ScoreBord()
{
        JSON_Value* loadrootValue = json_parse_file("score.json");
        JSON_Object* loadrootObject = json_value_get_object(loadrootValue);
        GameScore score[10];
      

    for (int i = 0; i < 10; i++)
    {
        strcpy(score[i].name, json_object_set_string(loadrootObject, "name",score[i]->name));
        score[i].score = json_object_set_number(loadrootObject, "score",score->score);

        printf("[%.0f] [ %s ] [%.0f]", i + 1,score->score );
    }
}

void SaveFruitDATA()
{
    JSON_Value* root_value = json_value_init_object(); // default Object 생성
    JSON_Object* root_object = json_value_get_object(root_value);

    json_object_set_string(root_object, "name", "apple");
    json_object_set_number(root_object, "price", 10);

    json_serialize_to_file_pretty(root_value, "fruit.json");
    json_value_free(root_value);

}


void SavePlayerDATA(const Player_* player)
{
    JSON_Value* root_value = json_value_init_object(); // default Object 생성
    JSON_Object* root_object = json_value_get_object(root_value);

    json_object_set_string(root_object, "name", player->name);
    json_object_set_number(root_object, "level", player->level);
    json_object_set_number(root_object, "stage", player->stage);
    json_object_set_number(root_object, "coin", player->coin);
    


    json_serialize_to_file_pretty(root_value, "player.json");
    json_value_free(root_value);
}

// Player_ player = LoadPlayerDATA();

Player_ LoadPlayerDATA()
{
    JSON_Value* loadrootValue = json_parse_file("player.json");
    JSON_Object* loadrootObject = json_value_get_object(loadrootValue);

    printf("name : %s\n", json_object_get_string(loadrootObject, "name"));
    printf("level : %.0f\n", json_object_get_number(loadrootObject, "level"));
    printf("stage : %.0f\n", json_object_get_number(loadrootObject, "stage"));
    printf("coin : %.0f\n" ,json_object_get_number(loadrootObject, "coin"));

    Player_ newPlayer;
    strcpy(newPlayer.name, json_object_get_string(loadrootObject, "name"));
    newPlayer.level = json_object_get_number(loadrootObject, "level");
    newPlayer.stage = json_object_get_number(loadrootObject, "stage");
    newPlayer.coin = json_object_get_number(loadrootObject, "coin");
    return newPlayer;
}


void SaveScoreData(const GameScore* score)
{
    JSON_Value* rootValue = json_value_init_object(); // default Object생성
    JSON_Object* rootObject = json_value_get_object(rootValue);

    json_object_set_string(rootObject, "name", score->name);
    json_object_set_number(rootObject, "score", score->score);

    json_serialize_to_file_pretty(rootValue, "score.json");
    json_value_free(rootValue);
}
void LoadFruitDATA()
{
    JSON_Value* loadrootValue = json_parse_file("fruit.json");
    JSON_Object* loadrootObject = json_value_get_object(loadrootValue);

    printf("name : %s\n", json_object_get_string(loadrootObject, "name"));
    printf("price : %.0f\n", json_object_get_number(loadrootObject, "price"));
}



int main()
{
    printf("JSON 입력 예제 구현 \n\n"); // Save 구현, [Player데이터, BestScore]
   

    // 포인터 > 주소. 초기화? ? NULL = (void*)0
    SaveFruitDATA();
    LoadFruitDATA();
    // 플레이어 구조체를 저장 및 로드 하기 예제

    Player_ player;
    player.level = 5;
    strcpy(player.name, "cham cham");
    player.stage = 2;
    player.coin = 10;

    GameScore score;
    strcpy(score.name, player.name);
    score.score = player.stage;
    ScoreBord();


    printf("저장하시겠습니까? [0] yes / [1] no\n");
    int select = 0;
    scanf("%d", &select);
    if (select == 0)
    {
    SavePlayerDATA(&player);
    }
    else
    {

    }

    // 만약에 player.json 경로가 있으면 파일을 가져와라
    player = LoadPlayerDATA();

}