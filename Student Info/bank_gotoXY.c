#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ENTER 13 //엔터키
#define UP 72 //윗쪽 방향키
#define DOWN 80 //아랫쪽 방향키
#define RIGHT 77 //오른쪽 방향키
#define LEFT 75 //왼쪽방향키
#define CLR system("cls"); //화면 지우기

int inputKey; //키 저장
int pwlr = 9; //키배드 좌우
int pwud = 10; //키패드 위아래

void gotoXY(int posX, int posY);
void input_card(struct bank_info* user); //카드 및 통장 삽입
void input_money(struct bank_info* user); //입금
void with_money(struct bank_info* user); //출금
void check_money(struct bank_info* user); //계좌확인
void remit_money(struct bank_info* user); //송금
void remit_money_nact(struct bank_info* user); //송금에서 계좌번호 입력
void remit_money_rec(struct bank_info* user); //송금에서 최근 송금목록
void act_password(struct bank_info* user); //계좌 비밀번호 입력


struct bank_info //사용자 정보
{
	char* name; //이름
	long long* actm; //메인계좌 잔고
	long long* acts; //서브계좌 잔고
	int loginpw[4]; //로그인 비밀번호
	int actpw[6]; //계좌 비밀번호
	long long actsn; //서브계좌번호
	char* actsb; //서브계좌은행
};

struct bank_info bank = { "씨쁠쁠", 6540000, 246000, {4, 3, 2, 1}, {6, 5, 4, 3, 2, 1}, 1972112131028, "국민은행" };

int main(void)
{
	int posX = 47, posY = 2;

	input_card(&bank);

	printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│     어서오세요 %s 고객님!     │             입금       │\n", bank.name);
	printf("│   원하시는 기능을 선택해주세요.   │             출금       │\n");
	printf("│                                   │             예금 조회  │\n");
	printf("│                                   │             송금       │\n");
	printf("│                                   │             종료       │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(posX, posY);
	printf("▶");


	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == UP)
			{
				if (posY != 2)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY--;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == DOWN)
			{
				if (posY != 6)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY++;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == ENTER)
			{
				if (posY == 2)
				{
					input_money(&bank);
				}
				else if (posY == 3)
				{
					with_money(&bank);
				}
				else if (posY == 4)
				{
					check_money(&bank);
				}
				else if (posY == 5)
				{
					remit_money(&bank);
				}
				else if (posY == 6)
				{
					CLR
						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│     이용해주셔서 감사합니다.      │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");
					Sleep(5000);

					CLR
						main();
				}
			}
		}
	}
}

