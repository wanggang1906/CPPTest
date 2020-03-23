
#include "test31_data_alg.h"
#include<iostream>


// 类定义与实现相分离的写法
// cpp文件只写类的实现，是通过内联函数实现的
// h文件只写类的定义，在多个文件中引用时编译器只编译一次，引用时也只包含头文件

void test31_data_alg::classTest()
{
	std::cout << "类中方法" << "\n";
};