public class Dog {
    public static void makeNoise() {/*静态方法，无法直接访问实例变量（需要实例+.才可以），因此其他类引用这个类的method也不需要先进行实例化*/
      /*Class methods, a.k.a. static methods.*/
      /*x = Math.sqrt(100)这玩意是静态的，可以直接这样写*/
        System.out.println("Bark!");
    }
}
public class DogLauncher {
    public static void main(String[] args) {
        Dog.makeNoise();
    }
}


public class Dog {
    public int weightInPounds;/*实例变量instance variables or non-static variables*/
/*members of class*/
    public static String binomen = "Canis familiaris";/*静态变量，一样用法*/
    public Dog(int w) {/*构造函数*/
        weightInPounds = w;
    }
    public void makeNoise() {/*非静态，可以直接访问*/
      /*instance methods or non-static methods*/
        if (weightInPounds < 10) {
            System.out.println("yipyipyip!");
        } else if (weightInPounds < 30) {
            System.out.println("bark. bark.");
        } else {
            System.out.println("woof!");
        }
    } 
  /*this.可以表示当前这个实例*/
  public Dog maxDog(Dog d2) {
    if (this.weightInPounds > d2.weightInPounds) {
        return this;
    }
    return d2;
}
}
public class DogLauncher {
    public static void main(String[] args) {
        Dog d;/*需要先实例化才能引用method*/
        d = new Dog();/*声明一个变量*/
        d.weightInPounds = 20;
        d.makeNoise();
      
      Dog d = new Dog(20);
        d.makeNoise();/*有了构造函数*/
      
      
      /* Create an array of two dogs. */
        Dog[] dogs = new Dog[2];
        dogs[0] = new Dog(8);
        dogs[1] = new Dog(20);

        /* Yipping will result, since dogs[0] has weight 8. */
        dogs[0].makeNoise();
    }
}


public class ArgsDemo {
    public static void main(String[] args) {
        System.out.println(args[0]);/*会异常*/
    }
}
/*$ java ArgsDemo these are command line arguments*/


public class ArgsSum {
	/** Prints out the sum of arguments, assuming they are
 	*  integers.
 	*/
	public static void main(String[] args) {
    	int index = 0;
    	int sum = 0;
    	while (index < args.length) {
        	sum = sum + Integer.parseInt(args[index]);
        	index = index + 1;
    	}
    	System.out.println(sum);
	}
}/*java ArgsSum 1 2 3 4*/


/*javac 编译 生成 java类，java类经过interpreter运行程序*/