/*====================================================================
							카드/통장 인식
====================================================================*/
void input_card(struct bank_info* user)
{
	srand(time(NULL));
	long long pw[4] = { 0 };
	int roadtime = (rand() % 5000) + 1500;
	int j;

	printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│     카드나 통장을 삽입해주세요.   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	while (1)
	{
		if (_kbhit())
		{
			inputKey = _getch();
			if (inputKey == ENTER)
			{
				CLR
					break;
			}
		}
	}

	printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│        통장을 읽고있습니다...     │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	Sleep(roadtime);
	CLR

		for (int i = 0; i < 5; i++)
		{
			printf("┌───────────────────────────────────┬────────────────────────┐\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│   비밀번호 4자리를 입력해주세요.  │                        │\n");
			printf("│    비밀번호:                      │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("├───────────────────────────────────┤                        │\n");
			printf("│                                   │                        │\n");
			printf("│        1        2        3        │                        │\n");
			printf("│        4        5        6        │                        │\n");
			printf("│        7        8        9        │                        │\n");
			printf("│                 0                 │                        │\n");
			printf("│                                   │                        │\n");
			printf("└───────────────────────────────────┴────────────────────────┘\n");

			gotoXY(pwlr, pwud);

			for (j = 0; j < 4; j++)
			{
				while (1) //키패드
				{
					if (_kbhit())
					{
						inputKey = _getch();
						if (inputKey == RIGHT)
						{
							if (pwlr < 19)
							{
								gotoXY(pwlr + 9, pwud);
								pwlr = pwlr + 9;
							}

						}
						else if (inputKey == LEFT)
						{
							if (pwlr > 9)
							{
								gotoXY(pwlr - 9, pwud);
								pwlr = pwlr - 9;
							}

						}
						else if (inputKey == DOWN)
						{
							if (pwud < 13)
							{
								gotoXY(pwlr, pwud + 1);
								pwud = pwud + 1;
							}

						}
						else if (inputKey == UP)
						{
							if (pwud > 10)
							{
								gotoXY(pwlr, pwud - 1);
								pwud = pwud - 1;
							}

						}
						else if (inputKey == ENTER)
						{
							if ((pwlr == 9) && (pwud == 10)) //1
							{
								gotoXY(15 + j, 4);
								printf("1");
								pw[j] = 1;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 18) && (pwud == 10)) //2
							{
								gotoXY(15 + j, 4);
								printf("2");
								pw[j] = 2;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 27) && (pwud == 10)) //3
							{
								gotoXY(15 + j, 4);
								printf("3");
								pw[j] = 3;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 9) && (pwud == 11)) //4
							{
								gotoXY(15 + j, 4);
								printf("4");
								pw[j] = 4;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 18) && (pwud == 11)) //5
							{
								gotoXY(15 + j, 4);
								printf("5");
								pw[j] = 5;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 27) && (pwud == 11)) //6
							{
								gotoXY(15 + j, 4);
								printf("6");
								pw[j] = 6;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 9) && (pwud == 12)) //7
							{
								gotoXY(15 + j, 4);
								printf("7");
								pw[j] = 7;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 18) && (pwud == 12)) //8
							{
								gotoXY(15 + j, 4);
								printf("8");
								pw[j] = 8;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 27) && (pwud == 12)) //9
							{
								gotoXY(15 + j, 4);
								printf("9");
								pw[j] = 9;
								gotoXY(pwlr, pwud);
								break;
							}
							else if ((pwlr == 18) && (pwud == 13)) //0
							{
								gotoXY(15 + j, 4);
								printf("0");
								pw[j] = 0;
								gotoXY(pwlr, pwud);
								break;
							}
						}
					}
				}
			}

			if ((pw[0] == user->loginpw[0]) && (pw[1] == user->loginpw[1]) && (pw[2] == user->loginpw[2]) && (pw[3] == user->loginpw[3]))
			{
				CLR
					return 0;
			}
			else
			{
				CLR

					printf("┌───────────────────────────────────┬────────────────────────┐\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│    비밀번호가 바르지 않습니다.    │                        │\n");
				printf("│   다시 입력해주세요.  ( %d / 5 )   │                        │\n", i + 1);
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("├───────────────────────────────────┤                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("└───────────────────────────────────┴────────────────────────┘\n");

				Sleep(2000);
				CLR
			}
		}

	printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│    비밀번호를 5회 틀리셨습니다.   │                        │\n");
	printf("│        처음으로 돌아갑니다.       │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");
	Sleep(5000);

	CLR
		main();
}

/*====================================================================
								입금
====================================================================*/
void input_money(struct bank_info* user)
{
	int posX = 47, posY = 2, input = 0;
	long long money = 0;

	CLR

		act_password(user);

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                입금               │                        │\n");
	printf("│                                   │                        │\n");
	printf("│   입금하실 금액을 입력해주세요.   │                        │\n");
	printf("│    금액:                          │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(11, 5);
	scanf("%lld", &money);

	CLR
		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│       현금을 세고있습니다.        │                        │\n");
	printf("│       잠시만 기다려주세요.        │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");
	Sleep(5000);

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                입금               │             확인       │\n");
	printf("│                                   │             취소       │\n");
	printf("│        금액을 확인해주세요.       │                        │\n");
	printf("│              %lld 원\n", money);
	printf("│ 위 내용을 확인하시고 맞으시면 확인│                        │\n");
	printf("│ 틀릴 경우에는 취소를 눌러주세요.  │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(36, 5);
	printf("│                        │");

	gotoXY(posX, posY);
	printf("▶");

	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == UP)
			{
				if (posY != 2)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY--;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == DOWN)
			{
				if (posY != 3)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY++;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == ENTER)
			{
				CLR
					if (posY == 2)
					{
						user->actm = user->actm + (money / 8);

						printf("┌───────────────────────────────────┬────────────────────────┐\n");
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("│     이용해주셔서 감사합니다.      │                        │\n");
						printf("│        거래 후 현재 잔액은        │                        │\n");
						printf("│        %lld 원 입니다.\n", user->actm);
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("├───────────────────────────────────┤                        │\n");
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("│                                   │                        │\n");
						printf("└───────────────────────────────────┴────────────────────────┘\n");

						gotoXY(36, 5);
						printf("│                        │");
						gotoXY(0, 10);
						Sleep(5000);

						CLR
							main();
					}
					else if (posY == 3)
					{
						main();
					}
			}
		}
	}
}

