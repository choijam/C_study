#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFUER_SIZE 100

//여러개의 단어들을 포인터를 이용하여 저장하기

char * strdup(char *s) {
	char *p;
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

int main()
{
	char* words[100];
	int n = 0;
	char str[BUFFUER_SIZE];
	
	while (n<5&&scanf("%s", str) != EOF) {
		words[n] = strdup(str);
		n++;
	}

	for (int i = 0; i < 5; i++) {
		printf("%s\n", words[i]);
	}

	return 0;
}