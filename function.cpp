#include<iostream>
#include<Windows.h>
#include <conio.h>
#include<stdlib.h>
#include"function.h"
using namespace std;

Location Map[29][101];
Location *SnakeHead,*SnakeEnd;

void Bar()
{
	cout << "*================================================================*" << endl;
	cout << "||                                                              ||" << endl;
	cout << "||                             正在加载中                       ||" << endl;
	cout << "||                                                              ||" << endl;
	cout << "*================================================================*" << endl;
	int ProgressBar = 65;
	for (int i = 0; i < ProgressBar; i++)
	{
		std::cout << "█";
		Sleep(5);
	}
	cout << endl;
	system("cls");
}


void Start()
{
	for (int i = 0; i < 101; i++)
	{
		Map[0][i].eval = 4;
		Map[0][i].x = 0;
		Map[0][i].y = i;
		Map[0][i].before = NULL;
		Map[0][i].next = NULL;
		Map[28][i].eval = 4;
		Map[28][i].x = 28;
		Map[28][i].y = i;
		Map[28][i].before = NULL;
		Map[28][i].next = NULL;
	}
	for (int i = 1; i < 28; i++)
	{
		Map[i][0].eval = 5;
		Map[i][0].x = i;
		Map[i][0].y = 0;
		Map[i][0].next = NULL;
		Map[i][0].before = NULL;
		Map[i][1].eval = 5;
		Map[i][1].x = i;
		Map[i][1].y = 1;
		Map[i][1].before = NULL;
		Map[i][1].next = NULL;
		Map[i][99].eval = 5;
		Map[i][99].x = i;
		Map[i][99].y = 99;
		Map[i][99].before = NULL;
		Map[i][99].next = NULL;
		Map[i][100].eval = 5;
		Map[i][100].x = i;
		Map[i][100].y = 100;
		Map[i][100].before = NULL;
		Map[i][100].next = NULL;
		for (int j = 2; j < 99; j++)
		{
			Map[i][j].eval = 3;
			Map[i][j].x = i;
			Map[i][j].y = j;
			Map[i][j].before = NULL;
			Map[i][j].next = NULL;
		}
	}
	Map[4][3].eval = 2;
	Map[4][2].eval = 1;
	SnakeHead = &Map[4][3];
	SnakeEnd = &Map[4][2];
	SnakeHead->before = NULL;
	SnakeEnd->next = NULL;
	SnakeHead->next = SnakeEnd;
	SnakeEnd->before = SnakeHead;
}

void Print()
{
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			switch (Map[i][j].eval)
			{
			case 1:
				printf("*");
				break;
			case 2:
				printf("■");
				break;
			case 3:
				printf(" ");
				break;
			case 4:
				printf("=");
				break;
			case 5:
				printf("|");
				break;
			case 6:
				printf("0");
				break;
			}
		}
		printf("\n");
	}
}

int CollisionText(Location *lock)
{
	if (lock->eval==1 || lock->eval==4 || lock->eval==5)
	{
		return 0;
	}
	else if (lock->eval==6)
	{
		return 2;
	}
	return 1;
}

