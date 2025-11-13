#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy 두 문자열을 복사 
#include <stdlib.h> // malloc 함수

// int number; -> 4바이트, 정수로 읽겠다. 시작하는 주소가 있어야 한다.
typedef struct {
	int number;
	char* name;
	char* class;
	char* coment;
}Student;

// Item inventory 구조체 만들어보세요.
// 몬스터 처치했다. -> 인벤토리에 보상을 저장
// Reward() << Inventory << Item
// 동적으로 변할 수 있도록 설정.
// 내 아이템의 크기를 변경해주는 함수. SetMyInventory()




// char A[80]; 배열로 표현하는 것과 -> 컴파일러가 주소를 직접 배정을 해준다.정적할당 
// char* Ab = malloc(sizeof(char) * 100); // 실행중에 메모리를 할당한다. 동적할당
// char* A[100]; 

// 동적할당 왜 필요한가요?
// 인벤토리. 몬스터의 보상을 저장을 한다. 아이템 1개.
// 인벤토리의 공간을 얼마나 할당을 해야 하나요?
// 정정한 인벤토리의 갯수는요? 80개
// 이 게임은 진행하는 동안 평생 80개 까지만 저장할 수 있다.
// 인벤토리 공간 확장 기능. 80 -> 90 1000
// 1000000, 10개 필요하면 10개만 만들자. 20개 필요하면 20개 만들자.
// ㄴ 

// [메모리 할당을 하면 - 메모리 해제] -> 에러. 공유 포인터

void Test()
{
	int a; // 값은 들어 있지 않아도 주소는 생성된다.
	printf("a의 주소 : %p\n", &a);
	char* name; // 주소를 저장하는 타입인데 주소가 저장되어 있지 않다.
	name = malloc(sizeof(char) * 100); // 주소를 직접 지정을 해주겠다.(프로그래머의 명령문)
	printf("name 주소 : %p\n", &name);
	char nameArray[100]; // 주소가 만들어 져있다.

	// 주소는 변수만들 때 무조건 만들어지는구나!
	// 어떤 Tpye 선언할 때 그 데이터를 저장할 수 있는 주소가 만들어지는구나.

	// 중단점을 걸기위함 _getch()
	// scanf("%d", &a);
	free(name); // 메모리 제거
}

void SetStudentInfo(Student* student)
{
	printf("학생의 이름을 작성해주세요 : ");
	char* temp = malloc(sizeof(char) * 100);
	scanf("%s", temp);

	// student학생의 char주소에 이름을 저장하고 싶어
	// student->name 주소는 지금 컴퓨터 메모리에 할당되어 있지 않은 상태.
	// 메모리 할당을 어떻게 할 수 있나요? malloc 함수
	// 메모리 할당을 하면 어떤 일이 있나요?
	student->name = malloc(sizeof(char) * 100);
	strcpy(student->name, temp);  // 두번째 에러
	
	printf("학생의 번호를 작성해주세요 : ");
	scanf("%d", &student->number);
	
	student->class = malloc(sizeof(char) * 100);
	printf("학생의 반을 배정해주세요 :");
	scanf("%s", temp);
	strcpy(student->class, temp);

	student->coment = malloc(sizeof(char) * 100);
	printf("학생의 코멘트 : ");
	scanf("%s", temp);
	strcpy(student->coment, temp);
	

	//student->comment
	// char name[100]
	// char* name = malloc(sizeof(char)*100);
	//free();
}

// Student, Student*
// Studemt student = s1;
void PrintStudentInfo(Student student)
{
	printf("학생의 번호 : %d , 학생의 이름 : %s \n", student.number,student.name );
}

void PrintStudentInfoPtr(Student* student)
{
	// (*student).number

	printf("학생의 번호 : %d , 학생의 이름 : %s \n",student->number,student->name );
}

// Player의 이동 구조체 구현해서 함수로 설정할 수 있게 만들어보세요.
// 텍스트도 포인터로 받아올 수 있게 되었다.

int main()
{
	while (1)
	{
		Test();
		break;
	}
	Student Test;

	Student s1;
	s1.number = 1;
	s1.name = "피카츄";

	Student s2;
	s2.number = 2;
	s2.name = "라이츄";

	SetStudentInfo(&Test);
	PrintStudentInfo(Test);
	PrintStudentInfoPtr(&s2);

	//Release();
	// 프로그램이 끝날 때 모든 동적할당 주소들을 해제해야한다.
	//
}

// 윈도우 OS 파일 읽어오고 실행하고.. 메모리를 자동으로 해제.


