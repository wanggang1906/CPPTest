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










