#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include "game.h"

#define DEBUG

int board[5][5] = {
	{ -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1 },
};

void PrintAll(flag) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			PrintColor(i, j,flag);
}

void Frame() {
	int x, y;
	for (x = 0; x <= 25; x++) {
		for (y = 0; y <= 25; y++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			gotoxy(0, 0);
			puts("      ");
			gotoxy(x, y);
			putchar(' ');
		}
	}
}
void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintColor(int x, int y, int flag) {
	const int d = 1;
	int i;
	int _x, _y;
	int color = 244;
	color = board[x][y] != -1 && board[x][y] ? 192 : 144;
	if (board[x][y] == -1) color = 244;
	gotoxy(0, 29);
	printf("collor %d", color);
	_x = x * 5 + 1;//(x % 2)
	_x = x == 0 ? 1 : _x;
	_y = y * 5 + d;

	for (i = 0; i < 4; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		gotoxy(_x, _y + i);
		puts("    ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoxy(0, 25);
	}
}
void Setting() {
	int _x = 0, _y = 0;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			_x = x * 5 + 1;
			_x = x == 0 ? 1 : _x;
			_y = y * 5 + 1;
			for (int i = 0; i <= 3; i++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
				gotoxy(_x, _y + i);
				puts("    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}
	}
}
void CheckWin() {
	int i;
	for (i = 0; i < 5; i++)
		if (board[i][0] != -1 && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4])
			PrintWin(board[i][0]);
	for (i = 0; i < 5 ;i++)
		if (board[0][i] != -1 && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i])
			PrintWin(board[0][i]);

	if (board[0][0] != -1 && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) PrintWin(board[0][0]);
	if (board[0][4] != -1 && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) PrintWin(board[0][2]);
}

void PrintWin(int color) {
	gotoxy(0, 26);
	puts("                         ");
	puts("                         ");
	puts("                         ");
	gotoxy(0, 26);
	printf("%s ½Â¸®\n", color ? "RED" : "BLUE");
	puts("                         ");
	puts("                         ");
	puts("                         ");
	puts("                         ");
	gotoxy(0, 27);
	system("pause");
	exit(0);
}