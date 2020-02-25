#pragma once

#include<iostream>
#include<string>

#ifndef _test06_oop_H_ // 开头和结尾加上，表示预编译


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



	// 求二叉树的最大深度
	int maxDepth(TreeNode* root);




};



#endif
