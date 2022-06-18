/*IDEA如何建package，package里的类，移动class；default package(除非是很小的程序不然不要搞到默认包去，因为无法import)*/
/*default：默认*/

import ug.joshh.animal.Dog;/*impor ug.joshh.animal.*危害：不清楚，污染命名空间  */
.../*地址把dot改成斜线*/
Dog d = new Dog(...);


package ug.joshh.animal;/*create package*/

public class Dog {
    private String name;
    private String breed;
    …
}

DogLauncher.launch(); // won’t work默认包以外的用不了
default.DogLauncher.launch(); // doesn’t exist

/*private：只有自己 public：所有 protected：自己、同package、子类 default:同package、自己*/
/*顶层：public：所有（其他package需要import）default：package private只有同package能用*/

/*扩展类太普遍了，而同一个package的类一般都是一组人再搞，所以package里的类相对更“亲近”一些*/

/*AJR文件：把class文件包好然后share，是个zip文件，没办法安全保存你的代码*/

/*private：子类还是能继承到，但是没办法访问*/

package universe;
public interface BlackHole {
    void add(Object x); // this method is public, not package-private!
}

package universe;
public class CreationUtils {
    public static BlackHole hirsute() {
         return new HasHair();
    }
}

package universe;
class HasHair implements BlackHole {
    Object[] items;
    public void add(Object o) { ... }
    public Object get(int k) { ... }
}

import static CreationUtils.hirsute;
class Client {
   void demoAccess() {
      BlackHole b = hirsute();
      b.add("horse");
      b.get(0);/*静态类型没有该method，错误*/
      HasHair hb = (HasHair) b;/*package private没办法用*/
   }
}

/*method toSpring()  If you want a custom String representation of an object, create a toString() method*/
public String toString() {
	String mood;
	if (angry == true) {
   	   mood = "displeased";
	} else {
   	   mood = "happy";
	}
	return name + " is a " + mood + " " + breed + 
               " weighing " + size + " standard lb units.";
}
Dog d = new Dog("Lucy", 
                "Dachshund", 25);
System.out.println(d);

/*.equals() and == different*/
/*Arrays.equal or Arrays.deepEquals for arrays.*/
/*class用equals需要写一个方法，否则默认为==*/

/*Java convention is that equals must be an equivalence relation:
Reflexive: x.equals(x) is true.
Symmetric: x.equals(y) is true iff y.equals(x)
Transitive: x.equals(y) and y.equals(z) implies x.equals(z).

Must also:
Take an Object argument.
Be consistent: If x.equals(y), then x must continue to equal y as long as neither changes.
Never true for null, i.e. x.equals(null) must be false.*/

public class Date {
  private final int month;
  private final int day;
  private final int year;
 
  public Date(int m, int d, int y) {
    month = m; day = d; year = y;
  }
public boolean equals(Object x) {
	if (this == x) return true;
	if (x == null) return false;
	if (this.getClass() != x.getClass()) {
    	   return false;
	}
    Date that = (Date) x;
	if (this.day != that.day) {
    	   return false;
	}
	if (this.month != that.month) {
       return false;
	}
	if (this.year != that.year) {
       return false;
	}
	return true;
}
