#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ENTER 13 //縛攪酈
#define UP 72 //嶺薹 寞щ酈
#define DOWN 80 //嬴概薹 寞щ酈
#define RIGHT 77 //螃艇薹 寞щ酈
#define LEFT 75 //豭薹寞щ酈
#define CLR system("cls"); //�飛� 雖辦晦

int inputKey; //酈 盪濰
int pwlr = 9; //酈寡萄 謝辦
int pwud = 10; //酈ぬ萄 嬪嬴楚

void gotoXY(int posX, int posY);
void input_card(struct bank_info* user); //蘋萄 塽 鱔濰 鳶殮
void input_money(struct bank_info* user); //殮旎
void with_money(struct bank_info* user); //轎旎
void check_money(struct bank_info* user); //啗謝�挫�
void remit_money(struct bank_info* user); //歎旎
void remit_money_nact(struct bank_info* user); //歎旎縑憮 啗謝廓�� 殮溘
void remit_money_rec(struct bank_info* user); //歎旎縑憮 譆斬 歎旎跡煙
void act_password(struct bank_info* user); //啗謝 綠塵廓�� 殮溘


struct bank_info //餌辨濠 薑爾
{
	char* name; //檜葷
	long long* actm; //詭檣啗謝 濤堅
	long long* acts; //憮粽啗謝 濤堅
	int loginpw[4]; //煎斜檣 綠塵廓��
	int actpw[6]; //啗謝 綠塵廓��
	long long actsn; //憮粽啗謝廓��
	char* actsb; //憮粽啗謝擎ч
};

struct bank_info bank = { "噢雒雒", 6540000, 246000, {4, 3, 2, 1}, {6, 5, 4, 3, 2, 1}, 1972112131028, "措團擎ч" };

//int main(void)
//{
//	int posX = 47, posY = 2;
//
//	input_card(&bank);
//
//	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
//	printf("弛                                   弛                        弛\n");
//	printf("弛     橫憮螃撮蹂 %s 堅偌椒!     弛             殮旎       弛\n", bank.name);
//	printf("弛   錳ж衛朝 晦棟擊 摹鷗п輿撮蹂.   弛             轎旎       弛\n");
//	printf("弛                                   弛             蕨旎 褻��  弛\n");
//	printf("弛                                   弛             歎旎       弛\n");
//	printf("弛                                   弛             謙猿       弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("弛                                   弛                        弛\n");
//	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
//
//	gotoXY(posX, posY);
//	printf("Ⅱ");
//
//
//	while (1) //濛機摹鷗
//	{
//		if (_kbhit())
//		{
//			inputKey = _getch();
//
//			if (inputKey == UP)
//			{
//				if (posY != 2)
//				{
//					gotoXY(posX, posY);
//					printf("  ");
//					posY--;
//					gotoXY(posX, posY);
//					printf("Ⅱ ");
//				}
//
//			}
//			else if (inputKey == DOWN)
//			{
//				if (posY != 6)
//				{
//					gotoXY(posX, posY);
//					printf("  ");
//					posY++;
//					gotoXY(posX, posY);
//					printf("Ⅱ ");
//				}
//
//			}
//			else if (inputKey == ENTER)
//			{
//				if (posY == 2)
//				{
//					input_money(&bank);
//				}
//				else if (posY == 3)
//				{
//					with_money(&bank);
//				}
//				else if (posY == 4)
//				{
//					check_money(&bank);
//				}
//				else if (posY == 5)
//				{
//					remit_money(&bank);
//				}
//				else if (posY == 6)
//				{
//					CLR
//						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛     檜辨п輿敷憮 馬餌м棲棻.      弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("弛                                   弛                        弛\n");
//					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
//					Sleep(5000);
//
//					CLR
//						main();
//				}
//			}
//		}
//	}
//}

