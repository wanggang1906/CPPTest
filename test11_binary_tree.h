#pragma once

#include<iostream>
#include<string>

#ifndef _test06_oop_H_ // ��ͷ�ͽ�β���ϣ���ʾԤ����


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



	// ���������������
	int maxDepth(TreeNode* root);




};



#endif
