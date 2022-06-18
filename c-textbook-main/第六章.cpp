#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;

int max_mul(int x) {
	if ((x - x / 2) * (x / 2) > x)
		return max_mul(x / 2) * max_mul(x - x / 2);
	else
		return x;
}
//---------------筛法-------------------//
int find_prime(int n) {
	int prime[1000] = { 0 };
	for (int i = 2;i <= n;i++)
		prime[i] = 1;//初始化
	for (int number = 3;number <= n;number++) {
		if (number % 2 == 0 && number != 2)
			prime[number] = 0;
		else {
			for (int j = 3;j <= int(sqrt(number));j += 2) {
				if (number % j == 0) {
					prime[number] = 0;
					break;
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if (prime[i] == 1)//数组下标也可以起到储存数据的作用
			cout << i << " ";
		else
			cout << i << " ";
	}
	return 0;
}//把合数与1筛选掉

//线性查找与折半查找
//数组元素有序，折半查找

int BinarySearch(int AA[], int Key, int low, int high) {
	int middle = 0;
	while (low <= high) {//终止循环条件
		middle = (low + high) / 2;
		if (AA[middle] == Key)
			return middle;
		else if (AA[middle] > Key)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;//找不到
}

//---------------冒泡排序--------//
int BubbleSort() {
	int a[1000] = { 0 };
	int n = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for(int i=1;i<n-1;i++)
		for (int j = 0;j < n - i;j++) {
			int temp = 0;
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	return 0;
}

//--------------递推-------------//
//分清楚递归和递推的区别
int fish() {
	int a[6] = { 1,1,1,1,1,1 };
	int i = 0;
	do {
		a[5] += 5;
		for (i=4;i >= 1;i--) {
			if (a[i + 1] % 4 != 0)//容易被忽略，因为从后往前
				break;
			a[i] = a[i + 1] * 5 / 4 + 1;//主要是数学问题，找关系
		}
	} while (i >= 1);
	return 0;
}

//--------------字符数组----------//
int reverse() {
	char s[] = "012345678";
	char* p = NULL;
	p = &s[8];
	do {
		cout << *p;
		p--;
	} while (p >= s);
	p = s;
	while (p) {//理解含义
		cout << *p;
		p++;
	}
	return 0;
}
char buf[5];//长度，会自动补\0
//char* itoa(int vlaue, char* string,int radix)
//返回一个指向字符串的指针，最后是进制数
int find_killer() {
	int n = 1080;
	itoa(n, buf, 10);//不需要表达式，字符串在函数中赋给buf，buf需要提前定义
	//if(buf[0]<buf[1]&&...)
	//for(int i=32;i<100;i++)
	// n=i*i 可以直接看平方数，不用看所有四位数然后排除，注意优化
	return 0;
}

int sub_str(char* a, char* b) {
	int count = 0;
	int la = strlen(a);
	int lb = strlen(b);
	for (int i = 0;i <= lb - la;i++) {//注意终止条件
		bool match = true;
		for (int j = 0;j < la;j++) {
			if (a[j] != b[i + j]) {//相当于a在b上移动
				match = false;
				break;
			}
		}
		if (match)
			count++;
	}
	return count;
}
//-------------函数跳转表
typedef void(*MenuFood)();//定义了一种新的数据类型，指向函数的指针
void food1(){}
void food2(){}
void food3(){}
void food4(){}
MenuFood p[] = { food1,food2,food3,food4 };
int Choose() {
	int choose = 0;
	do{
		cin >> choose;
		switch (choose) {
		case 1://常量表达式和表达式的类型要一致
		case 2:
		case 3:
		case 4:p[choose - 1];break;//记得break
		case 0:break;
		default:cout << "wrong" << "\n";
		}
	}while(choose!=0)
	return 0;
}

//------------字符的三种操作------//
const int maxlen = 200;
char* Substr(char* a, int start, int len) {
	char* ans = new char[maxlen];//定义一个空字符串
	for (int i = start;i < start + len;i++)
		ans[i - start] = a[i];
	ans[len] = '\0';//注意
	return ans;
}
void Insert(char* a, char* b, int pos) {
	char* ans = Substr(b, 0, pos);//0到pos-1
	strcat(ans, a);
	strcat(ans, Substr(b, pos, strlen(b)-pos));
	strcpy(b, ans);//代替
	delete ans;
}
void Delete(char* a, int start, int len) {
	char* ans = Substr(a, 0,start);
	stract(ans, Substr(a, start + len, strlen(a) - start - len));
	strcpy(a, ans);
	delete ans;
}



int main() {
	char a[8] = "beijing";//七个字符八个元素，最后‘\0’，自动补'\0'
	char b[] = "tsinghua";//系统自己补上去，但是赋值就不能整体赋值了
	int n[5] = { 1,2,3,4,5 };
	int* p = NULL;
	p = n;//数组名是常量指针（指的方向不会变，默认n[0]地址,n=&n[0]
	//用指针访问数组 *p!='\0'作为终止条件
	//数组单元是按照下标大小有序第存在连续的内存单元之中，相邻单元地址相差为1，p++相当移动一个单位，但一个单位可能占几个字节
	BubbleSort();
	return 0;

}

