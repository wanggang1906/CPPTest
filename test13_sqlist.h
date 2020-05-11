#pragma once
#include<iostream>

class test13_sqlist

typedef int ElemType; // 任何声明变量的语句前面加上typedef之后，原来是变量的都变成一种类型。不管这个声明中的标识符号出现在中间还是最后
// auto int ElemType;


//初始化
typedef struct {
	ElemType data[10]; //存放线性表的数据域
	int length;//存放线性表的长度
}SqList;

{
public:
	void CreatSqList(SqList*& L, ElemType a[], int n);
	void sqlistMain();

};

