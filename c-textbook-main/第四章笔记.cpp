#include<iostream>
using namespace std;
int main() {
	char thisman = 'A';
	for (int k = 0;k < 4;k += 1) {//֮ǰû������Ҫ����
		int sum = 0;//sum����������
		thisman = 'A' + k;
		sum = (thisman != 'A') + (thisman == 'C') + (thisman == 'D') + (thisman != 'D');
		if (sum == 1)
			break;
	}
	cout << thisman << endl;
	return 0;
}
//cin>>
//if(){} else if(){}else
//if()
int main() {
	char thisman = 'A';
	int g = 0;
	for (int k = 0;k < 4;k++) {
		int sum = 0;
		if (k != 0)sum += 1;
		if (k == 2)sum += 0;
		if (k == 3)sum += 1;
		if (k != 3)sum += 1;//�൱����Ϊ�жϺ���
		if (sum == 3) { cout << char('A' + k) << endl;g = 1; }
	}
	if (g != 1) cout << "can't find" << endl;
}
int main() {
	char thisman = 'A';
	int g = 0;
	for (int k = 0;k < 4;k++) {
		if ((k != 0) + (k == 2) + (k == 3) + (k != 3) == 3) {
			cout << char('A' + k) << endl;
			g = 1;
		}
	}
}

int main() {
	//�߼������ && || ��
	// a||b ab����һ������
	// !(a&&d)ad������ͬʱ����
	//(a&&e)||(a&&f)||(e&&f)��������������������������ȻҲ������������ͬʱ������
	//(b&&c)||(!b&&!c) bcͬʱ��������ͬʱ������
	//(c&&!d)||(!c&&d)cd���ҽ���һ������
	//d||(!d&&!e)���dû��������eҲ����������
	for (int A = 0;A <= 1;A++) {
		for (int B = 0;B <= 1;B++) {
			for (int C = 0;C <= 1;C++) {
				for (int D = 0;D <= 1;D++) {
					for (int E = 0;E <= 1;E++) {
						for (int F = 0;F <= 1;F++) {
							//��Ϊ�����߲�ֹһ���������ö���ѭ��ö�٣���Ϊֻ��һ�㣬����ǰ��Ĵ�����Ҳ����ʡ��
							//��ÿ����˵�Ļ�ת��Ϊ������ԣ���������ע����д��
							
							cout<<(A==0?"����":"��")//(ex? ex:ex)
						}
					}
				}
			}
		}
	}
}
int main() {
	//����Ҫ����ѭ���ķ�����n 0-63 n�Զ����ƴ洢ֻҪ֪��n����ȷ��abcdef
	//ÿһλ���Դ���һ���ˣ��ؼ�����ΰ���λ����Ϣ��ȡ��������������λ�����
	int a, b, c, d, e, f = 0;
	for (int i = 0;i < 64;i++) {
		//�ȱ�ʾ��abcdef
		a = (i & 32) >> 5;
		b = (i & 16) >> 4;
		c = (i & 8) >> 3;
		d = (i & 4) >> 2;
		e = (i & 2) >> 1;
		f = (i & 1);
		//����ͬ�ϣ���˵�Ļ�ת��ɱ������
	}
}
//ֱ����ѭ���͵�ѭ��
int main() {
	double e = 1.0, c;
	long k = 1;
	do {
		c = 1.0;
		for (int i = 1;i <= k;i++) {
			c = c / i;
		}
		k++;
		e += c;
	}while(c>1e-10)//ֱ���ͣ�����ѭ��һ��
}