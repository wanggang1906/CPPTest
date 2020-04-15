#include "test32_alg_of_dj.h"

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define Inf 0x3f3f3f3f // ʮ������1061109567����10^9����ģ���ʾ�����
					   // ÿ���ֽڶ���0x3f������Ҫ��һ���ڴ�ȫ����Ϊ���������ֻ��Ҫmemset(a,0x3f,sizeof(a))


// ��Դ
// https://blog.csdn.net/lbperfect123/article/details/84281300


using namespace std;

int map[1005][1005]; // 

int vis[1005], dis[1005]; // 
int n, m; // n���㣬m����

// ��ʼ�����ڵ㣬�߾���ĶԽ�����0
void test32_alg_of_dj::Init()
{
	memset(map, Inf, sizeof(map)); // ���ֽ�Ϊ��λ��ʼ���ڴ��
	for (int i = 1; i <= n; i++)
	{
		map[i][i] = 0; // �߾���ĶԽ�����0����������ľ���Ϊ0
	}
}

// ���ñߵ�Ȩ��
void test32_alg_of_dj::Getmap()
{
	int u, v, w; // 
	for (int t = 1; t <= m; t++)
	{
		printf("����ߵ�ʼĩ�ڵ��Ȩ�أ�");
		scanf_s("%d%d%d", &u, &v, &w); // ����scanf
		if (map[u][v] > w) // 
		{
			map[u][v] = w; // ����ͼ���ڽӾ���
			map[v][u] = w; // �ǶԳƾ���
		}
	}

}

// dj�㷨��n�ǵ�Դ���·�����
void test32_alg_of_dj::Dijkstra(int u)
{
	memset(vis, 0, sizeof(vis)); // ���ֽ�Ϊ��λ��ʼ���ڴ��
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
	printf("�������m���͵���n:");
	scanf_s("%d%d", &m, &n); // ����scanf
	this->Init();
	this->Getmap();
	this->Dijkstra(n);
	printf("%d\n", dis[1]);


	return 0;
}

