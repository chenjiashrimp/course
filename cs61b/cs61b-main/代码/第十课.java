/*多态性：一个行为具有不同表现形式。同一个接口，指向不同实例就会进行不同的操作*/
/*重写覆盖，继承，父类引用指向子类对象：多态性的三个条件*/

def print_larger(x, y):
    if x.largerThan(y):/*这个method是什么，还取决于x的类型*/
        return x.str()
    return y.str()
        
def print_larger(x, y, compare, stringify):/*与类型无关*/
    if compare(x, y):
        return stringify(x)
    return stringify(y)
          
/*******************************/
public static Object max(Object[] items) {/*返回数组中最大项*/
    int maxDex = 0;
    for (int i = 0; i < items.length; i += 1) {
        if (items[i] > items[maxDex]) {/*错误，>运算符并不能比较任何数据类型*/
            maxDex = i;
        }
    }
    return items[maxDex];
}

public static void main(String[] args) {
    Dog[] dogs = {new Dog("Elyse", 3), new Dog("Sture", 9), new Dog("Benjamin", 15)};
    Dog maxDog = (Dog) max(dogs);
    maxDog.bark();
}


public static Dog maxDog(Dog[] dogs) {/*单独为Dog写一个比较函数，放弃泛型化，繁琐*/
    if (dogs == null || dogs.length == 0) {
        return null;
    }
    Dog maxDog = dogs[0];
    for (Dog d : dogs) {
        if (d.size > maxDog.size) {
            maxDog = d;
        }
    }
    return maxDog;
}

/*object无法直接比较，需要让java知道用object的其他属性比较，而java无法像c或python那样重新定义运算法的功能，只能借助接口继承*/
public interface OurComparable {
    public int compareTo(Object o);
}
public class Dog implements OurComparable {
    private String name;
    private int size;

    public Dog(String n, int s) {
        name = n;
        size = s;
    }

    public void bark() {
        System.out.println(name + " says: bark");
    }

    public int compareTo(Object o) {
        Dog uddaDog = (Dog) o;/*需要cast转化类型*/
        if (this.size < uddaDog.size) {
            return -1;
        } else if (this.size == uddaDog.size) {
            return 0;
        }
        return 1;
      /*public int compareTo(Object o) {
    Dog uddaDog = (Dog) o;
    return this.size - uddaDog.size;简化*/
    }
}
public static OurComparable max(OurComparable[] items) {
    int maxDex = 0;
    for (int i = 0; i < items.length; i += 1) {
        int cmp = items[i].compareTo(items[maxDex]);/*只要是继承OurComparable就可以*/
        if (cmp > 0) {
            maxDex = i;
        }
    }
    return items[maxDex];
}/*对前面错误代码进行修正*/




/*删除CompareTo()会发生什么*/
public class DogLauncher {
    public static void main(String[] args) {
        ...
        Dog[] dogs = new Dog[]{d1, d2, d3};
        System.out.println(Maximizer.max(dogs));/*编译失败*/
    }
}

public class Dog implements OurComparable {/*编译失败*/
    ...
    public int compareTo(Object o) {
        Dog uddaDog = (Dog) o;
        if (this.size < uddaDog.size) {
            return -1;
        } else if (this.size == uddaDog.size) {
            return 0;
        }
        return 1;
    }
    ...
}

public class Maximizer {
    public static OurComparable max(OurComparable[] items) {
        ...
        int cmp = items[i].compareTo(items[maxDex]);
        ...
    }
}


/*上述的方式需要用到类型转换，这很不好*/
public class Dog implements Comparable<Dog> {/*采用泛型，无需转化，Comparable是库里已有的东西，并且Comparable适用于基本类型*/
    ...
    public int compareTo(Dog uddaDog) {/*而且Comparable只有这一个method，Comparable自己设定的排序方式叫做自然排序*/
        return this.size - uddaDog.size;
    }/*自定义类如果想排序可以引入Comparable*/
}

/*comparator*/
import java.util.Comparator;

public class Dog implements Comparable<Dog> {
    ...
    public int compareTo(Dog uddaDog) {
        return this.size - uddaDog.size;
    }

    private static class NameComparator implements Comparator<Dog> {
        public int compare(Dog a, Dog b) {
            return a.name.compareTo(b.name);
        }
    }

    public static Comparator<Dog> getNameComparator() {
        return new NameComparator();
    }
}/*comparator的比较方式比comparable更加复杂，如果不满意comparable提供的自然排序可以用，或者不想改变类又想排序的可以用，一般写法就是在原来的类再嵌套一个继承比较器的类*/
