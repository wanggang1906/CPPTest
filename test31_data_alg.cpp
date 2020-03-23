
#include "test31_data_alg.h" // ����д����������ͷ�ļ�
#include<iostream>


// �ඨ����ʵ��������д��
// cpp�ļ�ֻд���ʵ�֣���ͨ����������ʵ�ֵ�
// h�ļ�ֻд��Ķ��壬�ڶ���ļ�������ʱ������ֻ����һ�Σ�����ʱҲֻ����ͷ�ļ�

/**

// ���ݽṹ��������
void test31_data_alg::dataAlgMain()
{
	this->classTest();
	std::cout << "����" << "\n";
	this->testListMain();
}

// ���Է���
void test31_data_alg::classTest()
{
	
	std::cout << "���з���" << "\n";
};

// ��������ڵ�
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

// ʹ����������
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

// ��ӡ����
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

// ��������
void test31_data_alg::testListMain()
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(int);
	ListNode* head = this->createLinkedList(arr, n);
	this->printListNode(head);

}

*/