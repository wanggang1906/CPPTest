#include<iostream>
#include<fstream>
#include<string>
#include<algorithm> // min��max���ڵİ�

// ��Դ��
//https://www.cnblogs.com/nibolyoung/p/11692023.html


// �������ṹ��
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; // ����treeNode�ᱨ��


class BinaryTree
{
	
public:

	// ���������������
	int maxDepth(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return std::max(left, right) + 1;
	}




};
