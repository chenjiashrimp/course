#include<iostream>
#include<cmath>
using namespace std;

bool checkPrime(int);//���纯������,ע��ֺ�

int main() {
	int a = 0;
	cout << "������һ������" << endl;
	cin >> a;
	if (checkPrime(a))
		cout << a << "������" << endl;
	else
		cout << a << "��������" << endl;
	return 0;
}
bool checkPrime(int af) {
	if (af != 2 && af % 2 == 0)
		return false;
	if (af == 2)
		return true;
	if (af == 1)
		return false;
	for (int i = 3;i <= sqrt(af);i += 2) {
		if (af % i == 0) 
			return false;//��pythonһ����return��ѭ���Ͳ�������ˣ��������ý�����
	}
	return true;
}
//return () or return
//�޷��� return;
//�������ã��з���ֵ�ģ�����Ϊ���ʽ�����κο��Էŵĵط���û�з���ֵ�ģ�һ����ʵ��һϵ�в�������Ϊ���������ֶ����Ǳ��ʽ
//��ʽ������������û���ڴ浥Ԫ���������ڴ浥Ԫ�ͷţ��ֲ����������������亯���壻ʵ�ڲ���������ȷ��ֵ�ı��ʽ
//����Ҳ���Ե��ú���



