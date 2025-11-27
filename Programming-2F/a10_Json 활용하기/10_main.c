#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "parson.h"

typedef struct Item
{
	char name[50];
	int price;
}Item;

int main()
{
	printf("JSON 파일 활용하기 예제\n");

	Item item;
	strcpy(item.name, "사과");
	item.price = 10;
	printf("이름 : %s | 가격 : %d\n", item.name, item.price);

	JSON_Value* root_value;
	JSON_Array* items;
	JSON_Object* root_Object;

	root_value = json_parse_file("itemDB.json");
	root_Object = json_value_get_object(root_value);

	//printf("이름 : %s | 가격 : %.0f\n",
	//	json_object_get_string(root_Object, "name"),
	//	json_object_get_number(root_Object, "price"));

	items = json_object_get_array(root_Object, "items"); // 배열

	// object에서 배열을 가져오겠다.
	// 배열에서 n번째
	// 
	// JSON_Object* array_Object_1;
	// array_Object_1 = json_array_get_array(items, 0);
	// json_object_dotget_string(array_Object_1, "name");
	// JSON_Object* array_Object_2;
	// array_Object_2 = json_array_get_array(items, 1);
	// json_object_dotget_string(array_Object_2, "name");

	Item itemStruct[4];
	JSON_Object* array_Object;

	for (int i = 0; i < json_array_get_count(items); i++)
	{
		array_Object = json_array_get_object(items, i);

		strcpy(itemStruct[i].name, json_object_dotget_string(array_Object, "name"));
		itemStruct[i].price = json_object_dotget_number(array_Object, "price");

		printf("이름 : %s | 가격 : %.0f\n",
			json_object_dotget_string(array_Object, "name"),
			json_object_dotget_number(array_Object, "price"));
		

	}
	
}