int Leave(int keyboard)
{
	switch (keyboard)
	{
	case 8:
		if (CollisionText(&Map[SnakeHead->x - 1][SnakeHead->y]) == 0)
		{
			return 0;
		}
		else if (CollisionText(&Map[SnakeHead->x - 1][SnakeHead->y]) == 1)
		{
			Map[SnakeHead->x - 1][SnakeHead->y].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x - 1][SnakeHead->y];
			Map[SnakeHead->x - 1][SnakeHead->y].before = NULL;
			Map[SnakeHead->x - 1][SnakeHead->y].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x - 1][SnakeHead->y];
			SnakeEnd->eval = 3;
			SnakeEnd = SnakeEnd->before;
		}
		else
		{
			Map[SnakeHead->x - 1][SnakeHead->y].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x - 1][SnakeHead->y];
			Map[SnakeHead->x - 1][SnakeHead->y].before = NULL;
			Map[SnakeHead->x - 1][SnakeHead->y].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x - 1][SnakeHead->y];
			return 2;
		}
		break;
	case 2:
		if (CollisionText(&Map[SnakeHead->x + 1][SnakeHead->y]) == 0)
		{
			return 0;
		}
		else if (CollisionText(&Map[SnakeHead->x + 1][SnakeHead->y]) == 1)
		{
			Map[SnakeHead->x + 1][SnakeHead->y].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x + 1][SnakeHead->y];
			Map[SnakeHead->x + 1][SnakeHead->y].before = NULL;
			Map[SnakeHead->x + 1][SnakeHead->y].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x + 1][SnakeHead->y];
			SnakeEnd->eval = 3;
			SnakeEnd = SnakeEnd->before;
		}
		else
		{
			Map[SnakeHead->x + 1][SnakeHead->y].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x + 1][SnakeHead->y];
			Map[SnakeHead->x + 1][SnakeHead->y].before = NULL;
			Map[SnakeHead->x + 1][SnakeHead->y].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x + 1][SnakeHead->y];
			return 2;
		}
		break;
	case 4:
		if (CollisionText(&Map[SnakeHead->x][SnakeHead->y-1]) == 0)
		{
			return 0;
		}
		else if (CollisionText(&Map[SnakeHead->x][SnakeHead->y-1]) == 1)
		{
			Map[SnakeHead->x][SnakeHead->y-1].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x][SnakeHead->y-1];
			Map[SnakeHead->x][SnakeHead->y-1].before = NULL;
			Map[SnakeHead->x][SnakeHead->y-1].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x][SnakeHead->y-1];
			SnakeEnd->eval = 3;
			SnakeEnd = SnakeEnd->before;
		}
		else
		{
			Map[SnakeHead->x][SnakeHead->y - 1].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x][SnakeHead->y - 1];
			Map[SnakeHead->x][SnakeHead->y - 1].before = NULL;
			Map[SnakeHead->x][SnakeHead->y - 1].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x][SnakeHead->y - 1];
			return 2;
		}
		break;
	case 6:
		if (CollisionText(&Map[SnakeHead->x][SnakeHead->y+1]) == 0)
		{
			return 0;
		}
		else if (CollisionText(&Map[SnakeHead->x][SnakeHead->y+1]) == 1)
		{
			Map[SnakeHead->x][SnakeHead->y + 1].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x][SnakeHead->y + 1];
			Map[SnakeHead->x][SnakeHead->y + 1].before = NULL;
			Map[SnakeHead->x][SnakeHead->y + 1].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x][SnakeHead->y + 1];
			SnakeEnd->eval = 3;
			SnakeEnd = SnakeEnd->before;
		}
		else
		{
			Map[SnakeHead->x][SnakeHead->y + 1].eval = 2;
			SnakeHead->eval = 1;
			SnakeHead->before = &Map[SnakeHead->x][SnakeHead->y + 1];
			Map[SnakeHead->x][SnakeHead->y + 1].before = NULL;
			Map[SnakeHead->x][SnakeHead->y + 1].next = SnakeHead;
			SnakeHead = &Map[SnakeHead->x][SnakeHead->y + 1];
			return 2;
		}
		break;
	}
	return 1;
}

void Food()
{
	int x=0, y=0;
	do
	{
		x = rand() % 28;
		y = rand() % 100;
	} while (Map[x][y].eval!=3);
	Map[x][y].eval = 6;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo;                    
	curInfo.dwSize = 1;   
	curInfo.bVisible = FALSE;         
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorInfo(handle, &curInfo);
}

void Input()
{
	char a;
	int n,key=1;
	n = 6;
	Food();
	Print();
	Sleep(150);
	system("cls");
	goto First;
	while (1)
	{
		a = getch();
		n = a - '0';
	First:
		while (1)
		{
			Print();
			Sleep(150);
			system("cls");
			if (_kbhit()!=0)
			{
				break;
			}
			else
			{
				key=Leave(n);
				if (key == 0)
				{
					goto out;
				}
				else if (key == 2)
				{
					Food();
				}
			}
		}
	}
out:
	printf("您死了\n");
}