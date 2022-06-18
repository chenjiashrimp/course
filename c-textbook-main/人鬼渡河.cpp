#include<iostream>
using namespace std;

//-----------多步决策之人鬼渡河---------------//
//书本上的思路就是从“人类语言”到“计算机语言”的转变，并且把一个问题拆解成几个简单部分，分别用计算机语言表示，最后再合并
//为了充分理解解题思路还拿了一个具体过河例子来演示，这些都是我们以后学习所需要的。
void display();
void transfer_state();

struct state {
	int R;//东岸人数
	int G;//东岸鬼数
};
state s[20] = {0};
int choice[20] = { 0 };
int k;

int main() {
	transfer_state();
	display();
	return 0;
}

void transfer_state() {
	state d[6] = { (0,0),(2,0),(1,0),(1,1),(0,1),(0,2) };//数组具有储存数据的功能
	k = 1;
	s[1].G = 3;
	s[1].R = 3;
	do {
		int fx = 1;//摆渡方向
		if (k % 2 == 1)
			fx = -1;
		int i=0;
		for (i = choice[k + 1] + 1;i <= 5;i++) {//这个是在考虑第k怎么走，但是k步走完得到k+1的状态，要注意区分
			int u = s[k].R + fx * d[i].R;
			int v = s[k].G + fx * d[i].G;
			if (u > 3 || v > 3 || u < 0 || v < 0) 
				continue;
			bool AQ = (u == 3 || u == 0 || (u == 1 && v == 1) || (u == 2 && v == 2));//安全条件
			if (!AQ) continue;
			bool CHF = false;
			for (int j = k - 1;j >= 1;j -= 2)//考虑摆渡方向一致,这是要考虑重复情况
				if (s[j].R == u && s[j].G == v)//类似于过了一个周期
					CHF = true;
			if (CHF) continue;
			//什么才是正确的方案？上面总共检测了三个东西
			k = k + 1;//开始保存数据
			s[k].R = u;
			s[k].G = v;
			choice[k] = i;
			break;
		}
		if (i > 5)
			k = k - 1;//所有方案都失败了，说明从上一步就失败了，要回去，这也是为什么前面for循环i从choice[i+1]+1开始，因为起始未必是0
	} while (!(s[k].R == 0 && s[k].G == 0));
}
void display() {
	for (int i = 1;i <= k;i++)
		cout << i << ":(" << s[i].R << "," << s[i].G << ")" << endl;
}