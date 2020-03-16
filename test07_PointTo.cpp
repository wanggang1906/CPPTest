#include<iostream>


// 指针的四个问题

// 指针的类型 --- 把指针声明里的指针名字去掉，剩下的部分是指针的类型
// 指针所指向的类型 --- 当你通过指针来访问指针所指向的内存区时，指针所指向的类型决定了编译器将把那片内存区里的内容当做什么来看待。
// 指针本身的值 --- 
// 指针所指向的内存区域的值

// 类的声明在头文件中，类的实现在cpp文件中，在main中要引入头文件
class PointTo {
public: // 公开的属性和方法
	void pointDef() {
		printf("指针相关概念");
		// 来源： 
		// https://www.cnblogs.com/sumuncle/p/9773955.html
		// https://blog.csdn.net/weixin_39640298/article/details/84900326
		// https://www.cnblogs.com/aquester/p/11469872.html

		// 几种类型指针
		//int *ptr; // 指针的类型是int *	// 指针所指向的类型是int
		//char *ptr; // 指针的类型是char *	// 指针所指向的类型是char
		//int **ptr; // 指针的类型是int **	// 指针所指向的类型是int *
		//int(*ptr)[3]; // 指针的类型是int (*)[3]		// 指针所指向的类型是int()[3]	// ()可解决优先级问题
		//int *(*ptr)[4]; // 指针的类型是int *(*)[4]	// 指针所指向的类型是int *()[4]

		// 几种特殊的指针
		int num = 97;
		float score = 10.00F;
		int arr[3] = { 1,2,3 };

		int* p_num = &num;
		int* p_arr1 = arr;		//p_arr1意思是指向数组第一个元素的指针
		float* p_score = &score;
		int(*p_arr)[3] = &arr;
		//int (*fp_add)(int, int) = add;  //p_add是指向函数add的函数指针
		const char* p_msg = "Hello world";//p_msg是指向字符数组的指针

		std::cout << sizeof(num);


	}


	
	int add(int a,int b) {
		return 0;
	}

	// 点击运行后还是上一次的代码，本次的没有编译
	// 参考：https://blog.csdn.net/weixin_30559481/article/details/99924402
	void pointSize() {
		printf("指针实验---"+1); // 是否可以输出不同类型数据
		
		int *p;
		int s = 10;
		std::cout <<"指针的大小："<<sizeof(p)<<"_"<<s; // 输出流可以输出不同类型的数据

		int *ps[3];

		std::cout <<"ps的地址是: %d   "<<&ps<<"\n"; // &取地址符，%d十进制，%p十六进制
		
	}


	void pointType() {
		// 指针的类型
		// 从语法的角度看，你只要把指针声明语句里的指针名字去掉，剩下的部分就是这个指针的类型
		int* p; // 类型是int*
		int** pt; // 类型是 int**
		int*** ptr; // 类型是 int***

		int(*pta)[3]; // 类型是int(*)[3]
		int* (*ptc)[4]; // 类型是int*(*)[4]     //  int** ptc[4]; // 同？？？

		// 指针所指向的类型
		// 从语法上看，你只须把指针声明语句中的指针名字和名字左边的指针声明符*去掉(只去掉一个)，剩下的就是指针所指向的类型

	}

	void pointArray() {
		// 指针和数组
		// 指针数组-存储指针的数组。首先它是一个数组，数组的元素都是指针，数组占多少个字节由数组本身决定。
		// 数组指针-指向数组的指针。首先它是一个指针，它指向一个数组。在32 位系统下永远是占4 个字节，至于它指向的数组占多少字节，不知道。

		int* ary[12]; // []的优先级比*高，则首先是一个ary[12]的数组，int*修饰这个数组，即表明数组中每个元素都是int*类型的。即为存储指针的数组
		int(*aryp)[10]; // ()的优先级高于[]，*和aryp构成指针的定义，所以它首先是一个指针，int修饰数组，数组没有名字，是匿名数组。即aryp是一个指针，指向有10个int型元素的数组
		
		std::cout << ary[0] << "\n";

	}


	void pointTestMain() {
		std::cout << "指针主方法---"<<"\n";

		
		int* a=NULL;
		int* b=NULL;
		int d = 13;
		int e = 14;
		a = &d; // 取址运算符，结果是一个指针
		b = &e;
		this->pointTest01(a,b); // this指针调用本类方法


	}

	void pointTest01(int* p,int* a) {
		// 两数相加
		int* c;
		int* b;
		long d;
		c = p + 1;
		b = a + 1; // 使地址+1

		d = b - c; // 两个指针不可以相加，相加后指向的地方不知。但可以相减，值为两指针之间距离多少个元素，不是字节
		std::cout << c<<b<<"\n";
		std::cout << "指针之间的距离为：" << d << "\n";
	}

	





};


