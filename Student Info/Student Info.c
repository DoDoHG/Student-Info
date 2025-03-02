//학생 추가
//학생 삭제(이름)
//학생 이름으로 전화번호 알아오기
//전체 학생 보기, (검색조건, 2가지로)
//  -. '성'만 보고 예를들어 '김'씨인 학생들 목록 보여주기
//  -. 나이가 몇 이상 학생들 목록 보여주기

// 1. 학생 추가
// 2. 학생 검색
// 3. 학생 삭제



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define SCREEN_CLEAR system("cls"); //화면 지우기

//System Fn
void* Search_data(void* t);
void* Search_data_age(void* t);
void* Search_data_name(void* t);
void* Insert_data(void* t);
void* Delete_data(void* t);

//UI Fn
char* screen_main(void);
void* screen_search(void);
void* screen_addition(void);
void* screen_delete(void);
void* screen_exit(void);

typedef struct _student_info {
	int age;
	int phone;
	char* name[32];

	void* next;
}student_info;

student_info* head;
student_info* next;



int main(void)
{
	const char* screen;

	head = malloc(sizeof(student_info));
	head->age = 0;
	head->phone = 0;
	strcpy(head->name, "Empty");
	head->next = NULL;

	while (1)
	{
		SCREEN_CLEAR;

		screen = screen_main();

		if (screen == "Search")
		{
			screen_search();
		}
		else if (screen == "Add")
		{
			screen_addition();
		}
		else if (screen == "Del")
		{
			screen_delete();
		}
		else if (screen == "Exit")
		{
			SCREEN_CLEAR;
			printf("프로그램을 종료합니다.");
			Sleep(5000);
			exit(0);
		}
	}
	


	return 0;
}



//System Fn
void* Search_data_all(void* t)
{
	NULL;
}

void* Search_data_age(void* t)
{
	NULL;
}

void* Search_data_name(void* t)
{
	NULL;
}

void* Insert_data(void* t)
{
	NULL;
}

void* Delete_data(void* t)
{
	NULL;
}


//UI Fn
char* screen_main(void)
{
	int input_num = 0;

	while (1)
	{
		printf("수행할 작업을 선택하세요.\n\n");
		printf("1. 학생 검색\n");
		printf("2. 학생 추가\n");
		printf("3. 학생 삭제\n");
		printf("0. 프로그램 종료\n\n");

		scanf("%d", &input_num);

		if (input_num == 1)
		{
			return "Search";
		}
		else if (input_num == 2)
		{
			return "Add";
		}
		else if (input_num == 3)
		{
			return "Del";
		}
		else if (input_num == 0)
		{
			return "Exit";
		}
		else
		{
			printf("\n잘못된 입력입니다. 다시 선택해주세요.");
			Sleep(5000);
			SCREEN_CLEAR;
		}
	}
}

void* screen_search(void)
{
	int input_num = 0;

	SCREEN_CLEAR;

	while (1)
	{
		printf("검색 조건을 선택하세요.\n\n");
		printf("1. 전체 검색\n");
		printf("2. 나이(이상) 검색\n");
		printf("3. 성씨 검색\n");
		printf("0. 메인으로 돌아가기\n\n");

		scanf("%d", &input_num);

		if (input_num == 1)
		{
			Search_data_all("All");
		}
		else if (input_num == 2)
		{
			Search_data_age("Age");
		}
		else if (input_num == 3)
		{
			Search_data_name("Name");
		}
		else if (input_num == 0)
		{
			return 0;
		}
		else
		{
			printf("\n잘못된 입력입니다. 다시 선택해주세요.");
			Sleep(5000);
			SCREEN_CLEAR;
		}
	}
}

void* screen_addition(void)
{
	int age = 0, phone = 0;
	char name[32];

	SCREEN_CLEAR;

	printf("추가할 학생의 이름을 입력하세요 (0 입력시 메인으로 돌가가기): ");
	scanf("%s", name);
	if (strcmp(name, "0") == 0)
	{
		return 0;
	}
	else
	{
		printf("추가할 학생의 나이를 입력하세요: ");
		scanf("%d", &age);
		printf("추가할 학생의 전화번호를 입력하세요: ");
		scanf("%d", &phone);

		Insert_data(name, age, phone);
	}

}

void* screen_delete(void)
{
	char name[32];

	SCREEN_CLEAR;

	printf("삭제할 학생의 이름을 입력하세요 (0 입력시 메인으로 돌가가기): ");
	scanf("%s", name);

	if (strcmp(name, "0") == 0)
	{
		return 0;
	}
	else
	{
		Delete_data(name);
	}

}