#pragma once // 表示此文件只编译一次

#include<iostream>
#include<string>

#ifndef _test11_binary_tree_H_ // 开头和结尾加上，表示预编译，也可以是条件编译
#define _test11_binary_tree_H_

class BinaryTree
{
public:
	// 定义树结构体
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	BinaryTree();

	void testStruct();

	// 求二叉树的最大深度
	int maxDepth(TreeNode* root);




};



#endif