/*====================================================================
								출금
====================================================================*/
void with_money(struct bank_info* user)
{
	long long money = 0;

	CLR

		act_password(user);

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                출금               │                        │\n");
	printf("│                                   │                        │\n");
	printf("│   출금하실 금액을 입력해주세요.   │                        │\n");
	printf("│    금액:                          │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");
	gotoXY(11, 5);
	scanf("%lld", &money);

	if (user->actm < money)
	{
		CLR
			printf("┌───────────────────────────────────┬────────────────────────┐\n");
		printf("│                                   │                        │\n");
		printf("│                출금               │                        │\n");
		printf("│                                   │                        │\n");
		printf("│         잔액이 부족합니다.        │                        │\n");
		printf("│        처음으로 돌아갑니다.       │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("├───────────────────────────────────┤                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("└───────────────────────────────────┴────────────────────────┘\n");
		Sleep(5000);

		CLR
			main();
	}
	else if (money < 1000)
	{
		CLR
			printf("┌───────────────────────────────────┬────────────────────────┐\n");
		printf("│                                   │                        │\n");
		printf("│                출금               │                        │\n");
		printf("│                                   │                        │\n");
		printf("│  최소 출금 금액에 미치지 않습니다.│                        │\n");
		printf("│        처음으로 돌아갑니다.       │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("├───────────────────────────────────┤                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("└───────────────────────────────────┴────────────────────────┘\n");
		Sleep(5000);

		CLR
			main();
	}
	else if (user->actm >= money)
	{
		CLR
			printf("┌───────────────────────────────────┬────────────────────────┐\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│       현금을 준비중입니다.        │                        │\n");
		printf("│       잠시만 기다려주세요.        │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("├───────────────────────────────────┤                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("└───────────────────────────────────┴────────────────────────┘\n");
		Sleep(3000);

		user->actm = user->actm - (money / 8);

		CLR
			printf("┌───────────────────────────────────┬────────────────────────┐\n");
		printf("│                                   │                        │\n");
		printf("│                출금               │           ▶ 확인      │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│    현금을 챙기신 후 확인버튼을    │                        │\n");
		printf("│            눌러주세요.            │                        │\n");
		printf("│                                   │                        │\n");
		printf("├───────────────────────────────────┤                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("└───────────────────────────────────┴────────────────────────┘\n");

		while (1) //작업선택
		{
			if (_kbhit())
			{
				inputKey = _getch();
				if (inputKey == ENTER)
				{
					CLR
						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│     이용해주셔서 감사합니다.      │                        │\n");
					printf("│        거래 후 현재 잔액은        │                        │\n");
					printf("│        %lld 원 입니다.\n", user->actm);
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");

					gotoXY(36, 5);
					printf("│                        │");
					gotoXY(0, 10);

					Sleep(5000);

					CLR
						main();
				}
			}
		}
	}
}

/*====================================================================
							 계좌 확인
====================================================================*/
void check_money(struct bank_info* user)
{
	CLR

		act_password(user);

	CLR
		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│              계좌 확인            │            ▶ 확인     │\n");
	printf("│                                   │                        │\n");
	printf("│    현재잔액은 %lld 원 입니다.\n", user->actm);
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(36, 4);
	printf("│                        │");
	gotoXY(0, 7);

	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();
			if (inputKey == ENTER)
			{
				CLR
					main();
			}
		}
	}
}

/*====================================================================
								송금
====================================================================*/
void remit_money(struct bank_info* user)
{
	int posX = 45, posY = 2;

	CLR

		act_password(user);

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                송금               │           계좌입력     │\n");
	printf("│                                   │           최근보낸계좌 │\n");
	printf("│    송금할 계좌를 선택해주세요.    │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(posX, posY);
	printf("▶");

	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == UP)
			{
				if (posY != 2)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY--;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == DOWN)
			{
				if (posY != 3)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY++;
					gotoXY(posX, posY);
					printf("▶ ");
				}
			}
			else if (inputKey == ENTER)
			{
				if (posY == 2)
				{
					remit_money_nact(user);
				}
				else if (posY == 3)
				{
					remit_money_rec(user);
				}
			}
		}
	}


}

