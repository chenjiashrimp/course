public class Homework00 {/*任何code都要写在类里面*/
    public static int max(int x, int y){/*规则类似c语言只能返回一个类型，形参的类型也要说清楚*/
        if(x>y)
            return x;
        else
            return y;
    }/*函数同样要写在类里，而类里的函数叫做method，所以java的所有函数都为method*/
    public static void main(String[] args) {
        String s = 5 + "abc";/*静态类型语言(static types)，先确定变量类型，s确定为string所以5会被认为是字符，如果是int型就会报错*/
        System.out.println(s);
        System.out.print(s);/* 区别在于这个不会换行*/
        double d=2;
        System.out.println(d);/*输出变为2.0*/
        /*array数组*/
        int[] numbers=new int[3];
        numbers[0]=1;
        numbers[1]=2;
        numbers[2]=3;/*第一种定义*/
        System.out.println(numbers.length);/*得到数组长度的函数*/
        String[] names=new String[]{"chen","haha"};
        System.out.println(names[1].contains("ha"));/*函数：字符串包含*/

        /*enhanced for loop*/
        for(String str:names){
            System.out.println(str);
        }

    }
}
/*The compiler ensures type consistency. If types are inconsistent, the program will not compile.
* 运行前就会检测
* Command line compilation and execution. javac is used to compile programs.
* java is used to execute programs. We must always compile before execution.
* */

/*Static Typing. Static typing is one of the best features of Java.
It gives us a number of important advantages over languages without static typing:
Types are checked before the program is even run, allowing developers to catch type errors with ease.
If you write a program and distribute the compiled version, it is (mostly) guaranteed to be free of any type errors.
This makes your code more reliable.
Every variable, parameter, and function has a declared type, making it easier for a programmer to understand and reason about code.*/
