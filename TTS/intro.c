#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "intro.h"
int mode_choose() {
	int nkey = 0;
	int x = 0;
	IntroFrame();
	gotoxy(1, 8);
	puts("    SIN UP    ");
	gotoxy(1, 13);
	puts("     SIN IN     ") ;
	gotoxy(1, 19);
	puts("      GO    ");
	gotoxy(8, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {

		if (_kbhit() == 0) {
			continue;
		}
		nkey = _getch();
		//printf("%d ", nkey);
		//224 75 : LEFT
		//224 77 : RIGHT
		//244 72 : UP
		//244 80 : DOWN
		if (nkey == 32) {
			Beep(432, 300);
			return x;
		}
		if (nkey != 224) {
			continue;
		}
		nkey = _getch();
		if (nkey == 72) {
			--x;
			if (x < 0) ++x;
			pickmode(x);
		}
		else if (nkey == 80) {
			++x;
			if (x > 2) --x;
			pickmode(x);
		}

	}
}
void IntroFrame() {
	int x, y;
	for (x = 0; x <= 17; x++) {
		for (y = 3; y <= 23; y++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			gotoxy(0, 0);
			gotoxy(x, y);
			putchar(' ');
		}
	}
}
void pickmode(int x) {

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
	if (x == 0) {
		IntroFrame();
		gotoxy(1, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		puts("                ");
		gotoxy(1, 7);
		puts("     SIN UP     ");
		gotoxy(1, 8);
		puts("                ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
		gotoxy(1, 13);
		puts("     SIN IN    ");
		gotoxy(1, 19);
		puts("      GO    ");
		gotoxy(0, 0);
	}
	if (x == 1) {
		IntroFrame();
		gotoxy(1, 8);
		puts("    SIN UP      ");
		gotoxy(1, 11);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		puts("                ");
		gotoxy(1, 12);
		puts("     SIN IN     ");
		gotoxy(1, 13);
		puts("                ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
		gotoxy(1, 19);
		puts("      GO    ");
		gotoxy(0, 0);
	}
	if (x == 2) {
		IntroFrame();
		gotoxy(1, 8);
		puts("    SIN UP    ");
		gotoxy(1, 13);
		puts("     SINE IN    ");
		gotoxy(1, 17);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		puts("                ");
		gotoxy(1, 18);
		puts("       GO       ");
		gotoxy(1, 19);
		puts("                ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
		gotoxy(0, 0);
	}


}
