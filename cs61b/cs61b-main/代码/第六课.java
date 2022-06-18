/** Array based list.
 *  @author Josh Hug
 */

//         0 1  2 3 4 5 6 7
// items: [6 9 -1 2 0 0 0 0 ...]
// size: 5

/* Invariants:
 addLast: The next item we want to add, will go into position size
 getLast: The item we want to return is in position size - 1
 size: The number of items in the list should be size.
*/
/*这节课其实就是讲如何构造array这个数据类型，并把它和list做一个比较*/
/*array好在读取非常方便，但是增删不方便*/
/*list则相反*/
public class AList<Item> {
    private Item[] items;
    private int size;

    /** Creates an empty list. */
    public AList() {
        items = (Item[]) new Object[100];/*java禁止使用泛型数组，所以没办法像定义整型数组那样*/
      /*这会产生一个编译警告，但必须忍受*/
        size = 0;
    }

    /** Resizes the underlying array to the target capacity. */
    private void resize(int capacity) {
        Item[] a = (Item[]) new Object[capacity];
        System.arraycopy(items, 0, a, 0, size);/*复制也是要把所有数据都遍历一遍的，可见还是非常麻烦*/
        items = a;
    }

    /** Inserts X into the back of the list. */
    public void addLast(Item x) {
        if (size == items.length) {
            resize(size + 1);/*为了提高效率可以把1改成其他更大的数字，多增添数组长度，但是老师说用加法不好，用乘法更好，不过没有解释为啥*/
          /*这是编程技巧要记住，不要把增加长度的的代码直接写在这里，而是多写一个method，尽量分块，既提高可读性又方便测试*/
        }/*resize(n*size) better than resize(size+n)*/
      /*但是扩充太多又涉及到利用率的问题，利用率太小会造成空间浪费，可以定义一个使用率，使用率太低就减小数组长度*/
        items[size] = x;
        size = size + 1;
    }

    /** Returns the item from the back of the list. */
    public Item getLast() {
        return items[size - 1];
    }
    /** Gets the ith item in the list (0 is the front). */
    public Item get(int i) {
        return items[i];
    }

    /** Returns the number of items in the list. */
    public int size() {
        return size;
    }

    /** Deletes item from back of the list and
      * returns deleted item. */
    public Item removeLast() {
        Item x = getLast();
        items[size - 1] = null;/*当处理整型数组时，我们没必要管最后一项，因为系统会自动清除无法引用到的对象，但这是引用类型，box里面的是地址，
        *不处理的话由于object仍然可以被指针引用到，系统并不会销毁，而且object可能占据非常大的内存 avoid loiter*/
        size = size - 1;
        return x;
    }
} 
