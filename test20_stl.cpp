#include <iostream>
#include <string>
#include <vector>


// 教程网址
// http://c.biancheng.net/stl/

// STL是容器的集合，也是组件的集合。
// 容器包括list, vector向量, set, map 等
// 组件包括容器，迭代器，算法，仿函数
// 容器 - 存储并管理某类对象的集合。容器分为序列容器和关联容器
// 迭代器 - 在一个对象集群上进行遍历。迭代器分两类，双向迭代器和随机存取迭代器
// 算法 - 算法用于处理集群内的元素，可实现搜寻，排序，修改，使用
// 仿函数 - 具有泛型编程强大的威力，是纯粹抽象的例证


using namespace std;
const int NUM = 5;
int main20()
{
	// 向量
	vector <string>names(NUM);    //定义矢量对象
	vector <int> sexs(NUM);    //同上
	cout << "Please Do Exactly As Told You Will enter \n" << NUM << " Personal Name and Their Sex.\n";
	int i = 0;
	for (i = 0; i < NUM; i++)    //输入信息
	{
		cout << "Enter title # " << i + 1 << ": ";
		getline(cin, names[i]); //获取输入信息
		cout << "Enter sex (0/1) #";
		cin >> sexs[i];    //获取输入信息
		cin.get();    //等待
	}
	cout << "Thank you. You entered the following:    \n" << "name/sex" << endl;
	for (i = 0; i < NUM; i++)    //输出信息
	{
		cout << names[i] << "\t" << sexs[i] << endl;
	}
	return 0;
}