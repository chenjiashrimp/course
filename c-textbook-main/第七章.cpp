#include<iostream>
#include<cstring>
using namespace std;

//�ṹ�壬�������ͣ�����ṹʱ������ռ䣬�ڴ��ܺ�
struct person {
	char name[10];
	unsigned long birthday;
	char placeofbirth[20];
}per = {"Li Ming",19821209,"Beijing"};//���Գ�ʼ��
//per�Ǹ����͵�һ������
//�ṹҲ���Թ������飬��ʽ���ƶ�ά����

int main() {
	person my;
	person* p;
	p = &my;
	p->name = "Chen";//strcpy(p->name,"Chen")���ú�������
	p->birthday = 20021010;
	p->placeofbirth = "China";

	return 0;
}


//--------------------����--------------------------//
//�������Ŀ��������ȷ�������Ҵ���ռ�Ҳ����Ҫ����
struct ActList {//��̬���ݽṹ�������ɾ�����㲻��Ҫ�����Ķ����ݣ�ֻ��Ҫ�޸�ָ�룬���Ǳ����鷳
	char ActName[20];
	char director[20];
	int Mtime;//ǰ������Ϊÿ���ڵ��Ķ���
	ActList* next;
};
ActList* head;//ͷָ��
ActList* Create() {//ָ�뺯��
	ActList* p = NULL;
	ActList* q = NULL;
	head = NULL;//����һ��ʼΪ��
	int time;
	cin >> time;
	while (time != 0) {
		p = new ActList;//����ռ��p
		p->Mtime = time;
		cin >> p->ActName >> p->director;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;//p��Ŀ�������µĽڵ㣬q�Ǳ�����һ�������߽�����
		cin >> time;
	}
	if (head != NULL)
		q->next = NULL; // ����βΪ��
	//ѭ������q=tail
	//taol->next=head;
	return head;//����ͷָ��
}

//-----------------����---------//
struct numST {
	int num;
	numST* next;
};
void insert(numST*& pHead, numST* pNode) {
	struct numST* q, * r;
	if (pHead == NULL) { pHead = pNode;return; }
	if (pNode->num <= pHead->num) {
		pNode->next = pHead;
		pHead = pNode;
		return;
	}
	r = pHead;
	q = pHead->next;
	while (q != NULL) {
		if (pNode->num > q->num) {
			r = q;
			q = q->next;
		}
		else
			break;
	}
	r->next = pNode;
	pNode->next = q;
}

//-----------------------delete-----//
void del(numST*& p, int num) {
	numST* p = NULL;
	numST* q = NULL;
	if (pHead == NULL)
		return;
	p = pHead;
	if (p->num == num) {
		pHead = p->next;
		delete p;
		return;
	}
	q = p->next;
	while (q != NULL) {
		if (q->num == num) {
			p->next = q->next;
			delete q;
			return;
		}
		if (q->num > num)
			return;
		p = q;
		q = q->next;
	}
}

//-----------------ѭ������------------------//
