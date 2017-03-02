#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define CAPACITY 100
#define BUFFER_SIZE 20

/*전화번호부 만들기 Version 1.0
프로그램을 실행하면 화면에 프롬프트를 출력하고 사용자의 명령을 기다린다.
$ add John 01076769898
새로운 사람을 추가한다.
$ find Henry
이름으로 전화번호를 검색한다.
$ status
전화번호부에 저장된 모든 사람을 출력한다.
$ delete Jim
전화번호부에서 삭제한다.
$ exit
프로그램을 종료한다*/

char* names[CAPACITY];  /*names*/
char* numbers[CAPACITY];   /*phone numbers*/
int n = 0;			/*number of people in phone directory*/

void add();
void find();
void status();
void remove();

int main()
{
	char command[BUFFER_SIZE];

	while (1) {
		printf("$ ");
		scanf("%s", command);

		if (strcmp(command, "add") == 0)
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delete") == 0)
			remove();
		else if (strcmp(command, "exit") == 0)
			break;
	}
	return 0;
}

void add() {
	char username[BUFFER_SIZE];
	char usernumber[BUFFER_SIZE];

	scanf("%s %s", username, usernumber);

	names[n] = _strdup(username);
	numbers[n] = _strdup(usernumber);
	n++;

	//username, usernumber은 스택에 할당된 메모리이므로
	//add 함수가 return 되고 나면 소멸됨.
	//따라서 각각에 저장된 문자열을 복제한 후 names 배열과
	//numbers 배열에 복제된 배열의 주소를 저장해야함.
	//복제된 배열은 strdup 함수 내에서 malloc으로 힙에 할당된
	//메모리이므로 add 함수가 종료된 후에도 소멸하지 않는다.
	

	printf("%s was added successfully.\n", username);

	return;

}

void find() {
	char username[BUFFER_SIZE];
	scanf("%s", username);

	for (int i = 0; i < n; i++) {
		if (strcmp(username, names[i]) == 0) {
			printf("%s\n", numbers[i]);
			return;
		}
	}

	printf("No person named '%s' exists\n", username);
	return;
}

void status() {

	for (int i = 0; i < n; i++) {
		printf("%s %s\n", names[i], numbers[i]);
	}

	printf("Total %d persons.\n", n);
}

void remove() {
	char username[BUFFER_SIZE];
	scanf("%s", username);

	for (int i = 0; i < n; i++) {
		if (strcmp(username, names[i]) == 0) {
			names[i] = names[n - 1];
			numbers[i] = numbers[n - 1];
			n--;
			printf("'%s' was deleted successfully.\n", username);
			return;
		}
	}
	printf("No person named '%s' exists.\n", username);
}

/*
추가 정리
C언어에서 메모리 관리

-전역변수
함수의 외부에 선언된 변수들
프로그램이 시작될 때 메모리가 할당되며 프로그램이 종료될 떄 까지 유지
Data section이라고 부르는 메모리 영역에 위치한다.

-지역변수
함수의 내부에 선언된 변수들
자신이 속한 함수가 호출될 때 메모리가 할당되며 함수가 return될 때 소멸된다.
스택(stack)이라고 부르는 영역에 위치한다.

-동적 메모리 할당
아무때나 malloc등의 함수를 호출하여 필요한 크기의 메모리를 할당하 ㄹ수 있다. 
이것을 동적 메모리 할당이라고 부른다.
동적으로 할당된 메모리는 힙이라고 부르는 영역에 위치
동적으로 할당된 메모리는 명시적으로 free()함수를 호출하여
반환하지 않는한 계속 유지된다.

-메모리 레이아웃(구조)
stack / heap / data section / code
*/
