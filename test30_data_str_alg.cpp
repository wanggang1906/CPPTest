#include <iostream>
#include <string>
#include<fstream>



// 类声明前置
class DataStructuresAndAlgorithms30;


//void test();
//void DAMain();



// 数据结构与算法实践
class DataStructuresAndAlgorithms30
{
public:
	// 次主函数
	void DAMain()
	{
		this->test();
		this->testListMain();
	}


	void test() {
		//TestStruce ts;
		//ts.name = "你";
		//ts.age = 10;

		std::cout << "值：" << "ts.name" << "\n";
	}
/*
private:
	struct TestStruce
	{
		std::string name;
		int age;
	};
	*/

	// 链表节点
	
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(NULL) {}
	};
	

	// 使用数组链表
	ListNode* createLinkedList(int arr[], int n)
	{
		if (n == 0)
		{
			return NULL;
		}
		ListNode* head = new ListNode(arr[0]);
		ListNode* curNode = head;
		for (int i = 1; i < n; ++i)
		{
			curNode->next = new ListNode(arr[i]);
			curNode = curNode->next;
		}
		return head;
	}

	// 打印链表
	void printListNode(ListNode* head)
	{
		ListNode* curNode = head;
		while (curNode)
		{
			std::cout << curNode->val << " -> ";
			curNode = curNode->next;
			return;
		}
	}

	// 测试链表
	void testListMain()
	{
		int arr[] = { 1,2,3,4,5 };
		int n = sizeof(arr) / sizeof(int);
		ListNode* head = this->createLinkedList(arr, n);
		this->printListNode(head);
		std::cout << "链表打印结束。" << "\n";

	}
};