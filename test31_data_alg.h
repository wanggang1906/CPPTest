#pragma once
#include<iostream>


//#ifndef _test31_da_H_  // �������룬ֻ����һ��
//#define _test31_da_H_



class test31_data_alg
{
public:

	// ��������ڵ�
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

	 //ͼ
//#define MaxVertexNum 10000//��ඥ�㣨��㣩��
//#define MaxDistance 6//BFS���������������������Ĳ���
//#define DefaultWeight 1//�ޱߵ�Ȩ��Ҫ����Ĭ��Ϊ1
//#define QERROR 0//���з�������
//
//	typedef int Vertex;//�ö����±��ʾ����
//	typedef int WeightType;//�ߵ�Ȩ��
//
//	//����ͼ�ı�
//	typedef struct ENode* PtrToENode;
//	struct ENode {
//		Vertex V1, V2; //�����<V1,V2>
//		WeightType Weight;//Ȩ��
//	};
//	typedef PtrToENode Edge;
//
//	//�ڽӵ�Ķ���
//	typedef struct AdjVNode* PtrToAdjVNode;
//	struct AdjVNode {
//		Vertex AdjV; //�ڽӵ���±�
//		WeightType Weight;//��Ȩ��
//		PtrToAdjVNode Next;//ָ����һ���ڽӵ��ָ��
//	};
//
//	//�����ͷ�Ķ���
//	typedef struct Vnode {
//		PtrToAdjVNode FirstEdge;//���ͷָ��
//	} AdjList[MaxVertexNum];//AdjList���ڽӱ�����
//
//	//ͼ���Ķ���
//	typedef struct GNode* PtrToGNode;
//	struct GNode {
//		int Nv;//������
//		int Ne;//����
//		bool* visited;//���㱻����״̬�����ָ��
//		AdjList G;//�ڽӱ�
//	};
//	typedef PtrToGNode LGraph;//���ڽӱ�ʽ�洢��ͼ����
//
//	//���еĽ�㶨��
//	typedef struct Node* PtrToNode;
//	struct Node {
//		Vertex Data;//���н��洢������
//		PtrToNode Next;//ָ����һ�����н���ָ��
//	};
//	typedef PtrToNode Position;
//
//	//���еĶ���
//	struct QNode {
//		Position Front, Rear;//���е�ͷ����β���
//		int MaxSize;//���е����ɴ洢��С
//	};
//	typedef struct QNode* Queue;//���������ʽʵ�ֶ���
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

