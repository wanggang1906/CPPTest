#pragma once
#include<iostream>

class test13_sqlist

typedef int ElemType; // �κ��������������ǰ�����typedef֮��ԭ���Ǳ����Ķ����һ�����͡�������������еı�ʶ���ų������м仹�����
// auto int ElemType;


//��ʼ��
typedef struct {
	ElemType data[10]; //������Ա��������
	int length;//������Ա�ĳ���
}SqList;

{
public:
	void CreatSqList(SqList*& L, ElemType a[], int n);
	void sqlistMain();

};

