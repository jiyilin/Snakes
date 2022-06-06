#pragma once
#include<iostream>
#include<Windows.h>
#pragma warning(disable : 4996) 

typedef struct Location
{
	int x;
	int y;
	int eval;
	Location* next;
	Location* before;
}Location;


void Bar();
void Start();
void Print();
int CollisionText(Location* lock); //死了（0）；吃到食物（2）；继续（1）；
int Leave(int keyboard);           //上（输入8）；下（输入2）；左（输入4）；右（输入6）；
								   //死了（0）；继续（1）;吃了（2）；
void Food();
void Input();
void HideCursor();