C/C++ 数据结构 学习
===

## C语言
1. C语言中没有字符串类型,只能用间接的方式实现 `char *str = "Hello World!";`(字符串实际上就是一个char数组，只是末尾值为 '\0')
2. printf 格式控制字符的完整形式如下：`%[flags][width][.precision]type`
3. 关系运算符的优先级低于算术运算符，高于赋值运算符。(算数运算符 > 关系运算符 > 赋值运算符)
4. 当赋值的元素少于数组总体元素的时候，剩余的元素自动初始化为 0：对于short、int、long，就是整数0；对于char，就是字符 '\0'；对于float、double，就是小数0.0。
5. 函数声明,由于C语言是按顺序执行，原则上函数定义要出现在函数调用之前，使用函数声明可以实现先使用后声明
6. 预处理：主要包含 以`#`开头的命令
7. 宏定义：#define 使用时只简单的替换字符串，所以无需进行类型声明
8. [C语言指针变量的运算](http://c.biancheng.net/cpp/html/75.html)
9. [只需一招，彻底攻克C语言指针](http://c.biancheng.net/cpp/html/3249.html)
10. 函数无法识别结构体的不完整声明，但另一个结构体中可识别
11. 结构体中带指针的变量不能用`=`赋值，而要使用`memcpy()`函数
12. 返回值返回的是元数据的一份拷贝,所以返回结构体时需要返回指针

## C++
1. C++ 中的 public、private、protected 只能修饰类的成员，不能修饰类，C++中的类没有共有私有之分。
2. C++ 默认访问权限为`privite`
3. 函数初始化表 
    1. 以下两端代码功能相同，利用函数初始化表只是为了书写方便
    ``` c++
    // 普通函数初始化
    Student(std::string name, int age, float score) {
        m_name = name;
        m_age = age;
        m_score = score;
    }

    // 函数初始化表
    Student(std::string name, int age, float score): m_name(name), m_age(age), m_score(score) {
        // TODO
    }
    ```
    2. 初始化`const`成员变量(const 成员变量仅能通过初始化表进行初始化)
4. 析构函数 http://c.biancheng.net/cpp/biancheng/view/196.html
    1. 对象初始化时需要调用构造函数，而当对象销毁时则要调用析构函数
    2. 析构函数与类型相同但是需要加上前缀`~`
5. this 是一个指针，智能通过`->`访问成员变量
6. 继承，与**Java**不同，**C++**的构造函数无法被继承
7. 继承时可使用`using`关键字改变基类中的访问权限,如将`private`改为`public`。

## TODO
1. 浮点数在内存中如何存储
2. 缓冲区（缓存）

## Thanks
[C语言中文网](http://c.biancheng.net/cpp/)