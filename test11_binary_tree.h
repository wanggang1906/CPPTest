#pragma once // ��ʾ���ļ�ֻ����һ��

#include<iostream>
#include<string>

#ifndef _test11_binary_tree_H_ // ��ͷ�ͽ�β���ϣ���ʾԤ���룬Ҳ��������������
#define _test11_binary_tree_H_

class BinaryTree
{
public:
	// �������ṹ��
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	BinaryTree();

	void testStruct();

	// ���������������
	int maxDepth(TreeNode* root);




};



#endif
