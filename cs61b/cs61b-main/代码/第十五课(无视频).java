/*Efficient Programming*/
/*Efficiency comes in two flavors:

1.) Programming cost.

How long does it take to develop your programs?
How easy is it to read, modify, and maintain your code?
2.) Execution cost (starting next week).

How much time does your program take to execute?
How much memory does your program require?*/

/*Packages.
Good: Organizing, making things package private
Bad: Specific
Static type checking.
Good: Checks for errors early , reads more like a story
Bad: Not too flexible, (casting)
Inheritance.
Good: Reuse of code
Bad: “Is a”, the path of debugging gets annoying, can’t instantiate, implement every method of an interface*/

/*Module: A set of methods that work together as a whole to perform some task or set of related tasks.
Encapsulated: A module is said to be encapsulated（封装） 执行被隐藏，只能通过接口访问*/

/*写栈*/
public class ExtensionStack<Item> extends LinkedList<Item> {
    public void push(Item x) {
        add(x);
    }
}

public class DelegationStack<Item> {/*delegation 更像是has a关系*/
    private LinkedList<Item> L = new LinkedList<Item>();
    public void push(Item x) {
        L.add(x);
    }
}

public class StackAdapter<Item> {
    private List L;
    public StackAdapter(List<Item> worker) {
        L = worker;
    }

    public void push(Item x) {
        L.add(x);
    }
}

