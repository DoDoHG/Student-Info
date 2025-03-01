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
#include <Windows.h>

#define SCREEN_CLEAR system("cls"); //화면 지우기

//System Fn
void* Insert_data(void* t);
void* Delete_data(void* t);

//UI Fn
char* screen_main(void);

typedef struct _student_info {
	int age;
	int phone;
	char name[32];

	void* next;
}student_info;

int main(void)
{
	const char* a = screen_main();
	printf("%s\n", a);


	return 0;
}

void* Insert_data(void* t)
{
	NULL;
}

void* Delete_data(void* t)
{
	NULL;
}

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