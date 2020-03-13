//面向对象
#include<iostream>
#include<string>

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
