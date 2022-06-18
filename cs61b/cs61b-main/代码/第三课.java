public class IntList {
	public int first;
	public IntList rest;/*列表可以类比为c里面的指针，构造链表*/

	public IntList(int f, IntList r) {
		first = f;
		rest = r;
	}

	/** Return the size of the list using... recursion! */
	public int size() {
		if (rest == null) {
			return 1;
		}
		return 1 + this.rest.size();
	}

	/** Return the size of the list using no recursion! */
	public int iterativeSize() {
		IntList p = this;
		int totalSize = 0;
		while (p != null) {
			totalSize += 1;
			p = p.rest;
		}
		return totalSize;
	}/*两种获得列表长度的方法*/

	/** Returns the ith item of this IntList. */
	public int get(int i) {
		if (i == 0) {
			return first;
		}
		return rest.get(i - 1);/*使用递归得到第i个数*/
	}

	public static void main(String[] args) {
		IntList L = new IntList(15, null);
		L = new IntList(10, L);/*先确定rest*/
		L = new IntList(5, L);/*这是从末尾开始构造，相比于从开头构造貌似要简单一些*/
    /*IntList L = new IntList(5, null);
*L.rest = new IntList(10, null);
*L.rest.rest = new IntList(15, null);*/

		System.out.println(L.get(100));
	}
} 


Walrus a = new Walrus(1000, 8.3);/*内存里找了一些地方以01形式存下这些数据，然后返回该存储位置的地址给a，所以a相当于指针（也即地址），box里面的指针指向这些数据*/
Walrus b;/*create a box of 64 bits first, the box stores the address*/
/*If an address is all zeros, we will represent it with null.
*A non-zero address will be represented by an arrow pointing at an object instantiation.*/
b = a;/*相当于复制指针，a b指向同一类数据*/
b.weight = 5;/*b的改变会影响a，a b本质上是一个海象*/
System.out.println(a);
System.out.println(b);
/*9th reference type*/
/*array数组也属于reference type 所以特点相同 int[] x also 64 bits*/

/*不同数据可能以相同01序列储存，java的interpreter通过数据类型判断如何*/
int x = 5;/*8个基本数据类型之一，box里面就是值，x代表int本身*/
/*box notation and simplified box notation*/
/*byte, short, int, long, float, double, boolean, and char*/
int y;
y = x;/*copy bits给y*/
x = 2;/*x改变并不会影响y的值*/
System.out.println("x is: " + x);
System.out.println("y is: " + y);
