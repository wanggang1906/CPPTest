#include "test13_sqlist.h"


#include<stdio.h>
#include<malloc.h>


#define maxSize 10;
/*线性表的头插法和尾插法*/
//线性表的创建（头插法和尾插法）和初始化
typedef int ElemType;
//初始化
typedef struct {
	ElemType data[10]; //存放线性表的数据域
	int length;//存放线性表的长度
}SqList;

//创建线性表
//建立线性表
void test13_sqlist::CreatSqList(SqList *&L, ElemType a[], int n) {

	//给线性表进行申请空间
	L = (SqList *)malloc(sizeof(SqList)); // l是一个指针
	for (int i = 0; i < n; i++) {
		L->data = a[i];
		++L->length;
	}
	//输出线性表的长度
	if(L->length > 0) {

		printf("%d",L->length);

	}

}


//1、线性表的头插法



// 2、线性表的尾插法



void test13_sqlist::sqlistMain() {

	/*线性表的增删改查*/
	printf("线性表的增删改查!\n");
	SqList* L;
	int a[] = { 1,2,3,4,5,6 };
	CreatSqList(L, a, 6);


