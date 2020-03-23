#include <iostream>
#include <string>
#include<fstream>



// 类声明前置
class DataStructuresAndAlgorithms30;


void test();
void DAMain();



// 数据结构与算法实践
class DataStructuresAndAlgorithms30
{
public:
	// 次主函数
	void DAMain()
	{
		this->test();
	}


	void test() {
		//TestStruce ts;
		//ts.name = "你";
		//ts.age = 10;

		std::cout << "值：" << "ts.name" << "\n";
	}
/*
private:
	struct TestStruce
	{
		std::string name;
		int age;
	};
	*/
};