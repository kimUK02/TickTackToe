#include<stdio.h>
#include<stdio.h>
#include<windows.h>
#include "game.h"
void PrintPick(int, int,int);
extern int board[5][5];
int flag = 0;
int cnt = 0;
void choose() {
	const int d = 1;
	int nkey = 0;
	int i = 0, j = 0;
	int x = 0, y = 0;
	while (1) {
		if (_kbhit() == 0) {
			continue;
		}
		nkey = _getch();
		//printf("%d ", nkey);
		//224 75 : left
		//224 77 : right
		//244 72 : up
		//244 80 : down
		if (nkey == 32) {
			Beep(250, 200);
			flag = 0;
			if (board[x][y] == -1) {
				board[x][y] = cnt % 2;
					cnt++;
			}
			break;
		}
		if (nkey != 224) {
			continue;
		}
		nkey = _getch();
		if (nkey == 75) {
			--x;
			if (x < 0) ++x;
			gotoxy(0, 10);
			moving_realtime(x, y);
		}
		else if (nkey == 77) {
			++x;
			if (x > 4) --x;
			gotoxy(0, 10);
			moving_realtime(x, y);
		}
		else if (nkey == 80) {
			++y;
			if (y > 4) --y;
			gotoxy(0, 10);
			moving_realtime(x, y);
		}
		else if (nkey == 72) {
			--y;
			if (y < 0) ++y;
			gotoxy(0, 10);
			moving_realtime(x, y);
		}
	}
}
void Cls() {
	gotoxy(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i < 27; i++) {
		puts("                                             ");
	}
}
void moving_realtime(int x, int y) {
	CheckWin();
	PrintPick(x, y,flag);
}
void PrintPick(int x, int y, int flag) {
	//system("cls");
	Cls();
	PrintAll(0);
	Picking(x, y);
}

void Picking(int x, int y) {
	int _x = 0, _y = 0;
			_x = x * 5 + 1;
			_x = x == 0 ? 1 : _x;
			_y = y * 5 + 1;
			for (int i = 0; i <= 3; i++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
				gotoxy(_x, _y + i);
				puts("    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
}
