#include "test13_sqlist.h"


#include<stdio.h>
#include<malloc.h>


#define maxSize 10;
/*���Ա��ͷ�巨��β�巨*/
//���Ա�Ĵ�����ͷ�巨��β�巨���ͳ�ʼ��
typedef int ElemType;
//��ʼ��
typedef struct {
	ElemType data[10]; //������Ա��������
	int length;//������Ա�ĳ���
}SqList;

//�������Ա�
//�������Ա�
void test13_sqlist::CreatSqList(SqList *&L, ElemType a[], int n) {

	//�����Ա��������ռ�
	L = (SqList *)malloc(sizeof(SqList)); // l��һ��ָ��
	for (int i = 0; i < n; i++) {
		L->data = a[i];
		++L->length;
	}
	//������Ա�ĳ���
	if(L->length > 0) {

		printf("%d",L->length);

	}

}


//1�����Ա��ͷ�巨



// 2�����Ա��β�巨



void test13_sqlist::sqlistMain() {

	/*���Ա����ɾ�Ĳ�*/
	printf("���Ա����ɾ�Ĳ�!\n");
	SqList* L;
	int a[] = { 1,2,3,4,5,6 };
	CreatSqList(L, a, 6);