/*====================================================================
						  송금에서 계좌 입력
====================================================================*/
void remit_money_nact(struct bank_info* user)
{
	int posX = 45, posY = 2, pw = 0, i = 0;
	long long  act = 0, money = 0;

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│  계좌번호를 입력해주세요. (-없이) │                        │\n");
	printf("│    계좌번호:                      │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");
	gotoXY(15, 4);
	scanf("%lld", &act);

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                송금               │            KDB산업은행 │\n");
	printf("│                                   │            IBK기업은행 │\n");
	printf("│    계좌의 은행을 선택해주세요.    │            KB국민은행  │\n");
	printf("│                                   │            하나은행    │\n");
	printf("│                                   │            우리은행    │\n");
	printf("│                                   │            신한은행    │\n");
	printf("├───────────────────────────────────┤            MG새마을금고│\n");
	printf("│                                   │            SC제일은행  │\n");
	printf("│                                   │            한국씨티은행│\n");
	printf("│                                   │            NH농협은행  │\n");
	printf("│                                   │            수협은행    │\n");
	printf("│                                   │            대구은행    │\n");
	printf("│                                   │            부산은행    │\n");
	printf("│                                   │            광주은행    │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(posX, posY);
	printf("▶");

	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == UP)
			{
				if (posY != 2)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY--;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == DOWN)
			{
				if (posY != 15)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY++;
					gotoXY(posX, posY);
					printf("▶ ");
				}
			}
			else if (inputKey == ENTER)
			{
				CLR

					printf("┌───────────────────────────────────┬────────────────────────┐\n");
				printf("│                                   │                        │\n");
				printf("│                송금               │                        │\n");
				printf("│                                   │                        │\n");
				printf("│   송금하실 금액을 입력해주세요.   │                        │\n");
				printf("│    금액:                          │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("├───────────────────────────────────┤                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("└───────────────────────────────────┴────────────────────────┘\n");
				gotoXY(11, 5);
				scanf("%lld", &money);

				if (user->actm < money)
				{
					CLR
						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                송금               │                        │\n");
					printf("│                                   │                        │\n");
					printf("│         잔액이 부족합니다.        │                        │\n");
					printf("│        처음으로 돌아갑니다.       │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");
					Sleep(5000);

					CLR
						main();
				}
				else
				{
					CLR

						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                송금               │            확인        │\n");
					printf("│                                   │            취소        │\n");
					printf("│   입력하신 정보를 확인해주세요.   │                        │\n");
					printf("│   계좌: %lld \n\n", act);
					printf("│   금액: %lld \n", money);
					printf("│      위 내용을 확인해주세요.      │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");

					gotoXY(36, 5);
					printf("│                        │\n");
					gotoXY(36, 7);
					printf("│                        │\n");

					switch (posY)
					{
					case 2:
						gotoXY(0, 6);
						printf("│   은행: KDB산업은행               │                        │\n");
						break;

					case 3:
						gotoXY(0, 6);
						printf("│   은행: IBK기업은행               │                        │\n");
						break;

					case 4:
						gotoXY(0, 6);
						printf("│   은행: KB국민은행                │                        │\n");
						break;

					case 5:
						gotoXY(0, 6);
						printf("│   은행: 하나은행                  │                        │\n");
						break;

					case 6:
						gotoXY(0, 6);
						printf("│   은행: 우리은행                  │                        │\n");
						break;

					case 7:
						gotoXY(0, 6);
						printf("│   은행: 신한은행                  │                        │\n");
						break;

					case 8:
						gotoXY(0, 6);
						printf("│   은행:  MG새마을금고             │                        │\n");
						break;

					case 9:
						gotoXY(0, 6);
						printf("│   은행: SC제일은행                │                        │\n");
						break;

					case 10:
						gotoXY(0, 6);
						printf("│   은행: 한국씨티은행               │                        │\n");
						break;

					case 11:
						gotoXY(0, 6);
						printf("│   은행: NH농협은행                │                        │\n");
						break;

					case 12:
						gotoXY(0, 6);
						printf("│   은행: 수협은행                  │                        │\n");
						break;

					case 13:
						gotoXY(0, 6);
						printf("│   은행: 대구은행                  │                        │\n");
						break;

					case 14:
						gotoXY(0, 6);
						printf("│   은행: 부산은행                  │                        │\n");
						break;

					case 15:
						gotoXY(0, 6);
						printf("│   은행: 광주은행                  │                        │\n");
						break;
					}
				}

				break;
			}
		}
	}

	posY = 2;
	gotoXY(posX, posY);
	printf("▶");

	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == UP)
			{
				if (posY != 2)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY--;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == DOWN)
			{
				if (posY != 3)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY++;
					gotoXY(posX, posY);
					printf("▶ ");
				}
			}
			else if (inputKey == ENTER)
			{
				if (posY == 2)
				{
					user->actm = user->actm - (money / 8);

					CLR
						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│     이용해주셔서 감사합니다.      │                        │\n");
					printf("│ 정상적으로 송금을 완료하였습니다. │                        │\n");
					printf("│                                   │                        │\n");
					printf("│        거래 후 현재 잔액은        │                        │\n");
					printf("│        %lld 원 입니다.\n", user->actm);
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");
					gotoXY(36, 6);
					printf("│                        │");
					gotoXY(0, 10);

					Sleep(5000);

					CLR
						main();
				}
				else if (posY == 3)
				{
					CLR
						main();
				}
			}
		}
	}
}

