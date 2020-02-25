#pragma once

#include<iostream>
#include<string>

#ifndef _test06_oop_H_ // 开头和结尾加上，表示预编译
#define _test06_oop_H_ // 宏定义

class DataStructuresAndAlgorithms
{
public:
	//int sa[] = {1,2,3,4,5,6,7,5 };

	void insertSort(int a[], int n);

	void shellSort(int a[], int n);

	void selectSort(int a[], int n);

	void createHeap(int a[], int s, int n);

	void heapSort(int a[], int n);

	void bubbleSort(int a[], int n);

	int devideData(int a[], int left, int right);

	void quickSort(int a[], int left, int right);

	void mergeTwoSortedSeq(int a[], int r[], int s, int m, int n);

	void mergeTwo(int a[], int r[], int n, int len);
	
	void mergeSrot(int a[], int n);

	void printData(int a[], int n);

	void testSort();
	



};



#endif
