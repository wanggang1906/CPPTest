#include "test32_alg_of_dj.h"

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define Inf 0x3f3f3f3f // 十进制是1061109567，是10^9级别的，表示无穷大，
					   // 每个字节都是0x3f！所以要把一段内存全部置为无穷大，我们只需要memset(a,0x3f,sizeof(a))


// 来源
// https://blog.csdn.net/lbperfect123/article/details/84281300


using namespace std;

int map[1005][1005]; // 

int vis[1005], dis[1005]; // 
int n, m; // n个点，m条边

// 初始化，节点，边矩阵的对角线置0
void test32_alg_of_dj::Init()
{
	memset(map, Inf, sizeof(map)); // 以字节为单位初始化内存块
	for (int i = 1; i <= n; i++)
	{
		map[i][i] = 0; // 边矩阵的对角线置0，自身到自身的距离为0
	}
}

// 设置边的权重
void test32_alg_of_dj::Getmap()
{
	int u, v, w; // 
	for (int t = 1; t <= m; t++)
	{
		printf("输入边的始末节点和权重：");
		scanf_s("%d%d%d", &u, &v, &w); // 代替scanf
		if (map[u][v] > w) // 
		{
			map[u][v] = w; // 无向图的邻接矩阵
			map[v][u] = w; // 是对称矩阵
		}
	}

}

// dj算法，n是单源最短路的起点
void test32_alg_of_dj::Dijkstra(int u)
{
	memset(vis, 0, sizeof(vis)); // 以字节为单位初始化内存块
	for (int t = 1; t <= n; t++)
	{
		dis[t] = map[u][t];
	}
	vis[u] = 1;
	for (int t = 1; t < n; t++)
	{
		int minn = Inf, temp;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && dis[i] < minn)
			{
				minn = dis[i];
				temp = i;
			}
		}
		vis[temp] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (map[temp][i] + dis[temp] < dis[i])
			{
				dis[i] = map[temp][i] + dis[temp];
			}
		}
	}

}

int test32_alg_of_dj::main32()
{
	printf("输入边数m，和点数n:");
	scanf_s("%d%d", &m, &n); // 代替scanf
	this->Init();
	this->Getmap();
	this->Dijkstra(n);
	printf("%d\n", dis[1]);


	return 0;
}

