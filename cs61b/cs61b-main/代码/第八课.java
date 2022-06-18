/*主要讲了继承：接口继承和实现继承，subclass和superclass，override和overload*/
public static String longest(SLList<String> list) {/*如何list数据类型为AList，该怎么改？如果是简单地copy一个method(就是overload)，那么会增加代码量，降低可读性，而且日后修改麻烦*/
    int maxDex = 0;
    for (int i = 0; i < list.size(); i += 1) {
        String longestString = list.get(maxDex);
        String thisString = list.get(i);
        if (thisString.length() > longestString.length()) {
            maxDex = i;
        }
    }
    return list.get(maxDex);
}

/*Hypernyms and Hyponyms上位词和下位词*/
/*注意区分“is a” and "has a"的区别，继承是“is a”*/

public interface List61B<Item> {/*接口继承，确定它的子类有哪些行为，但是不确定具体如何实现这些行为（只有method的signature，没有body）*/
    public void addFirst(Item x);
    public void add Last(Item y);
    public Item getFirst();
    public Item getLast();
    public Item removeLast();
    public Item get(int i);
    public void insert(Item x, int position);
    public int size();
}/*这是第一步*/
/*第 1 步：定义通用列表上位词的类型——我们将选择名称 List61B。
*第 2 步：指定 SLList 和 AList 是该类型的下义词。*/

/*第二步*/
public class AList<Item> implements List61B<Item>{/*后面这部分相当于承诺，具有接口所有属性和行为，所以说如果不覆盖所有method，编译就会失败！*/
   ...
   public void addLast(Item x) {}
   @Override/*作用是提醒编译器你打算覆盖这个method。即使不加这个，也能起到覆盖的作用（没有失误的话），加的话一是增加可读性，二是防止失误，比如你写错signature了，没加这个就不能覆盖了*/
   public void addFirst(Item x) {
   insert(x, 0);
     }
}/*父类定义行为，子类负责实现*/
/*需要编辑接口确定的行为*/
/*signature包括method名称和内部的参数，完全一样才叫override，overload是名称一样但是参数不同*/

public static String longest(List61B<String> list) {/*实现继承后，最开始的代码就可以这样写*/
  	int maxDex = 0;
  	for (int i = 0; i < list.size(); i += 1) {
     	String longestString = list.get(maxDex);
     	String thisString = list.get(i);
     	if (thisString.length() > longestString.length()) {
        	maxDex = i;
     	}
  	}
  	return list.get(maxDex);
}

/*动态类型与静态类型Static and Dynamic Type*/
/*如何考虑具有继承关系的数据类型？*/
    public static void main(String[] args) {
   List61B<String> someList = new SLList<String>();	/*对于someList来说，它的静态类型为List61B（看最前面关键词），但是动态类型为SLList（看new），类型不同但不会报错，因为SLList继承List61B*/
   /*box上刻的是List61B，存的地址是List61B的，但是可以指向SLList，也可以指向AList*/
   someList.addFirst("elk");
}

public static void main(String[] args) {
   LivingThing lt1;/*一个64位box，存着LivingThing的地址*/
   lt1 = new Fox();/*实例化，指向Fox类型*/
   Animal a1 = lt1;
   Fox h1 = new Fox();
   lt1 = new Squid();
}


/*实现继承，指定了method，而且method该如何实现也一起交待了*/
public interface List61B<Item> {/*一样的写法*/
   public void addFirst(Item x);
   public void addLast(Item y);
   public Item getFirst();
   public Item getLast();
   public Item removeLast();
   public Item get(int i);
   public void insert(Item x, int position);
   public int size();  
   default public void print() {/*新写法，用到default*/
      for (int i = 0; i < size(); i += 1) {
         System.out.print(get(i) + " ");
      }
      System.out.println();
   }
}

/*SLList*/
@Override/*一边是superclass交待了print如何实现，一边是这里又override，好像产生矛盾，该执行哪一个呢？*/
public void print() {/*看动态类型，如果new的是SLList就用这个method，其他的用default的method，这个规律只用于既有default还有override*/
  /*如果是overload就没有矛盾了，因为signature不一样，本质上是两个不同的method，直接看静态类型*/
    for (Node p = sentinel.next; p != null; p = p.next) {
        System.out.print(p.item + " ");
    }
}


public interface Animal {
  default void greet(Animal a) {
    print("hello animal"); }
  default void sniff(Animal a) {
    print("sniff animal"); }
  default void flatter(Animal a) {
    print("u r cool animal"); }
}

public class Dog implements Animal {
  void sniff(Animal a) {
    print("dog sniff animal"); }
  void flatter(Dog a) {
    print("u r cool dog"); }
}
 
Animal a = new Dog();
Dog d = new Dog();
a.greet(d);   // "hello animal"
a.sniff(d);   // "dog sniff animal"
d.flatter(d); // "u r cool dog"
a.flatter(d); // “u r cool animal”
     
 /*总结*/
/*实现继承的好处就是可以和override配合使用，决定一个method怎么用*/
/*劣势：如果多级继承容易乱，method在很前面；使代码复杂；破坏封装性？之后讲*/
