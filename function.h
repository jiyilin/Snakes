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
int CollisionText(Location* lock); //���ˣ�0�����Ե�ʳ�2����������1����
int Leave(int keyboard);           //�ϣ�����8�����£�����2����������4�����ң�����6����
								   //���ˣ�0����������1��;���ˣ�2����
void Food();
void Input();
void HideCursor();