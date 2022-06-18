/*抽象数据结构*/
/*给你method，没说method怎么做，就是之前的接口interface*/

/*java libraries:已经建好的抽象数据类型*/
/*里面三个重要ADT：List(链表和数组) Set(不重复)(HashSet TreeSet) Map(HashMap TreeSet)*/

public static List<String> getWords(String inputFileName) {
    List<String> lst = new ArrayList<String>();
    In in = new In();
    while (!in.isEmpty()) {
        lst.add(in.readString()); //optionally, define a cleanString() method that cleans the string first.       
    }
    return lst;
}

public static int countUniqueWords(List<String> words) {
    Set<String> ss = new HashSet<>();
    for (String s : words) {
           ss.add(s);        
    }
    return ss.size();
}/*不重复的单词的个数*/

public static Map<String, Integer> collectWordCount(List<String> words) {/*单词重复几次*/
    Map<String, Integer> counts = new HashMap<String, Integer>();
    for (String t: target) {
        counts.put(s, 0);
    }
    for (String s: words) {
        if (counts.containsKey(s)) {
            counts.put(word, counts.get(s)+1);
        }
    }
    return counts;
}

/**代码比python复杂，但也有很多优点*/
/*可以说，由于以下特性，编写程序需要更少的时间：

静态类型（提供类型检查并帮助指导程序员）。
偏向接口继承导致更清晰的子类型多态性。
访问控制修饰符使抽象壁垒更加牢固。
由于以下功能，代码效率更高：

能够更好地控制工程权衡。
单值数组带来更好的性能。
基本数据结构更类似于底层硬件：
在 Python 中做 ArrayDeque 会很奇怪，因为不需要调整数组大小。但是，在硬件中（参见 61C），不存在可变长度数组。*/

/*抽象类：类似接口，加了abstract方法才被认为抽象
所有方法都必须是公开的。
所有变量都必须是 public static final。
无法实例化
默认情况下，所有方法都是抽象的，除非指定为 default
每个类可以实现多个接口
我们现在将介绍一个介于接口和具体类之间的新类：抽象类。下面是抽象类的特征：

方法可以是公共的或私有的
可以有任何类型的变量
无法实例化
默认情况下，方法是具体的，除非指定为 abstract
每个类只能实现一个*/

/*package：类有相同名称，把其放进package里面来区分
*import 类似地址(package)*/
