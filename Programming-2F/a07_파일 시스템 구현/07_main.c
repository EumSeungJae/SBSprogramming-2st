#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "parson.h"
typedef struct _Monster {
	char name[100]; // 배열도 포인터, 포인터로 표현할 수 있다.
	char dialogue[3][100]; // 대사
}Monster;


typedef struct Game {
	char Title[100];
	char Develop[100];
	char Platform[100];
	char  genre[50];
}Game;

int main()
{
	//FILE* fp = fopen("example.txt", "w"); // "example.txt"
	// fprintf(fp, "{");
	// fprintf(fp, "\"%s\" : \"%s\"", "name", "HelloWorld");
	// fprintf(fp, "}");

	//fclose(fp);

	Monster goblin;
	int count = 5;

	FILE* fp2 = fopen("example.txt", "r");
	// 문자열이 필요하니

	fscanf(fp2, "%s %s %s %s %d", goblin.name,
		goblin.dialogue[0], goblin.dialogue[1], goblin.dialogue[2],
		&count);
	fclose(fp2);
	printf("%s %s %s %s %d", goblin.name,
		goblin.dialogue[0], goblin.dialogue[1], goblin.dialogue[2],
		count);

	Monster rabbit;

	JSON_Value* rootValue; // 파일 이름을 불러와서 저장한다.
	JSON_Object* rootObject; // 파일 안에 저장되어 있는 실제 데이터

	rootValue = json_parse_file("Monster.json");
	rootObject = json_value_get_object(rootValue);

	const char* tempName = json_object_get_string(rootObject, "name");

	printf("name : %s\n", json_object_get_string(rootObject, "name"));

	JSON_Array* array = json_object_get_array(rootObject, "dialogue");

	for (int i = 0; i < i < json_array_get_count(array); i++)
	{
		printf("[%s] : %s\n", tempName, json_array_get_string(array, i));
	}
		json_value_free(rootValue);

	//"당근";
	//"깡총";
	//"에휴";

	// 파일을 입력하고 쓰는 예제를 구현했습니다.
	// 메모장에 있는 파일에 규칙을 부여해줘야 하겠구나.

	// Monster데이터의 name에다가 json파일에 name을 찾아서 가져와라.
	// Monster데이터의 name을 json으로 저장해라.
	// JSON -> Java script object notation

	// Json 사용해서 몬스터 데이터를 저장해볼겁니다.
	// 만들어진 소스코드를 가져옵니다.


}

