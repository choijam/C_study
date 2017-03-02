#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define CAPACITY 100
#define BUFFER_SIZE 20

/*��ȭ��ȣ�� ����� Version 1.0
���α׷��� �����ϸ� ȭ�鿡 ������Ʈ�� ����ϰ� ������� ����� ��ٸ���.
$ add John 01076769898
���ο� ����� �߰��Ѵ�.
$ find Henry
�̸����� ��ȭ��ȣ�� �˻��Ѵ�.
$ status
��ȭ��ȣ�ο� ����� ��� ����� ����Ѵ�.
$ delete Jim
��ȭ��ȣ�ο��� �����Ѵ�.
$ exit
���α׷��� �����Ѵ�*/

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

	//username, usernumber�� ���ÿ� �Ҵ�� �޸��̹Ƿ�
	//add �Լ��� return �ǰ� ���� �Ҹ��.
	//���� ������ ����� ���ڿ��� ������ �� names �迭��
	//numbers �迭�� ������ �迭�� �ּҸ� �����ؾ���.
	//������ �迭�� strdup �Լ� ������ malloc���� ���� �Ҵ��
	//�޸��̹Ƿ� add �Լ��� ����� �Ŀ��� �Ҹ����� �ʴ´�.
	

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
�߰� ����
C���� �޸� ����

-��������
�Լ��� �ܺο� ����� ������
���α׷��� ���۵� �� �޸𸮰� �Ҵ�Ǹ� ���α׷��� ����� �� ���� ����
Data section�̶�� �θ��� �޸� ������ ��ġ�Ѵ�.

-��������
�Լ��� ���ο� ����� ������
�ڽ��� ���� �Լ��� ȣ��� �� �޸𸮰� �Ҵ�Ǹ� �Լ��� return�� �� �Ҹ�ȴ�.
����(stack)�̶�� �θ��� ������ ��ġ�Ѵ�.

-���� �޸� �Ҵ�
�ƹ����� malloc���� �Լ��� ȣ���Ͽ� �ʿ��� ũ���� �޸𸮸� �Ҵ��� ���� �ִ�. 
�̰��� ���� �޸� �Ҵ��̶�� �θ���.
�������� �Ҵ�� �޸𸮴� ���̶�� �θ��� ������ ��ġ
�������� �Ҵ�� �޸𸮴� ��������� free()�Լ��� ȣ���Ͽ�
��ȯ���� �ʴ��� ��� �����ȴ�.

-�޸� ���̾ƿ�(����)
stack / heap / data section / code
*/
