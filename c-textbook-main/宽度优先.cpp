#include<iostream>
using namespace std;

//----------------�������
struct qype {
	int x, y;
}queue[26];
int w[5][5];//ÿ������ֻ�ܼ�¼һ�Σ������ظ�
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
void init() {//��ʼ������
	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			w[i][j] = -1;
	w[0][0] = 0;
}
bool okjump(int x, int y) {
	return(x >= 0 && x <= 4 && y >= 0 && y <= 4 && w[x][y] == -1);
}
void BFS() {
	int head = 1;
	int tail = 1;
	queue[head].x = 0;queue[head].y = 0;//������
	int step = 0;
	int m = head;
	while (m <= tail) {//һ��һ��ĵ��ɺ����ŷ���
		int sq = tail;//��סԭ����β��
		for (int am = m;am <= sq;am++) {
			for (int k = 0;k < 8;k++) {
				int x1 = queue[am].x + dx[k];
				int y1 = queue[am].y + dy[k];
				if (okjump(x1, y1)) {
					tail++;
					queue[tail].x = x1;
					queue[tail].y = y1;
					w[x1][y1] = step + 1;
				}
			}
		}
		m = sq + 1;
		step = step + 1;
	}
}
int main() {

}