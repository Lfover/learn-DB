//#include <iostream>
//#include <windows.h>
//#include <conio.h>
//using namespace std;
//
//int len;
//struct Dot {
//	int x;
//	int y;
//	char c;
//}a[10000000];
//int vis[10000000];
//char c[5] = { 35, 36, 37, 38, 79 };
//string s = "/\\";
//int n;
//string me = "Merry Christmas ^_^ !";
//string fm = "From Mengru Li";
//
//void getcur(short int x, short int y)//移动光标函数 
//{
//	COORD pos = COORD{ x, y };//定义一个屏幕上的座标 
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(handle, pos);;
//}
//
//void goprint(int x, int y, char c) {
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
//	getcur(x, y); printf("%c", c); //getcur(0,row);//消除光标影响 
//}
//
//void del(int x, int y)
//{
//	getcur(x, y); printf(" ");
//}
//
//int main() {
//	cout << "请输入你喜欢的一个数字（10 - 17），并将窗口最大化：";
//	cin >> n;
//	cout << endl;
//	int Layer = 2 * n - 1;
//	int Space = 2 * n - 2;
//	for (int i = 1; i <= Layer; ++i) {
//		if (i & 1) {
//			for (int j = 0; j < 2 * i; j += 2) {
//				a[len].x = j + Space + 30, a[len].y = i + 5, a[len++].c = c[rand() % 5];
//			}
//			Space -= 2;
//		}
//		else {
//			int r = 0;
//			for (int j = 0; j < 2 * i; j += 2) {
//				a[len].x = j + Space + 31, a[len].y = i + 5, a[len++].c = s[r];
//				r = (r + 1) % 2;
//			}
//		}
//	}
//	for (int i = 0; i < Layer / 3 + 1; ++i) {
//		a[len].x = Layer + 29, a[len].y = i + 6 + Layer, a[len++].c = '|';
//		a[len].x = Layer + 30, a[len].y = i + 6 + Layer, a[len++].c = '|';
//	}
//	for (int i = 0; i < me.length(); ++i) {
//		a[len].x = Layer - 1 + i + 30;
//		a[len].y = Layer / 3 + 10 + Layer;
//		a[len++].c = me[i];
//	}
//	for (int i = 0; i < fm.length(); ++i) {
//		a[len].x = Layer - 1 + i + 30;
//		a[len].y = Layer / 3 + 11 + Layer;
//		a[len++].c = fm[i];
//	}
//	while (1) {
//		int i = rand() % len;
//		if ((a[i].c == '\\' || a[i].c == '/') && vis[i]) {
//			continue;
//		}
//		goprint(a[i].x, a[i].y, a[i].c);
//		vis[i] = 1;
//	}
//}


















//#include <windows.h>
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#define PI 3.14159265359
//#define T px + scale * r * cosf(theta), py + scale * r * sin(theta)
//float sx, sy;
//float sdCircle(float px, float py, float r) {
//	float dx = px - sx, dy = py - sy;
//	return sqrtf(dx * dx + dy * dy) - r;
//}
//float opUnion(float d1, float d2) {
//	return d1 < d2 ? d1 : d2;
//}
//float f(float px, float py, float theta, float scale, int n) {
//	float d = 0.0f;
//	for (float r = 0.0f; r < 0.8f; r += 0.02f)
//		d = opUnion(d, sdCircle(T, 0.05f * scale * (0.95f - r)));
//	if (n > 0)
//		for (int t = -1; t <= 1; t += 2) {
//			float tt = theta + t * 1.8f;
//			float ss = scale * 0.9f;
//			for (float r = 0.2f; r < 0.8f; r += 0.1f) {
//				d = opUnion(d, f(T, tt, ss * 0.5f, n - 1));
//				ss *= 0.8f;
//			}
//		}
//	return d;
//}
//int ribbon() {
//	float x = (fmodf(sy, 0.1f) / 0.1f - 0.5f) * 0.5f;
//	return sx >= x - 0.05f && sx <= x + 0.05f;
//}
//int main(int argc, char* argv[]) {
//	int n = argc > 1 ? atoi(argv[1]) : 3;
//	float zoom = argc > 2 ? atof(argv[2]) : 1.0f;
//	for (sy = 0.8f; sy > 0.0f; sy -= 0.02f / zoom, putchar('\n'))
//		for (sx = -0.35f; sx < 0.35f; sx += 0.01f / zoom) {
//			if (f(0, 0, PI * 0.5f, 1.0f, n) < 0.0f) {
//				if (sy < 0.1f) {
//					putchar('.');
//				}
//				else {
//					if (ribbon()) {
//						putchar('=');
//					}
//					else {
//						putchar("............................#j&o"[rand() % 32]);
//					}
//				}
//			}
//			else {
//				putchar(' ');
//			}
//		}
//	Sleep(1000);
//	printf("\n\n\n");
//	for (size_t i = 0; i < 40; i++) {
//		putchar(' ');
//	}
//	//_sleep(5000);
//	printf("Merry Christmas, baby~!\n");
//	Sleep(500);
//	for (size_t i = 0; i < 40; i++) {
//		putchar(' ');
//	}
//	printf("Never say die.\n");
//	Sleep(500);
//	for (size_t i = 0; i < 40; i++) {
//		putchar(' ');
//	}
//	printf("2021/12/24, 最爱默默的我哦~\n");
//	getchar();
//}










#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

float sx, sy;

float sdCircle(float px, float py, float r) {
	float dx = px - sx, dy = py - sy;
	return sqrtf(dx * dx + dy * dy) - r;
}

float opUnion(float d1, float d2) {
	return d1 < d2 ? d1 : d2;
}

#define T px + scale * r * cosf(theta), py + scale * r * sin(theta)

float f(float px, float py, float theta, float scale, int n) {
	float d = 0.0f;
	for (float r = 0.0f; r < 0.8f; r += 0.02f)
		d = opUnion(d, sdCircle(T, 0.05f * scale * (0.95f - r)));

	if (n > 0)
		for (int t = -1; t <= 1; t += 2) {
			float tt = theta + t * 1.8f;
			float ss = scale * 0.9f;
			for (float r = 0.2f; r < 0.8f; r += 0.1f) {
				d = opUnion(d, f(T, tt, ss * 0.5f, n - 1));
				ss *= 0.8f;
			}
		}

	return d;
}

int main(int argc, char* argv[]) {
	int n = argc > 1 ? atoi(argv[1]) : 3;
	for (sy = 0.8f; sy > 0.0f; sy -= 0.02f, putchar('\n'))
		for (sx = -0.35f; sx < 0.35f; sx += 0.01f)
			putchar(f(0, 0, PI * 0.5f, 1.0f, n) < 0 ? '*' : ' ');
	system("pause");
}
