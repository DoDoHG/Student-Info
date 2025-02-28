#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//학생 추가
//학생 삭제(이름)
//학생 이름으로 전화번호 알아오기
//전체 학생 보기, (검색조건, 2가지로)
//  -. '성'만 보고 예를들어 '김'씨인 학생들 목록 보여주기
//  -. 나이가 몇 이상 학생들 목록 보여주기

// 1. 학생 추가
// 2. 학생 검색
// 3. 학생 삭제

typedef struct _student_info {
	int age;
	int phone;
	char name[32];

	void* next;
}student_info;

int main(void)
{
	return 0;
}

void* Insert_data(void* )
{

}

void* Delete_data(void* )
{

}

