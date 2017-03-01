#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 5


int read_line(char str[], int limit) {
	int ch, i = 0;
	char prev = ' ';

	while ((ch = getchar()) != '\n') {
		if (i < limit) {

			if (ch != ' ' || prev != ' ') {
				str[i] = ch;
				i++;
			}
			prev = ch;
		}
	}
	
	printf("-1의 값 : %c, %d\n", str[i - 1],i-1);
	if (str[i - 1] == ' ') {
		str[i-1] = '\0';
	}
	else {
		//printf("gg");
		str[i] = '\0';
	}
	printf("%s\n", str);
	return i;
}

//void com(char str[], int size) {
//	char newstr[BUFFER_SIZE];
//	int i=0,j=0;
//
//	while (str[i] == ' ') {
//		i++;
//	}
//
//	while (str[i] != '\0') {
//		if (str[i] != ' ') {
//			newstr[j] = str[i];
//			j++;
//			i++;
//		}
//		else {
//			if (newstr[j-1] == ' ') {
//				i++;
//			}
//			else {
//				newstr[j] = str[i];
//				i++;
//				j++;
//			}
//		}
//	}
//	
//	newstr[j] = '\0';
//	//printf("j값 : %d\n", j);
//	//printf("함수내 : %s\n", newstr);
//	strcpy(str, newstr);
//
//}

int main(void)
{
	char buffer[BUFFER_SIZE];
	
	

	while(1) {
		printf("$ ");
		read_line(buffer, BUFFER_SIZE);
	
	}
	return 0;
}

