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
};

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
