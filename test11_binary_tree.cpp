#include<iostream>
#include<fstream>
#include<string>
#include<algorithm> // min��max���ڵİ�

// �����������㷨
// ��Դ��
//https://www.cnblogs.com/nibolyoung/p/11692023.html

/*
// �������ṹ��
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {} // �ṹ���еķ�����C�����в�����
}; // ����treeNode�ᱨ��*/


class BinaryTree
{
	//struct TreeNode treeNode; // ʵ�����ṹ��

	// �������ṹ��
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {} // �ṹ���еķ�����C�����в�����
	}treeNode; // ����treeNode�ᱨ��
	
public:

	// �Զ��幹�캯��
	BinaryTree();

	// �������еĽṹ��
	void testStruct()
	{
		std::cout << "123";
		//treeNode.val; // ���ýṹ������
	}



	// ���������������
	int maxDepth(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return std::max(left, right) + 1;
	}




};
