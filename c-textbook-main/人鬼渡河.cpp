#include<iostream>
using namespace std;

//-----------�ಽ����֮�˹�ɺ�---------------//
//�鱾�ϵ�˼·���Ǵӡ��������ԡ�������������ԡ���ת�䣬���Ұ�һ��������ɼ����򵥲��֣��ֱ��ü�������Ա�ʾ������ٺϲ�
//Ϊ�˳��������˼·������һ�����������������ʾ����Щ���������Ժ�ѧϰ����Ҫ�ġ�
void display();
void transfer_state();

struct state {
	int R;//��������
	int G;//��������
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
	state d[6] = { (0,0),(2,0),(1,0),(1,1),(0,1),(0,2) };//������д������ݵĹ���
	k = 1;
	s[1].G = 3;
	s[1].R = 3;
	do {
		int fx = 1;//�ڶɷ���
		if (k % 2 == 1)
			fx = -1;
		int i=0;
		for (i = choice[k + 1] + 1;i <= 5;i++) {//������ڿ��ǵ�k��ô�ߣ�����k������õ�k+1��״̬��Ҫע������
			int u = s[k].R + fx * d[i].R;
			int v = s[k].G + fx * d[i].G;
			if (u > 3 || v > 3 || u < 0 || v < 0) 
				continue;
			bool AQ = (u == 3 || u == 0 || (u == 1 && v == 1) || (u == 2 && v == 2));//��ȫ����
			if (!AQ) continue;
			bool CHF = false;
			for (int j = k - 1;j >= 1;j -= 2)//���ǰڶɷ���һ��,����Ҫ�����ظ����
				if (s[j].R == u && s[j].G == v)//�����ڹ���һ������
					CHF = true;
			if (CHF) continue;
			//ʲô������ȷ�ķ����������ܹ��������������
			k = k + 1;//��ʼ��������
			s[k].R = u;
			s[k].G = v;
			choice[k] = i;
			break;
		}
		if (i > 5)
			k = k - 1;//���з�����ʧ���ˣ�˵������һ����ʧ���ˣ�Ҫ��ȥ����Ҳ��Ϊʲôǰ��forѭ��i��choice[i+1]+1��ʼ����Ϊ��ʼδ����0
	} while (!(s[k].R == 0 && s[k].G == 0));
}
void display() {
	for (int i = 1;i <= k;i++)
		cout << i << ":(" << s[i].R << "," << s[i].G << ")" << endl;
}