# 1.数组

## 1.1一维数组

三种定义方法

1.数据类型 数组名[长度]

2.数据类型 数组名[长度] = {...}

3.数据类型 数组名[] = {.....}

## 1.2数组名

可以统计数组元素个数

可以获取数组在内存中的首地址

```cpp
	int a[] = { 1,2,3,45,7,8,987,89 };
	cout << sizeof(a) << endl;
```

可得输出为32，为4个字节，8个元素

数组名是常量，不能赋值

**案例1：找出数组中最大值**

```cpp
	int a[5] = { 23,56,12,42,78 };
	int b = 0;
	for (int i = 0; i < 5; i++)
	{
		if (b < a[i]) {
			b = a[i];
		}
	}
```

**案例2.数组元素逆置**

```cpp
	int a[5] = { 23,56,12,42,78 };
	int b = 0;
	int end = sizeof(a) / sizeof(a[0]) - 1;
	while(b<end)
	{
		int temp = 0;
		temp = a[b];
		a[b] = a[end];
		a[end] = temp;
		b++;
		end--;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
```

# 2.函数

## 2.1概述

将一段经常使用的代码封装起来，减少重复代码

```cpp
返回值类型 函数名（参数列表）{
}
```

## 2.2函数调用

```CPP
int add(int a,int b){
    int c = a+b;
    return c;
}
int main(){
    int a = 10;
    int b = 20;
    add(a,b);
    cout <<c<<endl;
}
```

输出为30

## 2.3值传递

形参发生改变，实参不发生任何改变

如需要改变，则传入参数需要引用

## 2.4函数的样式

有参无返

有参有返

无参有返

无参无返

## 2.5函数的分文件编写

1.创建.h的头文件

2.创建.cpp的源文件

3.在头文件中写函数的声明

4.在源文件中写函数的定义

# 3.指针

## 3.1指针

通过指针间接访问内存

定义： 

```cpp
int a = 10;
int* p;
p = &a;//让指针p记录a的地址
```

## 3.2指针内存

32位操作系统占4个字节

64位操作系统占8个字节



## 3.3空指针

指针变量指向内存中编号位0的空间

用来初始化指针变量，不可用来访问内存

## 3.4野指针

指向非法内存空间

## 3.5const修饰指针

const修饰指针，常量指针

```cpp
const int*p = &a;
```

指向可更改，指向的值不可更改

const修饰常量，指针常量

```cpp
int * const p = &a;
```

指向不可更改，指向的值可更改

const修饰指针和常量

```cpp
const int * const p = &a;
```

指向不可更改，指向的值不可更改

## 3.6指针和数组

利用指针访问数组中元素

```cpp
int arr[10] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr;//此时访问第一个元素
p++;//访问第二个元素
```

## 3.7指针和函数

利用指针做函数形参，可改变实参的值

**地址传递**

```cpp
void swap(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(){
    int a = 10;
    int b = 20;
    swap(&a,&b);
}
```

如果地址传递即可改变实参的值

## 3.8指针数组函数案例

封装一个函数，冒泡排序，升序排列

```cpp
//冒泡排序函数
void sortlist(int *arr[],int len)
{
    for(int i = 0;i<len-1;i++)
    {
        for(int j = 1 ;j <len ;j++)
        {
            int temp = arr[j];
            arr[j] = arr [j+1];
            arr[j+1] = temp;
        }
    }
}
```

# 4.结构体

结构体属于用户自定义的数据类型，允许存储不同的数据类型

```cpp
struct student{//自定义数据类型
    string name;
    int age;
    int score;
}
struct student  s1 ;
s1.name = "asdad";
s1.age = 12;
s1.score = 100;//两种赋值方法
struct student  s1 = {"asda" ,15 ,98};
```

## 4.1结构体数组

将自定义的结构体放到数组中方便维护

```cpp
struct student{//自定义数据类型
    string name;
    int age;
    int score;
};
struct student  s1 ;
s1.name = "asdad";
s1.age = 12;
s1.score = 100;//两种赋值方法
struct student  s1 = {"asda" ,15 ,98};
struct student  arr[3]={
    {"asdad",45,465}
    {"dsadasd",78,54}
    {"asdasd",79,23}
};
//调用
arr[1].name = "sdadasd";//后期修改
```

## 4.2结构体指针

通过指针访问结构体中的成员

```cpp
struct student{
    string name;
    int age;
    nt score;
};
int main(){
    student s = {"sdas",12,32}
    student * p = &s;
    p->name;
    p->age;
    p->score;
}
```

## 4.3结构体嵌套结构体

结构体中的成员可以是另一个结构体

案例：每个老师辅导一个学院，一个老师的结构体中有另一个学员的结构体

```cpp
struct student{
    int id;
    int age;
    string name;
};
struct teacher{
    int id;
    string name;
    int age;
    struct student stu;
};
int main(){
    teacher t;
    t.name = "ad";
    t.age = 12;
    t.id = 100;
    t.stu.name = "as";
    t.stu.age = 45;
    t.stu.id = 78;
}
```

## 4.4结构体做函数参数

将结构体作为参数传入函数

值传递

地址传递

```cp
struct student{
    int id;
    int age;
    string name;
};
int main(){
	struct student s;
	s.name = "qw";
	s.id = 45;
	s.age = 12;
}
//值传递：
void print(struct student s)
{
	cout<<s.name<<s.age<<s.id<<endl;
//地址传递
void print2(struct student *s)
{
	cout<<s->name<<s->age<<s->id<<endl;
}
```

## 4.5结构体中const使用场景

用const防止误操作

```cp
struct student
{
	string name;
	int age;
	int score;
};
viod print(const student * s)
{
	cout<<s->name<<endl;
}
int main()
{
	struct student s ={"asd",15,70};
	print(&s);
}
```

节省内存可用地址传递

加入const后修改就会报错

## 4.6结构体案例

![image-20230315220923652](C:\Users\34844\AppData\Roaming\Typora\typora-user-images\image-20230315220923652.png)

```cpp
#include <iostream>
#include <string>
using namespace std;

struct student
{
    string aname;
    int score;
};
struct teacher
{
    string tname;
    struct student arry1[5];
};
void insert_score(teacher arry[], int len)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        arry[i].tname = "Teacher_";
        arry[i].tname += nameseed[i];
        for (int j = 0; j < 5; j++)
        {
            arry[i].arry1[j].aname = "Student_";
            arry[i].arry1[j].aname += nameseed[j];
            arry[i].arry1[j].score = 60;
        }
    }
}
void print(teacher arry[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << arry[i].tname << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "学生姓名：" << arry[i].arry1[j].aname << arry[i].arry1[j].score<< endl;
        }
    }
}
int main()
{
    teacher arry[3];
    student arry1[5];
    int len = sizeof(arry) / sizeof(arry[0]);
    insert_score(arry, len);
    print(arry, len);
    return 0;
}
```

