#include<iostream>
#include<fstream>
#include<string>
#include<algorithm> // min，max所在的包

// 二叉树常用算法
// 来源：
//https://www.cnblogs.com/nibolyoung/p/11692023.html

/*
// 定义树结构体
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {} // 结构体中的方法，C语言中不允许
}; // 加入treeNode会报错*/


class BinaryTree
{
	//struct TreeNode treeNode; // 实例化结构体

	// 定义树结构体
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {} // 结构体中的方法，C语言中不允许
	}treeNode; // 加入treeNode会报错
	
public:

	// 自定义构造函数
	BinaryTree();

	// 测试类中的结构体
	void testStruct()
	{
		std::cout << "123";
		//treeNode.val; // 引用结构体内容
	}



	// 求二叉树的最大深度
	int maxDepth(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return std::max(left, right) + 1;
	}




};
