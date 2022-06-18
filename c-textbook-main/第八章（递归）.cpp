#include<iostream>
using namespace std;
//递归与递推，递推的效率更好，但有时候递推的关系式不容易找到，而递归的可读性比较强，容易理解

//-----------计算组合数C(m,n)----------//
//从m中找n
int Cmn(int m, int n) {
	if (m < 0 || n < 0 || m < n)
		return 0;
	if (m == n)
		return 1;
	if (n == 1)
		return 1;
	return Cmn(m - 1, n) + Cmn(m - 1, n - 1);
}
//----------------Quick Sort----------//
void sort(int array[], int zz, int yy) {
	int z, y, k;
	if (zz < yy) {
		z = zz;y = yy;k = array[z];
		do {
			while ((z < y) && (array[y] > k))
				y--;
			if (z < y) {
				array[z] = array[y];
				z++;
			}
			while ((z < y) && (array[z] < k))
				z++;
			if (z < y) {
				array[y] = array[z];
				y--;
			}
		} while (z != y);
		array[z] = k;
		sort(array, zz, z - 1);
		sort(array, z + 1, yy);
	}
}
//-----------数字旋转方针-------//
#define N 9
int P[N][N];
void Fill(int number, int begin, int size) {//左上角数字，左上角坐标，区域大小
	if (size == 0)
		return;
	if (size == 1) {
		P[begin][begin] = number;
		return;
	}
	int i = 0;int h = begin;int v = begin;//初始坐标
	P[h][v] = number;
	number++;
	for (int i = 0;i < size - 1;i++) {
		h++;
		P[h][v] = number;
		number++;
	}
	for (i = 0;i < size - 1;i++) {
		v++;
		P[h][v] = number;
		number++;
	}
	for (i = 0;i < size - 1;i++) {
		h--;
		P[h][v] = number;
		number++;
	}
	for (int i = 0;i < size - 2;i++) {
		v--;
		P[h][v] = number;
		number++;
	}
	Fill(number, v, size - 2);
}


//--------------下楼问题----------------//
int take[99] = { 0 };
int num = 0;
void Try(int i, int s) {//第i级台阶，从上到下走第s步
	int j = 0;
	for (j = 3;j > 0;j--) {
		if(i<j){}
		else {
			take[s] = j;
			if (i == j) {
				num++;
			}
			else
				Try(i - j, s + 1);
		}
	}
}
//-------------跳马问题----------//
const int TARGETX = 8;
const int TARGETY = 4;
const int MAXSTEP = 9;
int num = 0;
int path[MAXSTEP][2];
int dx[] = { 0,1,2,3,1 };
int dy[] = { 0,2,1,-1,-2 };
int mk[MAXSTEP];
void Jump(int x, int y, int step) {
	for (int k = 1;k <= 4;k += 1) {
		int x1 = x + dx[k];
		int y1 = y + dy[k];
		bool t1 = (x1 >= 0) && (x1 <= TARGETX);
		bool t2 = (y1 >= 0) && (y1 <= TARGETY);
		bool t3 = (x1 == TARGETX) && (y1 != TARGETY);
		bool t4 = (x1 == TARGETX) && (y1 == TARGETY);

		if (t1 && t2 && !t3) {//貌似不可能出现y到了但是x未到的情况
			path[step][0] = x1;
			path[step][1] = y1;
			mk[step] = k;
			if (t4)
				num++;//然后就是一系列输出
			else
				Jump(x1, y1, step + 1);
		}
	}
}

//------------------分书---------------------//
int take[5], n = 0;
int like[5][5] = { {0,0,1,1,0},{1,1,0,0,1},{0,1,1,0,1},{0,0,0,1,0},{0,1,0,0,1} };
int book[5] = { 0,0,0,0,0 };
void TryBook(int i) {
	for (int j = 0;j < 5;j++) {
		if (book[j] == 0 && like[i][j] == 1) {
			take[i] = j;
			book[j] = 1;
			if (i == 4)
				num++;//还是输出方案
			else
				TryBook(i + 1);
			book[j] = 0;//标记要记得更新
		}
	}
}

//--------------------八皇后------------------//
const int Normalize = 9;
int Num;
int Q[9];
bool C[9];
bool L[17];
bool R[17];
void Queen(int i) {
	for (int j = 1;j <= 8;j++) {
		if (C[j] && L[i - j + Normalize] && R[i + j]) {
			Q[i] = j;
			C[j] = false;
			L[i - j + Normalize] = false;
			R[i + j] = false;
			if (i < 8)
				Queen(i + 1);
			else
				Num++;//又是输出
			C[j] = true;
			L[i - j + Normalize] = true;
			R[i + j] = true;
		}
	}
}
int main() {
	
	return 0;
}
