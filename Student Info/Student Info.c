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
#include <string.h>
#include <Windows.h>

#define SCREEN_CLEAR system("cls"); //ȭ�� �����

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
			printf("���α׷��� �����մϴ�.");
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

void* screen_search(void)
{
	int input_num = 0;

	SCREEN_CLEAR;

	while (1)
	{
		printf("�˻� ������ �����ϼ���.\n\n");
		printf("1. ��ü �˻�\n");
		printf("2. ����(�̻�) �˻�\n");
		printf("3. ���� �˻�\n");
		printf("0. �������� ���ư���\n\n");

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
			printf("\n�߸��� �Է��Դϴ�. �ٽ� �������ּ���.");
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

	printf("�߰��� �л��� �̸��� �Է��ϼ��� (0 �Է½� �������� ��������): ");
	scanf("%s", name);
	if (strcmp(name, "0") == 0)
	{
		return 0;
	}
	else
	{
		printf("�߰��� �л��� ���̸� �Է��ϼ���: ");
		scanf("%d", &age);
		printf("�߰��� �л��� ��ȭ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &phone);

		Insert_data(name, age, phone);
	}

}

void* screen_delete(void)
{
	char name[32];

	SCREEN_CLEAR;

	printf("������ �л��� �̸��� �Է��ϼ��� (0 �Է½� �������� ��������): ");
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