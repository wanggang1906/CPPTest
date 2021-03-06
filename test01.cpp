#include <fstream>

//#include <iostream.h> // 头文件有扩展名时可以不用namespace

#include <iostream> // 预处理器编译指令，include
					// C++的头文件可以是.h的或无扩展名，C语言的是.h的
#include"test05_structure.cpp"

#include"test06_oop.cpp" // 自定义头文件在main方法中引入
// .h头文件会报错，报无法解析的外部符号，	但cpp的可以

#include"test07_PointTo.cpp" 

#include"test10_arithmentic.cpp"
#include"test11_binary_tree.cpp"
//#include"test11_binary_tree.h" // 同时引入.cpp和.h会引起重复编译的错误

#include "test13_sqlist.h"

#include "test30_data_str_alg.cpp"
#include "test31_data_alg.h" // vs自动生成的这样导入没问题
#include "test31_data_alg.cpp"
#include "test32_alg_of_dj.h"

#include "test40_opencv.cpp"

using namespace std; // using编译指令，命名空间，保证命名不重复，放在函数内表示只在本函数内使用



// 函数声明
// test02
int main2();
int m2();
int m3();

// test03
void u1();
int CandF();

// test04
int testString();
int pointerTest();
void dataSize();
void dataType();

// test05 // 该用类定义，不用再声明方法了
//int structureTest();
//void jiaoHuan();
//void swap(int* x, int* y);

// test06

// test07
//void pointTest();



// test10



// test20
int main20();



int main() // 函数头
// 一个类中只能有一个main函数
{
	//char sa = NULL;
	//scanf("%sa",sa); // C++ 可以使用所有C的标准输入输出函数，好像有错啊
	//printf("%sa", sa);
	printf("这是主类的 \n");
	cout << "入口文件的";
	cout << "主方法" << "\n"; // endl可用“\n”代替
	// printf是C中的标准输入输出函数，而cout是iostream类中的方法，是对运算符的重载

	std::cout << "<< " << endl; // endl表示光标重起一行，作用类似换行符\n
	// << 是对用算符的重载，编译器自动根据上下文判断符号的实际含义，C语言中 &和*也是重载，表示位运算和逻辑运算



	// 调用自定义方法
	// test02
	//main2();
	//m2();
	//m3();

	// test03
	//u1();
	//CandF();

	// test04
	//testString();
	//pointerTest();
	//dataSize();
	//dataType();

	// test05
	//structureTest();
	//jiaoHuan();
	//StructClass sc = StructClass();
	//sc.structureTestMain();
	//std::cout << "类对象的地址：" << &sc << "\n";
	//sc.test(); // 类中方法访问不到 ？？？

	// test06
	//PerA personalA;
	//personalA.saidSelfName();
	//personalA.saidWord();


	// test07
	//class PointTo pTo; // 类实例化时class的作用???
	//pTo.pointTestMain();


	// test08
	

	// test10
	//DataStructuresAndAlgorithms alg;
	//alg.testSort();

	// test11
	/*
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};*/
	
	//BinaryTree binaryTree;
	//binaryTree.testStruct();

	//bTree.maxDepth;


	// test13
	//test13_sqlist sl = test13_sqlist();
	//sl.sqlistMain();
	

	// test20
	//main20();

	// test30
	//DataStructuresAndAlgorithms30 da = DataStructuresAndAlgorithms30();
	//da.DAMain();
	

	// test31
	//test31_data_alg ts31 = test31_data_alg();
	//ts31.dataAlgMain();
	//ts31.mainGraph();

	// test32
	//test32_alg_of_dj ts32 = test32_alg_of_dj();
	//ts32.main32();



	// test40
	//opencvTest cvt;
	//cvt.opencvMain();
	
	return 0;
 }
