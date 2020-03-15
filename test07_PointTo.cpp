#include<iostream>


// 指针的四个问题

// 指针的类型 --- 把指针声明里的指针名字去掉，剩下的部分是指针的类型
// 指针所指向的类型 --- 当你通过指针来访问指针所指向的内存区时，指针所指向的类型决定了编译器将把那片内存区里的内容当做什么来看待。
// 指针本身的值 --- 
// 指针所指向的内存区域的值

// 类的声明在头文件中，类的实现在cpp文件中，在main中要引入头文件
class PointTo {
public: // 公开的属性和方法
	void pointTest() {
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
		printf("/n指针实验---"+1); // 是否可以输出不同类型数据
		
		int *p;
		int s = 10;
		std::cout <<"指针的大小："<<sizeof(p)<<"_"<<s; // 输出流可以输出不同类型的数据

		int *ps[3];

		std::cout <<"ps的地址是"<<&ps;
		std::cout << "测试结束";
	}





};