/*====================================================================
							蘋萄/鱔濰 檣衝
====================================================================*/
void input_card(struct bank_info* user)
{
	srand(time(NULL));
	long long pw[4] = { 0 };
	int roadtime = (rand() % 5000) + 1500;
	int j;

	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛     蘋萄釭 鱔濰擊 鳶殮п輿撮蹂.   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

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

	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛        鱔濰擊 檗堅氈蝗棲棻...     弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	Sleep(roadtime);
	CLR

		for (int i = 0; i < 5; i++)
		{
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛   綠塵廓�� 4濠葬蒂 殮溘п輿撮蹂.  弛                        弛\n");
			printf("弛    綠塵廓��:                      弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛        1        2        3        弛                        弛\n");
			printf("弛        4        5        6        弛                        弛\n");
			printf("弛        7        8        9        弛                        弛\n");
			printf("弛                 0                 弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

			gotoXY(pwlr, pwud);

			for (j = 0; j < 4; j++)
			{
				while (1) //酈ぬ萄
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

					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛    綠塵廓�ㄟ� 夥腦雖 彊蝗棲棻.    弛                        弛\n");
				printf("弛   棻衛 殮溘п輿撮蹂.  ( %d / 5 )   弛                        弛\n", i + 1);
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

				Sleep(2000);
				CLR
			}
		}

	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛    綠塵廓�ㄧ� 5�� ぎ葬樟蝗棲棻.   弛                        弛\n");
	printf("弛        籀擠戲煎 給嬴骨棲棻.       弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	Sleep(5000);

	CLR
		main();
}

/*====================================================================
								殮旎
====================================================================*/
void input_money(struct bank_info* user)
{
	int posX = 47, posY = 2, input = 0;
	long long money = 0;

	CLR

		act_password(user);

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                殮旎               弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛   殮旎ж褒 旎擋擊 殮溘п輿撮蹂.   弛                        弛\n");
	printf("弛    旎擋:                          弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoXY(11, 5);
	scanf("%lld", &money);

	CLR
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛       ⑷旎擊 撮堅氈蝗棲棻.        弛                        弛\n");
	printf("弛       濡衛虜 晦棻溥輿撮蹂.        弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	Sleep(5000);

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                殮旎               弛             �挫�       弛\n");
	printf("弛                                   弛             鏃模       弛\n");
	printf("弛        旎擋擊 �挫恉媮祤撚�.       弛                        弛\n");
	printf("弛              %lld 錳\n", money);
	printf("弛 嬪 頂辨擊 �挫恉牮簸� 蜃戲衛賊 �挫峖�                        弛\n");
	printf("弛 ぎ萵 唳辦縑朝 鏃模蒂 揚楝輿撮蹂.  弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoXY(36, 5);
	printf("弛                        弛");

	gotoXY(posX, posY);
	printf("Ⅱ");

	while (1) //濛機摹鷗
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
					printf("Ⅱ ");
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
					printf("Ⅱ ");
				}

			}
			else if (inputKey == ENTER)
			{
				CLR
					if (posY == 2)
					{
						user->actm = user->actm + (money / 8);

						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("弛     檜辨п輿敷憮 馬餌м棲棻.      弛                        弛\n");
						printf("弛        剪楚 �� ⑷營 濤擋擎        弛                        弛\n");
						printf("弛        %lld 錳 殮棲棻.\n", user->actm);
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("弛                                   弛                        弛\n");
						printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

						gotoXY(36, 5);
						printf("弛                        弛");
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
								轎旎
====================================================================*/
void with_money(struct bank_info* user)
{
	long long money = 0;

	CLR

		act_password(user);

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                轎旎               弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛   轎旎ж褒 旎擋擊 殮溘п輿撮蹂.   弛                        弛\n");
	printf("弛    旎擋:                          弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	gotoXY(11, 5);
	scanf("%lld", &money);

	if (user->actm < money)
	{
		CLR
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                轎旎               弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛         濤擋檜 睡褶м棲棻.        弛                        弛\n");
		printf("弛        籀擠戲煎 給嬴骨棲棻.       弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		Sleep(5000);

		CLR
			main();
	}
	else if (money < 1000)
	{
		CLR
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                轎旎               弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛  譆模 轎旎 旎擋縑 嘐纂雖 彊蝗棲棻.弛                        弛\n");
		printf("弛        籀擠戲煎 給嬴骨棲棻.       弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		Sleep(5000);

		CLR
			main();
	}
	else if (user->actm >= money)
	{
		CLR
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛       ⑷旎擊 遽綠醞殮棲棻.        弛                        弛\n");
		printf("弛       濡衛虜 晦棻溥輿撮蹂.        弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		Sleep(3000);

		user->actm = user->actm - (money / 8);

		CLR
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                轎旎               弛           Ⅱ �挫�      弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛    ⑷旎擊 穫晦褐 �� �挫庣鶳偯�    弛                        弛\n");
		printf("弛            揚楝輿撮蹂.            弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

		while (1) //濛機摹鷗
		{
			if (_kbhit())
			{
				inputKey = _getch();
				if (inputKey == ENTER)
				{
					CLR
						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛     檜辨п輿敷憮 馬餌м棲棻.      弛                        弛\n");
					printf("弛        剪楚 �� ⑷營 濤擋擎        弛                        弛\n");
					printf("弛        %lld 錳 殮棲棻.\n", user->actm);
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

					gotoXY(36, 5);
					printf("弛                        弛");
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
							 啗謝 �挫�
====================================================================*/
void check_money(struct bank_info* user)
{
	CLR

		act_password(user);

	CLR
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛              啗謝 �挫�            弛            Ⅱ �挫�     弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛    ⑷營濤擋擎 %lld 錳 殮棲棻.\n", user->actm);
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoXY(36, 4);
	printf("弛                        弛");
	gotoXY(0, 7);

	while (1) //濛機摹鷗
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
								歎旎
====================================================================*/
void remit_money(struct bank_info* user)
{
	int posX = 45, posY = 2;

	CLR

		act_password(user);

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                歎旎               弛           啗謝殮溘     弛\n");
	printf("弛                                   弛           譆斬爾魚啗謝 弛\n");
	printf("弛    歎旎й 啗謝蒂 摹鷗п輿撮蹂.    弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoXY(posX, posY);
	printf("Ⅱ");

	while (1) //濛機摹鷗
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
					printf("Ⅱ ");
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
					printf("Ⅱ ");
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
						  歎旎縑憮 啗謝 殮溘
====================================================================*/
void remit_money_nact(struct bank_info* user)
{
	int posX = 45, posY = 2, pw = 0, i = 0;
	long long  act = 0, money = 0;

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛  啗謝廓�ㄧ� 殮溘п輿撮蹂. (-橈檜) 弛                        弛\n");
	printf("弛    啗謝廓��:                      弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	gotoXY(15, 4);
	scanf("%lld", &act);

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                歎旎               弛            KDB骯機擎ч 弛\n");
	printf("弛                                   弛            IBK晦機擎ч 弛\n");
	printf("弛    啗謝曖 擎ч擊 摹鷗п輿撮蹂.    弛            KB措團擎ч  弛\n");
	printf("弛                                   弛            ж釭擎ч    弛\n");
	printf("弛                                   弛            辦葬擎ч    弛\n");
	printf("弛                                   弛            褐и擎ч    弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣            MG億葆擊旎堅弛\n");
	printf("弛                                   弛            SC薯橾擎ч  弛\n");
	printf("弛                                   弛            и措噢じ擎ч弛\n");
	printf("弛                                   弛            NH堯⑺擎ч  弛\n");
	printf("弛                                   弛            熱⑺擎ч    弛\n");
	printf("弛                                   弛            渠掘擎ч    弛\n");
	printf("弛                                   弛            睡骯擎ч    弛\n");
	printf("弛                                   弛            惜輿擎ч    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoXY(posX, posY);
	printf("Ⅱ");

	while (1) //濛機摹鷗
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
					printf("Ⅱ ");
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
					printf("Ⅱ ");
				}
			}
			else if (inputKey == ENTER)
			{
				CLR

					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                歎旎               弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛   歎旎ж褒 旎擋擊 殮溘п輿撮蹂.   弛                        弛\n");
				printf("弛    旎擋:                          弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
				gotoXY(11, 5);
				scanf("%lld", &money);

				if (user->actm < money)
				{
					CLR
						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                歎旎               弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛         濤擋檜 睡褶м棲棻.        弛                        弛\n");
					printf("弛        籀擠戲煎 給嬴骨棲棻.       弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
					Sleep(5000);

					CLR
						main();
				}
				else
				{
					CLR

						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                歎旎               弛            �挫�        弛\n");
					printf("弛                                   弛            鏃模        弛\n");
					printf("弛   殮溘ж褐 薑爾蒂 �挫恉媮祤撚�.   弛                        弛\n");
					printf("弛   啗謝: %lld \n\n", act);
					printf("弛   旎擋: %lld \n", money);
					printf("弛      嬪 頂辨擊 �挫恉媮祤撚�.      弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

					gotoXY(36, 5);
					printf("弛                        弛\n");
					gotoXY(36, 7);
					printf("弛                        弛\n");

					switch (posY)
					{
					case 2:
						gotoXY(0, 6);
						printf("弛   擎ч: KDB骯機擎ч               弛                        弛\n");
						break;

					case 3:
						gotoXY(0, 6);
						printf("弛   擎ч: IBK晦機擎ч               弛                        弛\n");
						break;

					case 4:
						gotoXY(0, 6);
						printf("弛   擎ч: KB措團擎ч                弛                        弛\n");
						break;

					case 5:
						gotoXY(0, 6);
						printf("弛   擎ч: ж釭擎ч                  弛                        弛\n");
						break;

					case 6:
						gotoXY(0, 6);
						printf("弛   擎ч: 辦葬擎ч                  弛                        弛\n");
						break;

					case 7:
						gotoXY(0, 6);
						printf("弛   擎ч: 褐и擎ч                  弛                        弛\n");
						break;

					case 8:
						gotoXY(0, 6);
						printf("弛   擎ч:  MG億葆擊旎堅             弛                        弛\n");
						break;

					case 9:
						gotoXY(0, 6);
						printf("弛   擎ч: SC薯橾擎ч                弛                        弛\n");
						break;

					case 10:
						gotoXY(0, 6);
						printf("弛   擎ч: и措噢じ擎ч               弛                        弛\n");
						break;

					case 11:
						gotoXY(0, 6);
						printf("弛   擎ч: NH堯⑺擎ч                弛                        弛\n");
						break;

					case 12:
						gotoXY(0, 6);
						printf("弛   擎ч: 熱⑺擎ч                  弛                        弛\n");
						break;

					case 13:
						gotoXY(0, 6);
						printf("弛   擎ч: 渠掘擎ч                  弛                        弛\n");
						break;

					case 14:
						gotoXY(0, 6);
						printf("弛   擎ч: 睡骯擎ч                  弛                        弛\n");
						break;

					case 15:
						gotoXY(0, 6);
						printf("弛   擎ч: 惜輿擎ч                  弛                        弛\n");
						break;
					}
				}

				break;
			}
		}
	}

	posY = 2;
	gotoXY(posX, posY);
	printf("Ⅱ");

	while (1) //濛機摹鷗
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
					printf("Ⅱ ");
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
					printf("Ⅱ ");
				}
			}
			else if (inputKey == ENTER)
			{
				if (posY == 2)
				{
					user->actm = user->actm - (money / 8);

					CLR
						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛     檜辨п輿敷憮 馬餌м棲棻.      弛                        弛\n");
					printf("弛 薑鼻瞳戲煎 歎旎擊 諫猿ж艘蝗棲棻. 弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛        剪楚 �� ⑷營 濤擋擎        弛                        弛\n");
					printf("弛        %lld 錳 殮棲棻.\n", user->actm);
					printf("弛                                   弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
					gotoXY(36, 6);
					printf("弛                        弛");
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
						  歎旎縑憮 譆斬 歎旎跡煙
====================================================================*/
void remit_money_rec(struct bank_info* user)
{
	int posX = 45, posY = 2, i = 0;
	long long money = 0;

	CLR

		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                歎旎               弛            %s      弛\n", user->name);
	printf("弛                                   弛                        弛\n");
	printf("弛    剪楚й 啗謝蒂 摹鷗п輿撮蹂.    弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("弛                                   弛                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoXY(posX, posY);
	printf("Ⅱ");

	while (1)
	{
		if (_kbhit())
		{
			inputKey = _getch();

			if (inputKey == ENTER)
			{
				CLR
					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                歎旎               弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛   歎旎ж褒 旎擋擊 殮溘п輿撮蹂.   弛                        弛\n");
				printf("弛    旎擋:                          弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("弛                                   弛                        弛\n");
				printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
				gotoXY(11, 5);
				scanf("%lld", &money);

				if (user->actm < money)
				{
					CLR
						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                歎旎               弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛         濤擋檜 睡褶м棲棻.        弛                        弛\n");
					printf("弛        籀擠戲煎 給嬴骨棲棻.       弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
					Sleep(5000);

					CLR
						main();
				}
				else
				{
					CLR

						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                歎旎               弛            �挫�        弛\n");
					printf("弛                                   弛            鏃模        弛\n");
					printf("弛   啗謝: %lld \n", user->actsn);
					printf("弛   擎ч: %s \n", user->actsb);
					printf("弛   旎擋: %lld \n", money);
					printf("弛      嬪 頂辨擊 �挫恉媮祤撚�.      弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

					gotoXY(36, 4);
					printf("弛                        弛\n");
					gotoXY(36, 5);
					printf("弛                        弛\n");
					gotoXY(36, 6);
					printf("弛                        弛\n");
				}

				break;
			}
		}
	}

	posY = 2;
	gotoXY(posX, posY);
	printf("Ⅱ");

	while (1) //濛機摹鷗
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
					printf("Ⅱ ");
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
					printf("Ⅱ ");
				}
			}
			else if (inputKey == ENTER)
			{
				if (posY == 2)
				{
					user->actm = user->actm - (money / 8);

					CLR
						printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛     檜辨п輿敷憮 馬餌м棲棻.      弛                        弛\n");
					printf("弛 薑鼻瞳戲煎 歎旎擊 諫猿ж艘蝗棲棻. 弛                        弛\n");
					printf("弛        剪楚 �� ⑷營 濤擋擎        弛                        弛\n");
					printf("弛        %lld 錳 殮棲棻.\n", user->actm);
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
					gotoXY(36, 5);
					printf("弛                        弛");
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
						  啗謝 綠塵廓�� 殮溘
====================================================================*/
void act_password(struct bank_info* user)
{
	int i = 0, j = 0;
	long long pw[6] = { 0 };

	for (i = 0; i < 3; i++)
	{
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛   綠塵廓�� 6濠葬蒂 殮溘п輿撮蹂.  弛                        弛\n");
		printf("弛    綠塵廓��:                      弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("弛        1        2        3        弛                        弛\n");
		printf("弛        4        5        6        弛                        弛\n");
		printf("弛        7        8        9        弛                        弛\n");
		printf("弛                 0                 弛                        弛\n");
		printf("弛                                   弛                        弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

		gotoXY(pwlr, pwud);

		for (j = 0; j < 6; j++)
		{
			while (1) //酈ぬ萄
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

				printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛    綠塵廓�ㄟ� 夥腦雖 彊蝗棲棻.    弛                        弛\n");
			printf("弛   棻衛 殮溘п輿撮蹂.  ( %d / 3 )   弛                        弛\n", i + 1);
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("弛                                   弛                        弛\n");
			printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

			Sleep(2000);
			CLR

				if (i == 2)
				{
					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛    綠塵廓�ㄧ� 3�� ぎ葬樟蝗棲棻.   弛                        弛\n");
					printf("弛        籀擠戲煎 給嬴骨棲棻.       弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("弛                                   弛                        弛\n");
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
					Sleep(5000);

					CLR
						main();
				}
		}
	}
	
}

/*====================================================================
							 �香嚂� 檜翕
====================================================================*/
void gotoXY(int posX, int posY) //醴憮 檜翕л熱
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = posX;
	pos.Y = posY;
	SetConsoleCursorPosition(handle, pos);
}