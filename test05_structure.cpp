#include<iostream>



// 类声明前置 ？？？
//class StructClass;

class StructClass
{

private:
	// 定义结构体数据类型
	typedef struct info {
		std::string name;
		int age;
	};

	typedef struct infoName {
		int af;
	};
	
	// 结构体必须要初始化

	
public:
	void structureTestMain()
	{
		this->getStructureOfClass();
	}

	// 结构体
	// .和 -> 的区别，如结构变量时用. 指针指向时用 -> 
	int structureTypeTest()
	{
		struct FishOil
		{
			std::string name; // 字符串对象
			int age;
			char sex;
		};
		return 0;
	}


	// 使用类中的结构体

	void getStructureOfClass()
	{
		struct info inf001 = { "",0 };
		inf001.name = "inf01";
		inf001.age = 10;
		std::cout << "结构体对象的地址：" << &inf001 << "\n";

		//Inm02* inm002 = NULL;
		//inm002->af = 20;
		//std::cout << inm002->af << "\n";


	}

	// 交换两个数
	void jiaoHuan()
	{
		int s = 1;
		int d = 2;
		//swap(&s, &d);
	}

	void swap(int* x, int* y) 
	{
		*x ^= *y;
		*y ^= *x; // 异或操作
		*x ^= *y;
	}




};
