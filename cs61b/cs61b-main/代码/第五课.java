public class ArrayBasics {
    /** ArrayBasics */
    public static void main(String[] args) {
        int[] z = null;
        int[] x, y;

        x = new int[]{1, 2, 3, 4, 5};
        y = x;
        x = new int[]{-1, 2, 5, 4, 99};/*指向新数组*/
        y = new int[3];/*旧数据被抛弃，找不到了*/
        z = new int[0];

        String[] s = new String[6];
        s[4] = "ketchup";
        s[x[3] - x[1]] = "muffins";

        int[] b = {9, 10, 11}; 
        System.arraycopy(b, 0, x, 3, 2);/*从哪里开始复制，复制到哪里，应当属于深度复制*/
    }
}



public class ArrayBasics2 {
	/** ArrayBasics
	 */

	public static void main(String[] args) {
		int[][] pascalsTriangle;
		pascalsTriangle = new int[4][];
		int[] rowZero = pascalsTriangle[0];

		pascalsTriangle[0] = new int[]{1};
		pascalsTriangle[1] = new int[]{1, 1};
		pascalsTriangle[2] = new int[]{1, 2, 1};
		pascalsTriangle[3] = new int[]{1, 3, 3, 1};
		int[] rowTwo = pascalsTriangle[2];
		rowTwo[1] = -5;

		int[][] matrix;
		matrix = new int[4][];
		matrix = new int[4][4]; 

		int[][] pascalAgain = new int[][]{{1}, {1, 1}, 
		{1, 2, 1}, {1, 3, 3, 1}};
	}
} 


public class SLList<LochNess> {	/*类似于类模板，把数据类型形参化*/
	private class StuffNode {
		public LochNess item;
		public StuffNode next;

		public StuffNode(LochNess i, StuffNode n) {
			item = i;
			next = n;
		}
	} 

	private StuffNode first;
	private int size;

	public SLList(LochNess x) {
		first = new StuffNode(x, null);
		size = 1;
	}

 	/** Adds x to the front of the list. */
 	public void addFirst(LochNess x) {
 		first = new StuffNode(x, first);
 		size += 1;
 	}

 	/** Returns the first item in the list. */
 	public LochNess getFirst() {
 		return first.item; 		
 	}

 	/** Adds an item to the end of the list. */
 	public void addLast(LochNess x) {/*速度太慢，可以改成双向链表，可以设置第二个哨兵节点*/
 		size += 1;

 		StuffNode p = first;

 		/* Move p until it reaches the end of the list. */
 		while (p.next != null) {
 			p = p.next;
 		}

 		p.next = new StuffNode(x, null);
 	}

 	public int size() {
 		return size;
 	}
}

public class SLListLauncher {
	public static void main(String[] args) {
		SLList<String> s1 = new SLList<>("bone");/*如何声明变量*/
		s1.addFirst("thugs");	
	}
} 
