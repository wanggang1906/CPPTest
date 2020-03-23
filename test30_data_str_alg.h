#pragma once
#include<iostream>
#include<fstream>

#ifndef _test30_da_H_ 
#define _test30_da_H_

class DataStructuresAndAlgorithms30
{




	
public:
	
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(NULL) {}
	};
	


	void test();
	void DAMain();
	ListNode* createLinkedList(int arr[], int n);
	void printListNode(ListNode* head);
	void printListNode(ListNode* head);
	void testListMain();
	

/*
private:
	struct TestStruce
	{
		std::string name;
		int age;
	};
	*/


};

#endif
