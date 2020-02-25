#include<iostream>
#include<fstream>
#include<string>
#include<algorithm> // min，max所在的包

// 来源：
//https://www.cnblogs.com/nibolyoung/p/11692023.html


// 定义树结构体
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; // 加入treeNode会报错


class BinaryTree
{
	
public:

	// 求二叉树的最大深度
	int maxDepth(TreeNode* root) {
		if (root == NULL)  return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return std::max(left, right) + 1;
	}




};
