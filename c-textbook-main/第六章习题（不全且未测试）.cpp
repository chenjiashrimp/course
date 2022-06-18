#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int letter(int n) {
	int d[1000] = { 0 };
	d[1] = 1;
	for (int i = 2;i <= n;i++)
		d[i] = (n - 1) * (d[i - 1] + d[i - 2]);
	return d[n];
}

void sort(int* a,int len) {
	for (int i = 0;i < len - 1;i++) {
		int temp = a[i];
		int a_temp = i;
		for (int j = i;j < len;j++) {
			if (a[j] < temp) {
				temp = a[j];
				a_temp = j;\
			}
		}
		a[a_temp] = a[i];
		a[i] = temp;
		for (int k = 0;k < len;k++)
			cout << a[k] << " ";
		cout << endl;
	}
}

void rope() {
	int a[6] = { 0 };

}

void light(int N) {
	int a[1000] = { 0 };
	for (int i = 2;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (j % i == 0)
				a[j] = (a[j]==0);
		}
	}
	int count = 0;
	for (int i = 1;i <= N;i++)
		if (a[i])
			count++;
}

void volleyball() {
	int a[3][4] = { {0,0,0,0},{0,4,3,2},{0,5,6,1} };
	int b[7] = { 0 };
	int x = 1;
	for(int i=1;i<=2;i++)
		for (int j = 1;j <= 3;j++) {
			for (int k = 1;k <= 6;k++) {
				if (a[i][j] == k)
					continue;
				if (i == 2 && (k == 1 || k == 6))
					continue;
				if (((i == 1 && j == 3) || (i == 2 && j == 1)) && (k == 2 || k == 3))
					continue;
				if (i == 1 && j == 3) {
					b[x] = 4;
					break;
				}
				if ((k == 5 || k == 6) && ((i == 1 && j == 2) || (i == 2 && j == 2)))
					continue;
				b[x] = k;
			}
			x++;
		}
}
const int max_len = 200;
void plural(char* str) {
	char* ans = new char[max_len];
	if (str[strlen(str) - 2] == 'y') {
		str[strlen(str) - 2] = 'i';
		strcat(str, "es");
	}
	else if (str[strlen(str) - 2] == 'o' || str[strlen(str) - 2] == 's' || str[strlen(str) - 2] == 'x')
		strcat(str, "es");
	else if (str[strlen(str) - 2] == 'h')
		if (str[strlen(str) - 3] == 'c' || str[strlen(str) - 3] == 's')
			strcat(str, "es");
	else
		strcat(str, "s");
}

int f(int x) {
	while (x > 10) {
		int new_x = 1;
		while (!x) {
			if (x % 10 != 0)
				new_x *= x % 10;
			x = x / 10;
		}
		x = new_x;
	}
	return x;
}
//-----------------------------//
char buf[6];
bool plalindrome(int n) {
	_itoa_s(n, buf, 10);
	for (int i = 0;i = (strlen(buf) - 1) / 2;i++) {
		if (buf[i] != buf[strlen(buf) - 2 - i])
			return false;
	}
	return true;
}

int square_num() {
	for (int A = 32;A < 100;A++) {
		for (int i = 1;i <= 9;i++) {
			int B = 1111 * i;
			if (B > A)
				break;
			else {
				int C = A - B;
				if (C < 1000)
					break;
				else
					if (int(sqrt(C)) == sqrt(C))
						cout << A << " " << B << " " << C << endl;
			}
		}
	}
}

char a_str[4], b_str[4], c_str[4];
void three_square() {
	for (int a = 11;a <= 32;a++) {
		int A = a * a;
		itoa(A, a_str, 10);
		if (a_str[0] == a_str[1] || a_str[0] == a_str[2] || a_str[1] == a_str[2])
			continue;
		for (int b = a + 1;b <= 32;b++) {
			int B = b * b;
			itoa(B, b_str, 10);
			if (b_str[0] == b_str[1] || b_str[1] == b_str[2] || b_str[0] == b_str[2])
				continue;
			for (int c = b + 1;c < -32;c++) {
				int C = c * c;
				itoa(C, c_str, 10);
				if (c_str[0] == c_str[1] || c_str[1] == c_str[2] || c_str[0] == c_str[2])
					continue;
				strcat(a_str, b_str);
				strcat(a_str, c_str);
				int n[10] = { 0 };
				bool x = true;
				for (int i = 0;i < strlen(a_str);i++) {
					if (n[a_str[i] - '0']) {
						x = false;
						break;
					}
					n[a_str[i] - '0'] = 1;
				}
				if (x)
					cout << A << " " << B << " " << C;
			}
		}
	}
}
int main() {
	int a[5] = { 5,4,3,2,1 };
	cout << sqrt(5) << endl;
	return 0;
}