// 数据结构与算法

#include<iostream>
#include<fstream>
#include<string>

class DataStructuresAndAlgorithms
{
public:
	// 算法思想：
	// https://blog.csdn.net/weixin_41190227/article/details/86600821


/*
1.插入排序
思想：扫描未排序的插入排序好的序列中，采用O(1)的空间复杂度，把排好序的元素逐个向后移动
时间复杂度：平均O(n2)，最好O(n)，最坏O(n2)
空间复杂度：O(1)
稳定性：稳定
*/
void insertSort(int a[], int n)
{
	std::cout << "插入排序 \n";
	int i, j, t;
	// 已排好的序列
	int sortList[7] = {}; // 数组大小固定，不能用n，因为n的值可通过指针改变，是变量
	for (i = 1; i < n; i++) // 循环不从第一个开始，第一个默认有序，从第二个元素开始进行插入
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)
		{
			a[j + 1] = a[j];
			a[j + 1] = t;
		}
		sortList[i] = a[i]; // i是内存地址
		std::cout << "已排序好的序列：" << sortList[i] << "\n";
	}
	std::cout << "结束";
}

/*
2.希尔排序
时间复杂度：平均O(n1.3)，最好O(n)，最坏O(n2)
空间复杂度：O(1)
稳定性：不稳定
*/
void shellSort(int a[], int n)
{
	int d, i, j, x;
	d = n / 2;//增量
	while (d >= 1)//循环至增量为1时结束
	{
		for (i = d; i < n; i++)
		{
			x = a[i];//序列中下一个数据
			j = i - d;//序列中前一个数据的序号
			while (j >= 0 && a[j] > x)//下一个数大于前一个数
			{
				a[j + d] = a[j];//将后一个数向前移动
				j = j - d;//修改序号，继续向前移动
			}
			a[j + d] = x;//保存数据
		}
		d = d / 2;//缩小增量
	}
}


/*
3.选择排序
时间复杂度：平均O(n2)，最好O(n2)，最坏O(n2)
空间复杂度：O(1)
稳定性：不稳定
*/
void selectSort(int a[], int n)
{
	int t, k;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
}


/*
4.堆排序
时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(nlogn)
空间复杂度：O(1)
稳定性：不稳定
*/
void createHeap(int a[], int s, int n)
{
	//构成堆
	//s根节点序号
	//长度
	int j, t;
	while (2 * s + 1 < n)//第s个节点有右子树
	{
		j = 2 * s + 1;
		if ((j + 1) < n)
		{
			if (a[j] < a[j + 1])//左子树小于右子树，需要比较右子树
				j++;
		}
		if (a[s] < a[j])
		{
			t = a[s];
			a[s] = a[j];
			a[j] = t;
			s = j;//堆被破坏，需要重新调整
		}
		else
		{
			break;
		}
	}
}
void heapSort(int a[], int n)
{
	int t;
	int j;
	for (int i = n / 2 - 1; i >= 0; i--)//将a[0,n-1]建成大根堆
	{
		createHeap(a, i, n);
	}
	for (int i = n - 1; i > 0; i--)
	{
		t = a[0];//与第i个记录交换
		a[0] = a[i];
		a[i] = t;
		createHeap(a, 0, i);//将a[0]与a[i]重新调整为堆
	}
}


/*
5.冒泡排序
时间复杂度：平均O(n2)，最好O(n)，最坏O(n2)
空间复杂度：O(1)
稳定性：稳定
*/
void bubbleSort(int a[], int n)
{
	int tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}


/*
6.快速排序
时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(n2)
空间复杂度：O(nlogn)
稳定性：不稳定
*/
int devideData(int a[], int left, int right)
{
	int base = a[left];
	while (left < right)
	{
		while (left<right && a[right]>base)
			right--;
		a[left] = a[right];
		while (left < right && a[left] < base)
			left++;
		a[right] = a[left];
	}
	a[left] = base;
	return left;
}
void quickSort(int a[], int left, int right)
{
	int i;
	if (left < right)
	{
		i = devideData(a, left, right);
		quickSort(a, left, i - 1);
		quickSort(a, i + 1, right);
	}
}


/*
7.归并排序
时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(nlogn)
空间复杂度：O(1)
稳定性：稳定
*/
void mergeTwoSortedSeq(int a[], int r[], int s, int m, int n)
{
	//相邻两个有序序列的合并
	//a 数组
	//s序列起始序号
	//m第一个序列的结束后序号
	//n第二个序列结束序号
	int i, j, k;
	k = s;
	i = s;
	j = m + 1;
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			r[k++] = a[i++];
		else
			r[k++] = a[j++];

	}
	while (i <= m)
		r[k++] = a[i++];
	while (j <= n)
		r[k++] = a[j++];

}
void mergeTwo(int a[], int r[], int n, int len)
{//完成一次长度为n的合并
	int s = 0, e;
	while (s + len < n)//至少有两个有序段
	{
		e = s + 2 * len - 1;
		if (e >= n)
			e = n - 1;
		mergeTwoSortedSeq(a, r, s, s + len - 1, e);
		s = e + 1;
	}
	if (s < n)//还剩一个有序段
	{
		for (; s < n; s++)
		{
			r[s] = a[s];
		}
	}

}
void mergeSrot(int a[], int n)
{
	int* p = new int[n];
	int len = 1;
	int f = 0;
	while (len < n)
	{
		if (f)
			mergeTwo(p, a, n, len);
		else
			mergeTwo(a, p, n, len);
		len *= 2;
		f = 1 - f;
	}
	if (f)
		for (int i = 0; i < n; i++)
			a[i] = p[i];
	delete p;

}


void printData(int a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout<< "结束";
}


void testSort()
{
	int op, a[] = { 3,4,1,6,2,7,5 };
	std::cout << "原始数据:";
	printData(a, 7);
	std::cout << "/n";
	std::cout << "1--插入排序--";
	std::cout << "2--希尔排序--";
	std::cout << "3--选择排序--";
	std::cout << "4--堆排序----";
	std::cout << "5--冒泡排序--";
	std::cout << "6--快速排序--";
	std::cout << "7--归并排序--";
	std::cout << "输入操作";
	std::cin >> op;
	switch (op)
	{
	case 1:
		insertSort(a, 7);
		break;
	case 2:
		shellSort(a, 7);
		break;
	case 3:
		selectSort(a, 7);
		break;
	case 4:
		heapSort(a, 7);
		break;
	case 5:
		bubbleSort(a, 7);
		break;
	case 6:
		quickSort(a, 0, 6);
		break;
	case 7:
		mergeSrot(a, 7);
		break;
	}
	std::cout << "排序后结果:";
	printData(a, 7);
}





};