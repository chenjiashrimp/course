/*类的层次关系，上节是类与接口的关系*/
public class RotatingSLList<Item> extends SLList<Item>{/*获得SLList所有功能而不用复制code "is a"关系*/
  public void rotateRight() {
    Item x = removeLast();
    addFirst(x);/*列表元素向右移动*/
  }
  /*继承：所有实例和静态变量
*所有方法
*所有嵌套类
*但是不可访问private，也不继承构造函数*/
}


public class VengefulSLList<Item> extends SLList<Item> {/*记录被删除的元素*/
    SLList<Item> deletedItems;

    public VengefulSLList() {
        deletedItems = new SLList<Item>();
    }

    @Override
    public Item removeLast() {/*重写覆盖*/
        Item x = super.removeLast();/*子类优先级较高，但是我们又需要父类函数，如果直接粘贴父类的code，里面又有太多private，所以只能采用super关键字*/
        deletedItems.addLast(x);
        return x;
    }

    /** Prints deleted items. */
    public void printLostItems() {
        deletedItems.print();
    }
}

public VengefulSLList() {
    super();/*以此调用superclass的构造函数，这里写不写无所谓*/
    deletedItems = new SLList<Item>();
}

public VengefulSLList(Item x) {
    super(x);/*这里带参数，就一定要写了*/
    deletedItems = new SLList<Item>();
}
/*super关键词有三个作用，前两个是调用父类的变量和method，只有出现覆盖情况时才用super，super.variables super.method*/
/*第三个作用是调用父类的构造函数，super(),而且我们必须使用，如果没有的话编译器会为我们默认添加，但是添加的是不带参数的super()*/

/*Object类是最基本的类，它提供了很多行为*/

/*封装，模块化，接口*/
/*处理复杂性，把模块如何实现功能的部分隐藏起来，仅通过接口进行交互，黑盒子*/

/*抽象分层、分成几个部分*/


VengefulSLList<Integer> vsl = new VengefulSLList<Integer>(9);
SLList<Integer> sl = vsl;
sl.addLast(50);/*子类没有，自动去看更高一级*/
sl.removeLast();/*子类覆盖，执行*/
sl.printLostItems();/*注意：编译时发现静态类型不含这个method，所以程序编译失败会崩溃*/
VengefulSLList<Integer> vsl2 = sl;/*同样会崩溃，sl把静态类型传过去，但是vsl2的静态类型是sl静态类型的subclass，“is a”关系可能不成立*/

public static Dog maxDog(Dog d1, Dog d2) { ... }
Poodle frank = new Poodle("Frank", 5);
Poodle frankJr = new Poodle("Frank Jr.", 15);

Dog largerDog = maxDog(frank, frankJr);
Poodle largerPoodle = maxDog(frank, frankJr); //does not compile! RHS has compile-time type Dog
Poodle largerPoodle = (Poodle) maxDog(frank, frankJr); // compiles! Right hand side has compile-time type Poodle after casting
/*这是欺骗编译器的行为，强大但也危险，相当于告诉编译器不需要做check type的行为*/

Poodle frank = new Poodle("Frank", 5);
Malamute frankSr = new Malamute("Frank Sr.", 100);

Poodle largerPoodle = (Poodle) maxDog(frank, frankSr); // runtime exception!如果没有的话并不会编译，但是现在cast，而method返回的类型是Malamute不是Poodle，就会发生异常

/*高阶函数*/
public interface IntUnaryFunction {
    int apply(int x);
}
public class TenX implements IntUnaryFunction {
    /* Returns ten times the argument. */
    public int apply(int x) {
        return 10 * x;
    }
}
public static int do_twice(IntUnaryFunction f, int x) {
    return f.apply(f.apply(x));
}
System.out.println(do_twice(new TenX(), 2));