/*====================================================================
						  송금에서 최근 송금목록
====================================================================*/
void remit_money_rec(struct bank_info* user)
{
	int posX = 45, posY = 2, i = 0;
	long long money = 0;

	CLR

		printf("┌───────────────────────────────────┬────────────────────────┐\n");
	printf("│                                   │                        │\n");
	printf("│                송금               │            %s      │\n", user->name);
	printf("│                                   │                        │\n");
	printf("│    거래할 계좌를 선택해주세요.    │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("├───────────────────────────────────┤                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("│                                   │                        │\n");
	printf("└───────────────────────────────────┴────────────────────────┘\n");

	gotoXY(posX, posY);
	printf("▶");

	while (1)
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == ENTER)
			{
				CLR
					printf("┌───────────────────────────────────┬────────────────────────┐\n");
				printf("│                                   │                        │\n");
				printf("│                송금               │                        │\n");
				printf("│                                   │                        │\n");
				printf("│   송금하실 금액을 입력해주세요.   │                        │\n");
				printf("│    금액:                          │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("├───────────────────────────────────┤                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("│                                   │                        │\n");
				printf("└───────────────────────────────────┴────────────────────────┘\n");
				gotoXY(11, 5);
				scanf("%lld", &money);

				if (user->actm < money)
				{
					CLR
						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                송금               │                        │\n");
					printf("│                                   │                        │\n");
					printf("│         잔액이 부족합니다.        │                        │\n");
					printf("│        처음으로 돌아갑니다.       │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");
					Sleep(5000);

					CLR
						main();
				}
				else
				{
					CLR

						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                송금               │            확인        │\n");
					printf("│                                   │            취소        │\n");
					printf("│   계좌: %lld \n", user->actsn);
					printf("│   은행: %s \n", user->actsb);
					printf("│   금액: %lld \n", money);
					printf("│      위 내용을 확인해주세요.      │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");

					gotoXY(36, 4);
					printf("│                        │\n");
					gotoXY(36, 5);
					printf("│                        │\n");
					gotoXY(36, 6);
					printf("│                        │\n");
				}

				break;
			}
		}
	}

	posY = 2;
	gotoXY(posX, posY);
	printf("▶");

	while (1) //작업선택
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == UP)
			{
				if (posY != 2)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY--;
					gotoXY(posX, posY);
					printf("▶ ");
				}

			}
			else if (inputKey == DOWN)
			{
				if (posY != 3)
				{
					gotoXY(posX, posY);
					printf("  ");
					posY++;
					gotoXY(posX, posY);
					printf("▶ ");
				}
			}
			else if (inputKey == ENTER)
			{
				if (posY == 2)
				{
					user->actm = user->actm - (money / 8);

					CLR
						printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│     이용해주셔서 감사합니다.      │                        │\n");
					printf("│ 정상적으로 송금을 완료하였습니다. │                        │\n");
					printf("│        거래 후 현재 잔액은        │                        │\n");
					printf("│        %lld 원 입니다.\n", user->actm);
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");
					gotoXY(36, 5);
					printf("│                        │");
					gotoXY(0, 10);

					Sleep(5000);

					CLR
						main();
				}
				else if (posY == 3)
				{
					CLR
						main();
				}
			}
		}
	}
}

