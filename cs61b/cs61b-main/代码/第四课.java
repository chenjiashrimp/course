public class IntList {
	public int first;
	public IntList rest;

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
	}

	/** Returns the ith item of this IntList. */
	public int get(int i) {
		if (i == 0) {
			return first;
		}
		return rest.get(i - 1);
	}

	public static void main(String[] args) {
		IntList L = new IntList(15, null);
		L = new IntList(10, L);
		L = new IntList(5, L);

		System.out.println(L.get(100));
	}
} 
/*Intlist并不好用，naked data struction因为其把功能如何实现都展现給使用者了，我们最好把功能的实现装在一个个黑盒子里面
使用者看到黑盒子的名字说明就知道功能并使用，但功能实现的具体细节无需清楚*/



/*IntNode和Intlist是一样的*/
 /** An SLList is a list of integers, which hides the terrible truth
   * of the nakedness within. 就像一个中间人*/
public class SLList {	
	private static class IntNode {/*私有，外界无法调用，作为naked data struction，使用者当然无需清楚nested classes*/
		public int item;/*这就是一个黑盒子，也不会用到SLList的任何方法变量，因此可以直接设置为静态，而且还可以节约memory*/
		public IntNode next;

		public IntNode(int i, IntNode n) {
			item = i;
			next = n;
			System.out.println(size);
		}
	} 

	/* The first item (if it exists) is at sentinel.next. */
	private IntNode sentinel;/*哨兵结点永远放在第一个，为了把空列表和非空列表统一，设置一个哨兵节点并把其隐藏*/
	private int size;/*定义尺寸，如果要是写一个计算尺寸的method，那么每次变更都要调用一次，不如把size作为初始的实例变量，根据变化直接实时更新*/
  
  /*没有定义next，所以SLList没办法直接使用递归*/
  
  /*SLList L = new SLList(15);
*L.addFirst(10);
*L.first.next.next = L.first.next;为何设置为私有，一个量被设置为private也说明了其可以被被忽略*/
 /*When you create a public member (i.e. method or variable), be careful, 
 *because you're effectively committing to supporting that member's behavior exactly as it is now, forever.*/ 
  
  
	private static void lectureQuestion() {
		SLList L = new SLList();
		IntNode n = IntNode(5, null);/*实例变量为IntNode，这样就能使用其method*/
	}

	/** Creates an empty SLList. */
	public SLList() {
		sentinel = new IntNode(63, null);/*可以是任何数*/
		size = 0;
	}

	public SLList(int x) {
		sentinel = new IntNode(63, null);
		sentinel.next = new IntNode(x, null);
		size = 1;
	}

 	/** Adds x to the front of the list. */
 	public void addFirst(int x) {
 		sentinel.next = new IntNode(x, sentinel.next);/*接在哨兵节点后面*/
 		size = size + 1;
 	}

 	/** Returns the first item in the list. */
 	public int getFirst() {
 		return sentinel.next.item;
 	}

 	/** Adds x to the end of the list. */
 	public void addLast(int x) {/*没有哨兵节点，空列表在这里就会error*/
 		size = size + 1; 		

 		IntNode p = sentinel;

 		/* Advance p to the end of the list. */
 		while (p.next != null) {
 			p = p.next;
 		}

 		p.next = new IntNode(x, null);
 	}
 	
 	/** Returns the size of the list. */
 	public int size() {
 		return size;/*size是私有量，不能直接使用*/
 	}

	public static void main(String[] args) {
 		/* Creates a list of one integer, namely 10 */
 		SLList L = new SLList();
 		L.addLast(20);
 		System.out.println(L.size());
 	}
}



/*An invariant is a fact about a data structure that is guaranteed to be true (assuming there are no bugs in your code).

A SLList with a sentinel node has at least the following invariants:

The sentinel reference always points to a sentinel node.
The front item (if it exists), is always at sentinel.next.item.
The size variable is always the total number of items that have been added.*/
