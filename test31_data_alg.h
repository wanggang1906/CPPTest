#pragma once
#include<iostream>


//#ifndef _test31_da_H_  // 条件编译，只编译一次
//#define _test31_da_H_



class test31_data_alg
{
public:

	// 定义链表节点
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(NULL) {}
	};

	void classTest();

	void dataAlgMain();




	ListNode* createLinkedList(int arr[], int n);
	void printListNode(ListNode* head);
	void testListMain();

	 //图
//#define MaxVertexNum 10000//最多顶点（结点）数
//#define MaxDistance 6//BFS广度优先搜索允许遍历到的层数
//#define DefaultWeight 1//无边的权重要求，则默认为1
//#define QERROR 0//队列发生错误
//
//	typedef int Vertex;//用顶点下标表示顶点
//	typedef int WeightType;//边的权重
//
//	//定义图的边
//	typedef struct ENode* PtrToENode;
//	struct ENode {
//		Vertex V1, V2; //有向边<V1,V2>
//		WeightType Weight;//权重
//	};
//	typedef PtrToENode Edge;
//
//	//邻接点的定义
//	typedef struct AdjVNode* PtrToAdjVNode;
//	struct AdjVNode {
//		Vertex AdjV; //邻接点的下标
//		WeightType Weight;//边权重
//		PtrToAdjVNode Next;//指向下一个邻接点的指针
//	};
//
//	//顶点表头的定义
//	typedef struct Vnode {
//		PtrToAdjVNode FirstEdge;//变表头指针
//	} AdjList[MaxVertexNum];//AdjList是邻接表类型
//
//	//图结点的定义
//	typedef struct GNode* PtrToGNode;
//	struct GNode {
//		int Nv;//顶点数
//		int Ne;//边数
//		bool* visited;//顶点被访问状态数组的指针
//		AdjList G;//邻接表
//	};
//	typedef PtrToGNode LGraph;//以邻接表方式存储的图类型
//
//	//队列的结点定义
//	typedef struct Node* PtrToNode;
//	struct Node {
//		Vertex Data;//队列结点存储的数据
//		PtrToNode Next;//指向下一个队列结点的指针
//	};
//	typedef PtrToNode Position;
//
//	//队列的定义
//	struct QNode {
//		Position Front, Rear;//队列的头结点和尾结点
//		int MaxSize;//队列的最大可存储大小
//	};
//	typedef struct QNode* Queue;//以链表的形式实现队列
//
//
//	LGraph CreateGraph(int Nv);
//	void InsertEdge(LGraph Graph, Edge E);
//	void BFSToSix(LGraph Graph);
//	int BFS(LGraph Graph, Vertex v);
//	Queue CreateQueue(int MaxSize);
//	bool QIsEmpty(Queue Q);
//	Vertex DeleteQ(Queue Q);
//	void AddQ(Queue Q, Vertex v);
//	int mainGraph();


};



//#endif

