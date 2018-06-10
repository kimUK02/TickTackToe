#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
#include "game.h"
#include"intro.h"
int main(){
	int mode;
	printf("choose mode with rudder.\n");
	printf("if you pick please push spacebar\n");
	mode = mode_choose();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(0, 0);
	puts("                                       ");
	puts("                                       ");
	gotoxy(0, 0);
	if (mode == 2) {
		while (1) {
			choose();
		}
	}
	if (mode == 0) {
		sin_up(); //ERROR YET :(
	}
	system("pause");
	return 0;
}
