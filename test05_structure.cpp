#include<iostream>


// 结构体
// .和 -> 的区别，如结构变量时用. 指针指向时用 -> 
int structureTest()
{
	struct FishOil
	{
		std::string name; // 字符串对象
		int age;
		char sex;
	};
	return 0;
}


// 交换两个数
void jiaoHuan() {
	int s = 1;
	int d = 2;
	//swap(&s, &d);
}

	void swap(int* x, int* y) {
		*x ^= *y;
		*y ^= *x; // 异或操作
		*x ^= *y;
	}
