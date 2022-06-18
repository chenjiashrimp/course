#include<iostream>
#include<cstring>
using namespace std;

//结构体，数据类型，定义结构时不分配空间，内存总和
struct person {
	char name[10];
	unsigned long birthday;
	char placeofbirth[20];
}per = {"Li Ming",19821209,"Beijing"};//可以初始化
//per是该类型的一个变量
//结构也可以构造数组，形式类似二维数组

int main() {
	person my;
	person* p;
	p = &my;
	p->name = "Chen";//strcpy(p->name,"Chen")利用函数复制
	p->birthday = 20021010;
	p->placeofbirth = "China";

	return 0;
}


//--------------------链表--------------------------//
//灵活，结点数目无需事先确定，而且储存空间也不需要连续
struct ActList {//动态数据结构，插入和删除方便不需要大量改动数据，只需要修改指针，但是遍历麻烦
	char ActName[20];
	char director[20];
	int Mtime;//前面三个为每个节点存的东西
	ActList* next;
};
ActList* head;//头指针
ActList* Create() {//指针函数
	ActList* p = NULL;
	ActList* q = NULL;
	head = NULL;//链表一开始为空
	int time;
	cin >> time;
	while (time != 0) {
		p = new ActList;//分配空间给p
		p->Mtime = time;
		cin >> p->ActName >> p->director;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;//p的目的引出新的节点，q是保留上一个，两者接起来
		cin >> time;
	}
	if (head != NULL)
		q->next = NULL; // 让链尾为空
	//循环链表q=tail
	//taol->next=head;
	return head;//返回头指针
}

//-----------------插入---------//
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

//-----------------循环链表------------------//
