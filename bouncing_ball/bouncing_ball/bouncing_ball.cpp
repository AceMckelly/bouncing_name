// bouncing_ball.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

bool gameOver;
int width = 20;
int height = 20;
int x, y;
enum vDirection{vSTOP=0,UP,DOWN};
enum hDirection{hSTOP=0,LEFT,RIGHT};
vDirection v;
hDirection h;

void setup(){
	system("color 1F");
	gameOver = false;
	v = UP;
	h = LEFT;
	x = width / 2;
	y = height / 2;
}

void draw(){
	system("cls");
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (j == 0)
				cout << "#";
			if (i == y&&j == x){
				cout << "@acemckelly";
				j = j + 10;
			}
			else
				cout << " ";
			

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
}

void logic(){
	switch (v){
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}

	switch (h){
	case UP:
		y--;
		break;
	case DOWN:
		y=y+2;
		break;
	}

	if (y == 0){
		h = RIGHT;
	}

	if (x == 0){
		v = DOWN;
	}

	if (y == height){
		h = LEFT;
	}

	if (x == width-10){
		v = UP;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setup();
	while(!gameOver){
		draw();
		logic();	
		Sleep(50);
	}
	return 0;
}

