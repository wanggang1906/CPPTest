// 数据结构与算法

/*
1.插入排序
时间复杂度：平均O(n2)，最好O(n)，最坏O(n2)
空间复杂度：O(1)
稳定性：稳定
*/
void insertSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}