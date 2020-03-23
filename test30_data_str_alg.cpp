#include <iostream>
#include <string>
#include<fstream>



// ������ǰ��
class DataStructuresAndAlgorithms30;


//void test();
//void DAMain();



// ���ݽṹ���㷨ʵ��
class DataStructuresAndAlgorithms30
{
public:
	// ��������
	void DAMain()
	{
		this->test();
		this->testListMain();
	}


	void test() {
		//TestStruce ts;
		//ts.name = "��";
		//ts.age = 10;

		std::cout << "ֵ��" << "ts.name" << "\n";
	}
/*
private:
	struct TestStruce
	{
		std::string name;
		int age;
	};
	*/

	// ����ڵ�
	
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(NULL) {}
	};
	

	// ʹ����������
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

	// ��ӡ����
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

	// ��������
	void testListMain()
	{
		int arr[] = { 1,2,3,4,5 };
		int n = sizeof(arr) / sizeof(int);
		ListNode* head = this->createLinkedList(arr, n);
		this->printListNode(head);
		std::cout << "�����ӡ������" << "\n";

	}
};