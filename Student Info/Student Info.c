//�л� �߰�
//�л� ����(�̸�)
//�л� �̸����� ��ȭ��ȣ �˾ƿ���
//��ü �л� ����, (�˻�����, 2������)
//  -. '��'�� ���� ������� '��'���� �л��� ��� �����ֱ�
//  -. ���̰� �� �̻� �л��� ��� �����ֱ�

// 1. �л� �߰�
// 2. �л� �˻�
// 3. �л� ����



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SCREEN_CLEAR system("cls"); //ȭ�� �����

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
		printf("������ �۾��� �����ϼ���.\n\n");
		printf("1. �л� �˻�\n");
		printf("2. �л� �߰�\n");
		printf("3. �л� ����\n");
		printf("0. ���α׷� ����\n\n");

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
			printf("\n�߸��� �Է��Դϴ�. �ٽ� �������ּ���.");
			Sleep(5000);
			SCREEN_CLEAR;

		}
	}
	
}