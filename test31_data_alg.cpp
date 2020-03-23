
#include "test31_data_alg.h" // 分离写法必须引入头文件
#include<iostream>


// 类定义与实现相分离的写法
// cpp文件只写类的实现，是通过内联函数实现的
// h文件只写类的定义，在多个文件中引用时编译器只编译一次，引用时也只包含头文件

/**

// 数据结构类主方法
void test31_data_alg::dataAlgMain()
{
	this->classTest();
	std::cout << "链表：" << "\n";
	this->testListMain();
}

// 测试方法
void test31_data_alg::classTest()
{
	
	std::cout << "类中方法" << "\n";
};

// 定义链表节点
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

// 使用数组链表
ListNode* test31_data_alg::createLinkedList(int arr[], int n)
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
void test31_data_alg::printListNode(ListNode* head)
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
void test31_data_alg::testListMain()
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(int);
	ListNode* head = this->createLinkedList(arr, n);
	this->printListNode(head);

}

*/