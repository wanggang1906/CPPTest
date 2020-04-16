
#include "test31_data_alg.h" // ����д����������ͷ�ļ�
#include<iostream>




// �ඨ����ʵ��������д��
// cpp�ļ�ֻд���ʵ�֣���ͨ����������ʵ�ֵ�
// h�ļ�ֻд��Ķ��壬�ڶ���ļ�������ʱ������ֻ����һ�Σ�����ʱҲֻ����ͷ�ļ�

/**

// ���ݽṹ��������
void test31_data_alg::dataAlgMain()
{
	this->classTest();
	std::cout << "����" << "\n";
	this->testListMain();
}

// ���Է���
void test31_data_alg::classTest()
{
	
	std::cout << "���з���" << "\n";
};

// ��������ڵ�
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

// ʹ����������
ListNode* createLinkedList(int arr[], int n)
{
	if (n == 0)
	{
		return NULL;
	}
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; ++i)
	{
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

// ��ӡ����
void test31_data_alg::printListNode(ListNode* head)
{
	ListNode* curNode = head;
	while (curNode)
	{
		std::cout << curNode->val << " -> ";
		curNode = curNode->next;
		return;
	}
}

// ��������
void test31_data_alg::testListMain()
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(int);
	ListNode* head = this->createLinkedList(arr, n);
	this->printListNode(head);

}

**/




//ͼ�ı���
//https://blog.csdn.net/Brianone/article/details/89600374
// ���ȷָ�
/**
#define MaxVertexNum 10000//��ඥ�㣨��㣩��
#define MaxDistance 6//BFS���������������������Ĳ���
#define DefaultWeight 1//�ޱߵ�Ȩ��Ҫ����Ĭ��Ϊ1
#define QERROR 0//���з�������

typedef int Vertex;//�ö����±��ʾ����
typedef int WeightType;//�ߵ�Ȩ��

//����ͼ�ı�
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1, V2; //�����<V1,V2>
    WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV; //�ڽӵ���±�
    WeightType Weight;//��Ȩ��
    PtrToAdjVNode Next;//ָ����һ���ڽӵ��ָ��
};

//�����ͷ�Ķ���
typedef struct Vnode {
    PtrToAdjVNode FirstEdge;//���ͷָ��
} AdjList[MaxVertexNum];//AdjList���ڽӱ�����

//ͼ���Ķ���
typedef struct GNode* PtrToGNode;
struct GNode {
    int Nv;//������
    int Ne;//����
    bool* visited;//���㱻����״̬�����ָ��
    AdjList G;//�ڽӱ�
};
typedef PtrToGNode LGraph;//���ڽӱ�ʽ�洢��ͼ����

//���еĽ�㶨��
typedef struct Node* PtrToNode;
struct Node {
    Vertex Data;//���н��洢������
    PtrToNode Next;//ָ����һ�����н���ָ��
};
typedef PtrToNode Position;

//���еĶ���
struct QNode {
    Position Front, Rear;//���е�ͷ����β���
    int MaxSize;//���е����ɴ洢��С
};
typedef struct QNode* Queue;//���������ʽʵ�ֶ���

// ��������
//LGraph CreateGraph(int Nv);
//void InsertEdge(LGraph Graph, Edge E);
//void BFSToSix(LGraph Graph);
//int BFS(LGraph Graph, Vertex v);
//Queue CreateQueue(int MaxSize);
//bool QIsEmpty(Queue Q);
//Vertex DeleteQ(Queue Q);
//void AddQ(Queue Q, Vertex v);

int test31_data_alg::mainGraph()
{
    
    //��������
   
    
    //��ʽӦ��
    int N, M;
    LGraph Graph;
    Edge E;

    cin >> N; //����������
    Graph = CreateGraph(N); //�����ޱ�ͼ

    cin >> M; //����ߵĸ���
    E = new ENode;
    for (int i = 0; i < M; i++) {
        cin >> E->V1;
        cin >> E->V2;
        E->Weight = DefaultWeight;
        InsertEdge(Graph, E);
    }

    BFSToSix(Graph);//���ȷָ�����ģ��

    return 0;
}


void BFSToSix(LGraph Graph)
{
    int SixVertexNum;
    float percent;
    if (Graph->Nv != 0) {
        for (Vertex v = 1; v < Graph->Nv; v++) {
            //�������ڿɱ������Ķ����������л�Ҫ���Ͻ�㱾��
            SixVertexNum = BFS(Graph, v) + 1;
            //�������ڿɱ������Ķ�����ռ�ܽ�����İٷֱȣ�����1��ʼ����Ҫ��ȥ0������ý�㣩
            percent = float(SixVertexNum) / float(Graph->Nv - 1);
            printf("%d: %.2f%\n", v, percent * 100);
            //��ս�㱻����״̬
            for (int i = 0; i < Graph->Nv; i++) Graph->visited[i] = false;
        }
    }
}

int BFS(LGraph Graph, Vertex v)
{
    PtrToAdjVNode w;
    int D = 0;
    int SixVertexNum = 0;
    Queue Q;

    Q = CreateQueue(MaxVertexNum);//��������

    Graph->visited[v] = true;
    AddQ(Q, v);
    AddQ(Q, 0);//��������е�0�����ڱ�ʾ�µ�һ��Ŀ�ʼ
    ++D;//���ڵĲ���
    while (!QIsEmpty(Q)) {
        v = DeleteQ(Q);
        if (v == 0 && D >= MaxDistance) break; //��ʾ�����ѳ���6
        if (v == 0 && D < MaxDistance) {//������δ����6
            AddQ(Q, 0);
            ++D;
            continue;
        }
        for (w = Graph->G[v].FirstEdge; w != NULL; w = w->Next) {

            if (!Graph->visited[w->AdjV]) {
                Graph->visited[w->AdjV] = true;
                AddQ(Q, w->AdjV);
                ++SixVertexNum;
            }
        }
    }
    return SixVertexNum;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;

    ++Graph->Ne;
    //����<V1,V2>
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //����<V2,V1>
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph CreateGraph(int N)
{
    LGraph Graph;

    Graph = new GNode;
    Graph->Nv = N + 1; //����1��ʼ
    Graph->Ne = 0;
    Graph->visited = new bool[N + 1];

    for (int i = 1; i < Graph->Nv; i++) Graph->visited[i] = false;

    for (int v = 1; v < Graph->Nv; v++) Graph->G[v].FirstEdge = NULL;

    return Graph;
}

Queue CreateQueue(int MaxSize)
{
    Queue Q;
    Q = new QNode;
    Q->Front = Q->Rear = NULL;
    Q->MaxSize = MaxSize;
    return Q;
}

bool QIsEmpty(Queue Q)
{
    return (Q->Front == NULL);
}

void AddQ(Queue Q, Vertex v)
{
    Position NewNode;
    NewNode = new Node;
    NewNode->Data = v;
    NewNode->Next = NULL;

    if (QIsEmpty(Q)) {
        Q->Front = NewNode;
        Q->Rear = NewNode;
    }
    else {
        Q->Rear->Next = NewNode;
        Q->Rear = NewNode;
    }
}

Vertex DeleteQ(Queue Q)
{
    Position FrontNode;
    Vertex FrontData;

    if (QIsEmpty(Q)) {
        return QERROR;
    }
    else {
        FrontNode = Q->Front;
        if (Q->Front == Q->Rear)
            Q->Front = Q->Rear = NULL;
        else
            Q->Front = Q->Front->Next;

        FrontData = FrontNode->Data;
        delete FrontNode;
        return FrontData;
    }

}
**/

