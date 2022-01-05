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

//创建链表，内容为诗歌信息(author:李子靖)
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

//判断文件是否为空(author:陆骏凯)
int isEmpty(char *fileName) {
	FILE* file;
	if ((file = fopen(fileName, "r")) == NULL) {
		printf("文件打开失败...");
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

//以链表方式写入文件
void inputToFile(Node* head, char* method) {
	FILE* file;
	if ((file = fopen("data.in", method)) == NULL) {
		printf("文件打开失败...");
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

//1.诗歌信息录入功能：存储在文件中(author:李子靖)；
void input(){
	printf("请输入需要添加的诗歌个数...\n");
	int n;
	scanf("%d", &n);
	printf("请输入诗歌(以#为最后一行结尾)\n");
	Node* head = creat(n);
	inputToFile(head, "a");
	printf("添加成功...\n");
}

//2.诗歌信息浏览功能：从文件中读取数据，显示在显示器上(author:雍佳奇)；
void browse() {
	if (isEmpty("data.in")) {
		printf("没有诗歌");
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("文件打开失败...");
		return;
	}
	printf("诗歌如下:\n");
	char str[100];
	while (!feof(file)) {
		fgets(str, 101, file);
		if (str[0] != '#') printf("%s", str); else printf("\n");
	}
	fclose(file);
}

//3.诗歌信息查询功能：按照题目查询，查询指定诗人所有诗集，查找所有朝代诗集；
void search(char* poet, char* title) {
	if (isEmpty("data.in")) {
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("文件打开失败...");
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
			printf("诗歌如下:\n");
			printf("%s\n%s %s\n", poem.title, poem.poet, poem.dynasty);
			for (i = 0; i < poem.row - 1; i++) {
				printf("%s\n", poem.content[i]);
			}
			fclose(file);
			printf("查询完毕...\n");
			return;
		}
	}

	fclose(file);
	printf("未查询到...\n");

}

//4.诗歌信息删除功能:

//按照指定诗人的指定诗集删除(author:陆骏凯）
void deleteByPoem(char* poet, char* title) {
	if (isEmpty("data.in")) {
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("文件打开失败...");
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

//5.诗歌信息修改功能：修改信息内容(陈佳豪)；
void update(char* poet, char* title) {
	if (isEmpty("data.in")) {
		return;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("文件打开失败...");
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
			printf("请输入修改后的诗歌(以#为最后一行结尾):\n");
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
		printf("未找到诗歌...\n");
		return;
	}

	inputToFile(head, "w");
	printf("修改成功!...\n");

}


//6.诗歌信息统计功能：添加诗歌(author:赵苑峻)
int countPoetry(){
	int count = 0;//诗歌总数

	if (isEmpty("data.in")) {
		return count;
	}
	FILE* file;
	if ((file = fopen("data.in", "r")) == NULL) {
		printf("文件打开失败...");
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

//添加用户(author:陆骏凯）
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
			printf("已存在用户名\n");
			fclose(file);
			return;
		}
	}

	file = fopen("user.in", "a");
	printf("请再次输入密码...\n");
	char password[30];
	scanf("%s", password);
	if (strcmp(password, user->password) == 0){
		fprintf(file, "%s\t\t%s\n", user->name, user->password);
		fclose(file);
		printf("添加成功！....\n");
	}
	else {
		fclose(file);
		printf("第二次密码错误,是否重新添加用户？(Y/N)\n");
		getchar();//!!!!!!!
		char r;
		scanf("%c", &r);
		if (r == 'Y' || r == 'y') {
			User user;
			printf("请输入用户和密码...\n");
			scanf("%s%s", user.name, user.password);
			addUser(&user);
		}
		else {
			printf("添加失败...");
		}
	}

}

//检查用户(author:陆骏凯)
int checkUser(char* userName) {
	if (isEmpty("user.in")) {
		printf("没有用户...");
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
			printf("请输入密码....\n");
			scanf("%s", userPassword);

			if (strcmp(userPassword, password) == 0) {
				printf("登陆成功...\n");
				fclose(file);
				return 1;
			}
			else {
				int i;
				for (i = 3; i > 0; i--){
					printf("登陆失败，密码错误,还剩%d次机会,请重试...\n", i);
					printf("请输入密码....\n");
					scanf("%s", userPassword);

					if (strcmp(userPassword, password) == 0) {
						printf("登陆成功...\n");
						fclose(file);
						return 1;
					}
				}
				fclose(file);
				printf("次数用尽，登录失败！...\n");
				return 0;
			}
		}
	}

	printf("未找到用户名...\n");
	fclose(file);

}

int main() {
	int chose;
	int flag = 0;
	while (1) {
		printf("**********************诗歌管理系统**********************\n");
		printf("***************1.登录--2.添加用户--3.退出系统***************\n");
		printf("请选择...\n");
		scanf("%d", &chose);
		if (chose == 3) {
			printf("退出系统...\n");
			return 0;
		}
		switch (chose){
		case 1:
			printf("请输入用户名...\n");
			User user;
			scanf("%s", user.name);
			flag = checkUser(user.name);
			break;
		case 2:
			printf("请输入需要添加的用户名和密码...\n");
			User user1;
			scanf("%s%s", user1.name, user1.password);
			addUser(&user1);
			break;
		default:
			printf("请输入合法选项，请重试...\n");
			break;
		}

		if (chose == 1 && flag) {
			system("cls");
			break;
		}
	}

	printf("进入系统成功！...\n");
	while (1) {
		printf("**********************诗歌管理系统**********************\n");
		printf("***************1.诗歌信息录入--2.诗歌信息浏览--3.诗歌信息查询***************\n");
		printf("***************4.诗歌信息删除--5.诗歌信息修改--6.诗歌统计***************\n");
		printf("***************7.清屏--8.退出系统----------------------------------- ***************\n");
		printf("请选择...\n");
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
			printf("请输入诗人与题目...\n");
			scanf("%s%s", poem.poet, poem.title);
			search(poem.poet, poem.title);
			break;
		case 4:
			printf("请输入诗人姓名与题目...\n");
			scanf("%s%s", poem.poet, poem.title);
			deleteByPoem(poem.poet, poem.title);
			printf("删除成功...\n");
			break;
		case 5:
			printf("请输入诗人姓名与题目...\n");
			scanf("%s%s", poem.poet, poem.title);
			update(poem.poet, poem.title);
			break;
		case 6:
			printf("一共有%d首诗歌\n", countPoetry());
			break;
		case 7:
			system("cls");
			break;
		case 8:
			printf("系统退出...\n");
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