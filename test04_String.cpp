#include <iostream>
#include <string>

using namespace std;

int testString() {

	std::string str; // 字符串是一个对象，在C++标准库中，功能非常多，如提取，比较，搜索字符串

	cout << "输入一个字符串";
	std::getline(std::cin,str);
	cout << str;
	return 0;
}


// 指针
// 指针的作用是存放地址
// 创建指针是空格不影响，如int *p; int * p; int* p;等同
// *的两种用途，@1-创建指针。@2-对指针进行解引用
// 允许多个指针指向相同的值，且同步改变
// 支持无类型指针，如void *vPointer，但解应用前要转换为适当的数据类型
int pointerTest()
{
	const unsigned short ITEM = 5;
	int intArray[ITEM] = { 1,2,3,4,5 };
	char charArray[ITEM] = { 'f','i','s','a','q' };

	int* intPtr = intArray;
	char* charPtr = charArray;
	std::cout << "整型数组输出" << '\n';
	for (int i = 0; i < ITEM; i++)
	{
		// reinterpret_cast<unsigned long>()是对地址进行强制转换
		std::cout << *intPtr << " at " << reinterpret_cast<unsigned long>(intPtr)
			<< '\n';
		intPtr++;

	}
	std::cout << "字符型数组输出" << '\n';
	for (int i = 0; i < ITEM; i++)
	{
		std::cout << *charPtr << " at " << reinterpret_cast<unsigned long>(charPtr)
			<< '\n';
		charPtr++;
	}
	return 0;
}


// 数据类型及其所占内存空间大小
void dataSize() {
	// 基本数据类型
	int a;
	float b;
	double c;
	bool d;
	char e;
	void; // 无类型
	wchar_t i; // 宽字符型
	//std::cout<< 

	// 所有数据类型
	cout << "type: \t\t" << "************size**************" << endl;
	cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
	cout << "\t最大值：" << (numeric_limits<bool>::max)(); // numeric_limits是C++的模板类，提供基础数据的极值等数学信息，其中的max,min是宏常量
	cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;

	cout << "char: \t\t" << "所占字节数：" << sizeof(char);
	cout << "\t最大值：" << (numeric_limits<char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;

	cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
	cout << "\t最大值：" << (numeric_limits<signed char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;

	cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
	cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;

	cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
	cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
	cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;

	cout << "short: \t\t" << "所占字节数：" << sizeof(short);
	cout << "\t最大值：" << (numeric_limits<short>::max)();
	cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;

	cout << "int: \t\t" << "所占字节数：" << sizeof(int);
	cout << "\t最大值：" << (numeric_limits<int>::max)();
	cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;

	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
	cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;

	cout << "long: \t\t" << "所占字节数：" << sizeof(long);
	cout << "\t最大值：" << (numeric_limits<long>::max)();
	cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;

	cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
	cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;

	cout << "double: \t" << "所占字节数：" << sizeof(double);
	cout << "\t最大值：" << (numeric_limits<double>::max)();
	cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;

	cout << "long double: \t" << "所占字节数：" << sizeof(long double);
	cout << "\t最大值：" << (numeric_limits<long double>::max)();
	cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;

	cout << "float: \t\t" << "所占字节数：" << sizeof(float);
	cout << "\t最大值：" << (numeric_limits<float>::max)();
	cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;

	cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
	cout << "\t最大值：" << (numeric_limits<size_t>::max)();
	cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;

	cout << "string: \t" << "所占字节数：" << sizeof(string);
	cout << "\t最大值：" << (numeric_limits<string>::max)();
	cout<< "\t最小值：" << (numeric_limits<string>::min)() << endl;  

	cout << "type: \t\t" << "************size**************" << endl;
}










