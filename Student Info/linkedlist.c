#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


struct _student_info {
	int age;
	int phone;
	char name[32];

	void* next;
};


//학생 추가
//학생 삭제(이름)
//학생 이름으로 전화번호 알아오기
//전체 학생 보기, (검색조건, 2가지로)
//  -. '성'만 보고 예를들어 '김'씨인 학생들 목록 보여주기
//  -. 나이가 몇 이상 학생들 목록 보여주기

// 1. 학생 추가
// 2. 학생 검색
// 3. 학생 삭제


typedef struct item {
	int val;
	void* next;
}item;


int fetchValue(void* head, int item_index)
{
	int idx = 0;
	int val;
	item* pHead;
	item* pNow;
	pHead = (item*)head;
	pNow = pHead;

	while (pNow != NULL && idx <= item_index)
	{
		if (idx == item_index) {
			val = pNow->val;
			return val;
		}

		pNow = pNow->next;
		idx++;		
	} 

	return -1;
}


void* DeleteItem(void *head, int item_index)
{
	int idx = 0;
	item* pHead;
	item* pNow;
	item* pPrev;

	pHead = (item*)head;
	pNow = pHead;
	pPrev = pHead;

	while (pNow != NULL && idx <= item_index)
	{
		if (idx == item_index)
		{
			//내가 가리키고 있는 포인터를 이전 노드의 next로 저장
			if (head == pNow) {
				head = pNow->next;
			}
			else {
				pPrev->next = pNow->next;
			}
			
			pNow->next = NULL;
			free(pNow);
			return head;
		}

		pPrev = pNow;
		pNow = pNow->next;
		idx++;
	}
}

void* InsertItem(void* head, int item_index, int num)
{
	int idx = 0;
	item* pHead;
	item* pNow;
	item* pPrev;
	item* p = malloc(sizeof(item));

	pHead = (item*)head;
	pNow = pHead;
	pPrev = pHead;

	while (pNow != NULL && idx <= item_index)
	{
		if (idx == item_index)
		{
			if (head == pNow)
			{
				pHead->next = pNow;
				head = p;
			}
			else
			{
				pPrev->next = p;
				p->next = pNow;
			}
			p->val = num;
			return head;
		}

		pPrev = pNow;
		pNow = pNow->next;
		idx++;
	}
}

//int main(void)
//{
//	int item_index;
//	int ret;
//	item* head;
//	item* tail;
//
//	head = malloc(sizeof(item));
//
//	head->val = 0;
//	head->next = NULL;
//
//	tail = head;
//
//	for (int i = 1; i <= 10; i++)
//	{
//		item* p = malloc(sizeof(item));
//
//		//마지막 노드 찾기
//		// 
//		//마지막 노드의 next에 p를 할당.
//		p->val = i;
//		p->next = NULL;
//
//		tail->next = p;
//		tail = p;	
//	}
//
//
//
//	item_index = 0;
//	for (int i = 0; i <= 10; i++)
//	{
//		ret = fetchValue(head, i);
//		printf("%d 번째 item 값 : %d\n", i, ret);
//	}
//
//	printf("\n");
//	head = DeleteItem(head, 1);
//	head = DeleteItem(head, 3);
//	head = DeleteItem(head, 6);
//	
//	for (int i = 0; i <= 10; i++)
//	{
//		ret = fetchValue(head, i);
//		printf("%d 번째 item 값 : %d\n", i, ret);
//	}
//
//	printf("\n");
//	head = InsertItem(head, 1, 20);
//	head = InsertItem(head, 3, 30);
//	head = InsertItem(head, 6, 60);
//
//
//	for (int i = 0; i <= 10; i++)
//	{
//		ret = fetchValue(head, i);
//		printf("%d 번째 item 값 : %d\n", i, ret);
//	}
//
//	
//
//	return 0;
//}




//int push(int n);
//int pop(void);

//int list[10] = { 0 };
//int f = 0;
//int head = 0, tail = 0, hchk = 0, tchk = 0, chk = 1, huse = 10;
//
//int main(void)
//{
//	push(1);
//	push(2);
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	push(3);
//	push(4);
//	printf("%d\n", pop());
//	printf("%d\n\n", pop());
//
//
//
//	for (int i = 0; i < 15; i++)
//	{
//		push(i);
//	}
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	push(3);
//	push(4);
//	for (int i = 0; i < 12; i++)
//	{
//		printf("%d\n", pop());
//	}
//
//	return 0;
//}



//##queue##
//
//int push(int n)
//{
//	if (chk == 1)
//	{
//		list[head] = n;
//		head++;
//		huse--;
//		chk = 0;
//		return 0;
//	}
//	else
//	{
//		if (huse == 0)
//		{
//			return 0;
//		}
//		else
//		{
//			list[head] = n;
//			if (head == 9)
//			{
//				head = 0;
//				hchk++;
//			}
//			else
//			{
//				head++;
//			}
//			huse--;
//
//			return 0;
//			
//		}
//	}
//
//	return 0;
//}
//
//int pop(void)
//{
//	int rt = 0;
//	
//	if (hchk == tchk)
//	{
//		if (head > tail)
//		{
//			rt = list[tail];
//			if (tail == 9)
//			{
//				tail = 0;
//				tchk++;
//			}
//			else
//			{
//				tail++;
//			}
//			huse++;
//
//			return rt;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	else
//	{
//		if (head <= tail)
//		{
//			rt = list[tail];
//			if (tail == 9)
//			{
//				tail = 0;
//				tchk++;
//			}
//			else
//			{
//				tail++;
//			}
//			huse--;
//
//			return rt;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	
//}

//##stack##
// 
//int push(int n)
//{ 
//	if (f <= 9)
//	{
//		list[f] = n;
//		f++;
//		return 0;
//	}
//	else
//	{
//		return -1;
//	}
//	
//}
// 
//int pop(void)
//{
//	int rt = 0;
//
//	if (f > 0)
//	{
//		rt = list[--f];
//		return rt;
//	}
//	else
//	{
//		return -1;
//	}
//}


/*double distance(p1, p2);

typedef struct point
{
	int x, y;
}point;

int main(void)
{
	point p1, p2;

	printf("%p\n", &p1);
	printf("%p", &p2);

	scanf("%d %d", &p1.x, &p1.y);
	scanf("%d %d", &p2.x, &p2.y);

	printf("%lf", distance(p1, p2));

	return 0;
}

double distance(point p1, point p2)
{
	double dist, d1, d2;

	d1 = (abs(p1.x - p2.x));
	d2 = (abs(p1.y - p2.y));

	dist = sqrt((d1 * d1) + (d2 * d2));

	return dist;
}*/