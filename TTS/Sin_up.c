#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include "intro.h"
void sin_up() {
	int in;
	char name[256];
	FILE* fp; 
	fp = fopen("test.txt", "w+");
	fclose(fp); 
}