/*====================================================================
						  계좌 비밀번호 입력
====================================================================*/
void act_password(struct bank_info* user)
{
	int i = 0, j = 0;
	long long pw[6] = { 0 };

	for (i = 0; i < 3; i++)
	{
		printf("┌───────────────────────────────────┬────────────────────────┐\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│   비밀번호 6자리를 입력해주세요.  │                        │\n");
		printf("│    비밀번호:                      │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("│                                   │                        │\n");
		printf("├───────────────────────────────────┤                        │\n");
		printf("│                                   │                        │\n");
		printf("│        1        2        3        │                        │\n");
		printf("│        4        5        6        │                        │\n");
		printf("│        7        8        9        │                        │\n");
		printf("│                 0                 │                        │\n");
		printf("│                                   │                        │\n");
		printf("└───────────────────────────────────┴────────────────────────┘\n");

		gotoXY(pwlr, pwud);

		for (j = 0; j < 6; j++)
		{
			while (1) //키패드
			{
				if (_kbhit())
				{
					inputKey = _getch();
					if (inputKey == RIGHT)
					{
						if (pwlr < 19)
						{
							gotoXY(pwlr + 9, pwud);
							pwlr = pwlr + 9;
						}

					}
					else if (inputKey == LEFT)
					{
						if (pwlr > 9)
						{
							gotoXY(pwlr - 9, pwud);
							pwlr = pwlr - 9;
						}

					}
					else if (inputKey == DOWN)
					{
						if (pwud < 13)
						{
							gotoXY(pwlr, pwud + 1);
							pwud = pwud + 1;
						}

					}
					else if (inputKey == UP)
					{
						if (pwud > 10)
						{
							gotoXY(pwlr, pwud - 1);
							pwud = pwud - 1;
						}

					}
					else if (inputKey == ENTER)
					{
						if ((pwlr == 9) && (pwud == 10)) //1
						{
							gotoXY(15 + j, 4);
							printf("1");
							pw[j] = 1;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 18) && (pwud == 10)) //2
						{
							gotoXY(15 + j, 4);
							printf("2");
							pw[j] = 2;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 27) && (pwud == 10)) //3
						{
							gotoXY(15 + j, 4);
							printf("3");
							pw[j] = 3;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 9) && (pwud == 11)) //4
						{
							gotoXY(15 + j, 4);
							printf("4");
							pw[j] = 4;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 18) && (pwud == 11)) //5
						{
							gotoXY(15 + j, 4);
							printf("5");
							pw[j] = 5;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 27) && (pwud == 11)) //6
						{
							gotoXY(15 + j, 4);
							printf("6");
							pw[j] = 6;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 9) && (pwud == 12)) //7
						{
							gotoXY(15 + j, 4);
							printf("7");
							pw[j] = 7;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 18) && (pwud == 12)) //8
						{
							gotoXY(15 + j, 4);
							printf("8");
							pw[j] = 8;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 27) && (pwud == 12)) //9
						{
							gotoXY(15 + j, 4);
							printf("9");
							pw[j] = 9;
							gotoXY(pwlr, pwud);
							break;
						}
						else if ((pwlr == 18) && (pwud == 13)) //0
						{
							gotoXY(15 + j, 4);
							printf("0");
							pw[j] = 0;
							gotoXY(pwlr, pwud);
							break;
						}
					}
				}
			}
		}

		if ((pw[0] == user->actpw[0]) && (pw[1] == user->actpw[1]) && (pw[2] == user->actpw[2]) && (pw[3] == user->actpw[3]) && (pw[4] == user->actpw[4]) && (pw[5] == user->actpw[5]))
		{
			return;
		}
		else
		{
			CLR

				printf("┌───────────────────────────────────┬────────────────────────┐\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│    비밀번호가 바르지 않습니다.    │                        │\n");
			printf("│   다시 입력해주세요.  ( %d / 3 )   │                        │\n", i + 1);
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("├───────────────────────────────────┤                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("│                                   │                        │\n");
			printf("└───────────────────────────────────┴────────────────────────┘\n");

			Sleep(2000);
			CLR

				if (i == 2)
				{
					printf("┌───────────────────────────────────┬────────────────────────┐\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│    비밀번호를 3회 틀리셨습니다.   │                        │\n");
					printf("│        처음으로 돌아갑니다.       │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("├───────────────────────────────────┤                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("│                                   │                        │\n");
					printf("└───────────────────────────────────┴────────────────────────┘\n");
					Sleep(5000);

					CLR
						main();
				}
		}
	}
	
}

/*====================================================================
							 화살표 이동
====================================================================*/
void gotoXY(int posX, int posY) //커서 이동함수
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = posX;
	pos.Y = posY;
	SetConsoleCursorPosition(handle, pos);
}