/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct poem {
	char title[20];
	char dynasty[10];
	char poet[20];
	char content[100][100];
	int row;

}Poem;

typedef struct user {
	char name[30];
	char password[30];
}User;

typedef struct Node {
	Poem poem;
	struct Node* next;
}Node;

//������������Ϊʫ����Ϣ(author:���Ӿ�)
Node* creat(int n){
	Node* head, *node, *end;
	head = (Node*)malloc(sizeof(Node));
	end = head;
	int i;
	for (i = 0; i < n; i++)
	{
		node = (Node*)malloc(sizeof(Node));
		scanf("%s", node->poem.title);
		scanf("%s ", node->poem.poet);
		scanf("%s", node->poem.dynasty);
		char content[100];
		int i = 0;
		while (1) {

			scanf("%s", content);
			if (content[0] != '#') {
				strcpy(node->poem.content[i], content);
				i++;
			}
			else {
				break;
			}
		}
		node->poem.row = i + 1;
		strcpy(node->poem.content[i], "#");

		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

//�ж��ļ��Ƿ�Ϊ��(author:½����)
int isEmpty(char *fileName) {
	FILE* file;
	if ((file = fopen(fileName, "r")) == NULL) {
		printf("�ļ���ʧ��...");
		return 0;
	}

	char ch = fgetc(file);
	fclose(file);
	if (ch == EOF){
		return 1;
	}
	else{
		return 0;
	}
}

//������ʽд���ļ�
void inputToFile(Node* head, char* method) {
	FILE* file;
	if ((file = fopen("data.in", method)) == NULL) {
		printf("�ļ���ʧ��...");
		return;
	}
	if (!isEmpty("data.in")) {
		fprintf(file, "\n");
	}

	Node* cur = head->next;
	int count = 1;
	while (cur != NULL) {
		if (count == 1) {
			fprintf(file, "%s\n", cur->poem.title);
		}
		else {
			fprintf(file, "\n%s\n", cur->poem.title);
		}
		fprintf(file, "%s ", cur->poem.poet);
		fprintf(file, "%s\n", cur->poem.dynasty);
		int i;
		for (i = 0; i < cur->poem.row; i++) {
			if (i == cur->poem.row - 1) {
				fprintf(file, "%s", cur->poem.content[i]);
			}
			else {
				fprintf(file, "%s\n", cur->poem.content[i]);
			}

		}
		count++;
		cur = cur->next;
	}
	fclose(file);
}

//1.ʫ����Ϣ¼�빦�ܣ��洢���ļ���(author:���Ӿ�)��
void input(){
	printf("��������Ҫ��ӵ�ʫ�����...\n");
	int n;
	scanf("%d", &n);
	printf("������ʫ��(��#Ϊ���һ�н�β)\n");
	Node* head = creat(n);
	inputToFile(head, "a");
	printf("��ӳɹ�...\n");
}

//2.ʫ����Ϣ������ܣ����ļ��ж�ȡ���ݣ���ʾ����ʾ����(author:Ӻ����)��
void browse() {
	if (isEmpty("data.in")) {
		printf("û��ʫ��");
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("�ļ���ʧ��...");
		return;
	}
	printf("ʫ������:\n");
	char str[100];
	while (!feof(file)) {
		fgets(str, 101, file);
		if (str[0] != '#') printf("%s", str); else printf("\n");
	}
	fclose(file);
}

//3.ʫ����Ϣ��ѯ���ܣ�������Ŀ��ѯ����ѯָ��ʫ������ʫ�����������г���ʫ����
void search(char* poet, char* title) {
	if (isEmpty("data.in")) {
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("�ļ���ʧ��...");
		return;
	}

	while (!feof(file)) {

		Poem poem;
		fscanf(file, "%s%s %s", poem.title, poem.poet, poem.dynasty);
		char content[100];
		int i = 0;
		while (1) {

			fscanf(file, "%s", content);
			if (content[0] != '#') {
				strcpy(poem.content[i], content);
				i++;
			}
			else {
				break;
			}
		}
		poem.row = i + 1;
		strcpy(poem.content[i], "#");
		if (strcmp(title, poem.title) == 0 && strcmp(poet, poem.poet) == 0) {
			printf("ʫ������:\n");
			printf("%s\n%s %s\n", poem.title, poem.poet, poem.dynasty);
			for (i = 0; i < poem.row - 1; i++) {
				printf("%s\n", poem.content[i]);
			}
			fclose(file);
			printf("��ѯ���...\n");
			return;
		}
	}

	fclose(file);
	printf("δ��ѯ��...\n");

}

//4.ʫ����Ϣɾ������:

//����ָ��ʫ�˵�ָ��ʫ��ɾ��(author:½������
void deleteByPoem(char* poet, char* title) {
	if (isEmpty("data.in")) {
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("�ļ���ʧ��...");
		return;
	}

	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node* cur = head;
	while (!feof(file)) {

		Node* node = (Node*)malloc(sizeof(Node));
		node->next = NULL;
		Poem poem;
		fscanf(file, "%s%s %s", poem.title, poem.poet, poem.dynasty);
		char content[100];
		int i = 0;
		while (1) {

			fscanf(file, "%s", content);
			if (content[0] != '#') {
				strcpy(poem.content[i], content);
				i++;
			}
			else {
				break;
			}
		}
		poem.row = i + 1;
		strcpy(poem.content[i], "#");
		if (strcmp(title, poem.title) != 0 || strcmp(poet, poem.poet) != 0) {

			node->poem = poem;
			cur->next = node;
			cur = cur->next;
		}


	}

	fclose(file);

	inputToFile(head, "w");

}

//5.ʫ����Ϣ�޸Ĺ��ܣ��޸���Ϣ����(�¼Ѻ�)��
void update(char* poet, char* title) {
	if (isEmpty("data.in")) {
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("�ļ���ʧ��...");
		return;
	}

	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node* cur = head;
	int flag = 0;
	while (!feof(file)) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->next = NULL;
		Poem poem;
		fscanf(file, "%s%s %s", poem.title, poem.poet, poem.dynasty);
		char content[100];

		if (strcmp(poet, poem.poet) == 0 && strcmp(title, poem.title) == 0) {
			flag = 1;
			char str[100];
			do {
				fgets(str, 100, file);
			} while (str[0] != '#');
			printf("�������޸ĺ��ʫ��(��#Ϊ���һ�н�β):\n");
			scanf("%s", poem.title);
			scanf("%s ", poem.poet);
			scanf("%s", poem.dynasty);

			int i = 0;
			while (1) {

				scanf("%s", content);
				if (content[0] != '#') {
					strcpy(poem.content[i], content);
					i++;
				}
				else {
					break;
				}
			}
			poem.row = i + 1;
			strcpy(poem.content[i], "#");

		}
		else {
			int i = 0;
			while (1) {

				fscanf(file, "%s", content);
				if (content[0] != '#') {
					strcpy(poem.content[i], content);
					i++;
				}
				else {
					break;
				}
			}
			poem.row = i + 1;
			strcpy(poem.content[i], "#");
		}

		node->poem = poem;
		cur->next = node;
		cur = cur->next;

	}

	fclose(file);

	if (flag == 0) {
		printf("δ�ҵ�ʫ��...\n");
		return;
	}

	inputToFile(head, "w");
	printf("�޸ĳɹ�!...\n");

}


//6.ʫ����Ϣͳ�ƹ��ܣ����ʫ��(author:��Է��)
int countPoetry(){
	int count = 0;//ʫ������

	if (isEmpty("data.in")) {
		return count;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("�ļ���ʧ��...");
		return 0;
	}
	char str[99];
	while (!feof(file)) {
		fgets(str, 100, file);
		if (str[0] == '#') {
			++count;
		}
	}
	fclose(file);
	return count;
}

//����û�(author:½������
void addUser(User *user){
	FILE *file;
	if ((file = fopen("user.in", "r")) == NULL){
		printf("erro!");
		return;
	}

	while (!feof(file)){
		char name[20];
		char password[30];
		fscanf(file, "%s\t\t%s", name, password);
		if (strcmp(user->name, name) == 0){
			printf("�Ѵ����û���\n");
			fclose(file);
			return;
		}
	}

	file = fopen("user.in", "a");
	printf("���ٴ���������...\n");
	char password[30];
	scanf("%s", password);
	if (strcmp(password, user->password) == 0){
		fprintf(file, "%s\t\t%s\n", user->name, user->password);
		fclose(file);
		printf("��ӳɹ���....\n");
	}
	else {
		fclose(file);
		printf("�ڶ����������,�Ƿ���������û���(Y/N)\n");
		getchar();//!!!!!!!
		char r;
		scanf("%c", &r);
		if (r == 'Y' || r == 'y') {
			User user;
			printf("�������û�������...\n");
			scanf("%s%s", user.name, user.password);
			addUser(&user);
		}
		else {
			printf("���ʧ��...");
		}
	}

}

//����û�(author:½����)
int checkUser(char* userName) {
	if (isEmpty("user.in")) {
		printf("û���û�...");
		return 0;
	}
	FILE* file;
	if ((file = fopen("user.in", "r")) == NULL) {
		printf("erro!");
		fclose(file);
		return 0;
	}

	while (!feof(file)) {
		char name[20];
		char password[30];
		char userPassword[30];
		fscanf(file, "%s\t\t%s", name, password);
		if (strcmp(userName, name) == 0) {
			printf("����������....\n");
			scanf("%s", userPassword);

			if (strcmp(userPassword, password) == 0) {
				printf("��½�ɹ�...\n");
				fclose(file);
				return 1;
			}
			else {
				int i;
				for (i = 3; i > 0; i--){
					printf("��½ʧ�ܣ��������,��ʣ%d�λ���,������...\n", i);
					printf("����������....\n");
					scanf("%s", userPassword);

					if (strcmp(userPassword, password) == 0) {
						printf("��½�ɹ�...\n");
						fclose(file);
						return 1;
					}
				}
				fclose(file);
				printf("�����þ�����¼ʧ�ܣ�...\n");
				return 0;
			}
		}
	}

	printf("δ�ҵ��û���...\n");
	fclose(file);

}

int main() {
	int chose;
	int flag = 0;
	while (1) {
		printf("**********************ʫ�����ϵͳ**********************\n");
		printf("***************1.��¼--2.����û�--3.�˳�ϵͳ***************\n");
		printf("��ѡ��...\n");
		scanf("%d", &chose);
		if (chose == 3) {
			printf("�˳�ϵͳ...\n");
			return 0;
		}
		switch (chose){
		case 1:
			printf("�������û���...\n");
			User user;
			scanf("%s", user.name);
			flag = checkUser(user.name);
			break;
		case 2:
			printf("��������Ҫ��ӵ��û���������...\n");
			User user1;
			scanf("%s%s", user1.name, user1.password);
			addUser(&user1);
			break;
		default:
			printf("������Ϸ�ѡ�������...\n");
			break;
		}

		if (chose == 1 && flag) {
			system("cls");
			break;
		}
	}

	printf("����ϵͳ�ɹ���...\n");
	while (1) {
		printf("**********************ʫ�����ϵͳ**********************\n");
		printf("***************1.ʫ����Ϣ¼��--2.ʫ����Ϣ���--3.ʫ����Ϣ��ѯ***************\n");
		printf("***************4.ʫ����Ϣɾ��--5.ʫ����Ϣ�޸�--6.ʫ��ͳ��***************\n");
		printf("***************7.����--8.�˳�ϵͳ----------------------------------- ***************\n");
		printf("��ѡ��...\n");
		scanf("%d", &chose);
		Poem poem;
		switch (chose) {
		case 1:
			input();
			break;
		case 2:
			browse();
			break;
		case 3:
			printf("������ʫ������Ŀ...\n");
			scanf("%s%s", poem.poet, poem.title);
			search(poem.poet, poem.title);
			break;
		case 4:
			printf("������ʫ����������Ŀ...\n");
			scanf("%s%s", poem.poet, poem.title);
			deleteByPoem(poem.poet, poem.title);
			printf("ɾ���ɹ�...\n");
			break;
		case 5:
			printf("������ʫ����������Ŀ...\n");
			scanf("%s%s", poem.poet, poem.title);
			update(poem.poet, poem.title);
			break;
		case 6:
			printf("һ����%d��ʫ��\n", countPoetry());
			break;
		case 7:
			system("cls");
			break;
		case 8:
			printf("ϵͳ�˳�...\n");
			return 0;
		}
	}
}
*/

#include <iostream>
using namespace std;
int& Add(int left, int right)
{
	int ret = left + right;
	return ret;
}
int main()
{
	int& result = Add(1, 2);
	Add(3, 4);
	Add(5, 6);
	return 0;
}