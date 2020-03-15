//面向对象
#include<iostream>
#include<string>

// C++中类和结构体比较相似
// 类中可以定义属性和方法，结构体中声明变量，是一组变量组成的数据结构，操作是
// 一个空类也含有四种函数，构造函数，析构函数，赋值函数，拷贝函数



// 基类Personal
class Personal
{
public:
	std::string name;
	float age;
	int a;

	void saidWord()
	{
		std::cout << "输出";
	}
	void saidBay();
};

/*
// :: 是域运算符，在类中声明方法，但未实现，在类外实现时用::指明是那个类的方法
void Personal::saidBay(){
	std::cout << "bay";
}
*/

// 子类PerA
class PerA : public Personal
{
public:
	int perAParticularAttribute = 021;

	void saidSelfName()
	{
		std::cout << "我是：" << perAParticularAttribute;
	}

};
