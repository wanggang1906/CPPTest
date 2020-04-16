
#include "test31_data_alg.h" // 分离写法必须引入头文件
#include<iostream>




// 类定义与实现相分离的写法
// cpp文件只写类的实现，是通过内联函数实现的
// h文件只写类的定义，在多个文件中引用时编译器只编译一次，引用时也只包含头文件

/**

// 数据结构类主方法
void test31_data_alg::dataAlgMain()
{
	this->classTest();
	std::cout << "链表：" << "\n";
	this->testListMain();
}

// 测试方法
void test31_data_alg::classTest()
{
	
	std::cout << "类中方法" << "\n";
};

// 定义链表节点
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

// 使用数组链表
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

// 打印链表
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

// 测试链表
void test31_data_alg::testListMain()
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(int);
	ListNode* head = this->createLinkedList(arr, n);
	this->printListNode(head);

}

**/




//图的遍历
//https://blog.csdn.net/Brianone/article/details/89600374
// 六度分隔
/**
#define MaxVertexNum 10000//最多顶点（结点）数
#define MaxDistance 6//BFS广度优先搜索允许遍历到的层数
#define DefaultWeight 1//无边的权重要求，则默认为1
#define QERROR 0//队列发生错误

typedef int Vertex;//用顶点下标表示顶点
typedef int WeightType;//边的权重

//定义图的边
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1, V2; //有向边<V1,V2>
    WeightType Weight;//权重
};
typedef PtrToENode Edge;

//邻接点的定义
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV; //邻接点的下标
    WeightType Weight;//边权重
    PtrToAdjVNode Next;//指向下一个邻接点的指针
};

//顶点表头的定义
typedef struct Vnode {
    PtrToAdjVNode FirstEdge;//变表头指针
} AdjList[MaxVertexNum];//AdjList是邻接表类型

//图结点的定义
typedef struct GNode* PtrToGNode;
struct GNode {
    int Nv;//顶点数
    int Ne;//边数
    bool* visited;//顶点被访问状态数组的指针
    AdjList G;//邻接表
};
typedef PtrToGNode LGraph;//以邻接表方式存储的图类型

//队列的结点定义
typedef struct Node* PtrToNode;
struct Node {
    Vertex Data;//队列结点存储的数据
    PtrToNode Next;//指向下一个队列结点的指针
};
typedef PtrToNode Position;

//队列的定义
struct QNode {
    Position Front, Rear;//队列的头结点和尾结点
    int MaxSize;//队列的最大可存储大小
};
typedef struct QNode* Queue;//以链表的形式实现队列

// 声明方法
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
    
    //测试用例
   
    
    //正式应用
    int N, M;
    LGraph Graph;
    Edge E;

    cin >> N; //输入结点总数
    Graph = CreateGraph(N); //创建无边图

    cin >> M; //输入边的个数
    E = new ENode;
    for (int i = 0; i < M; i++) {
        cin >> E->V1;
        cin >> E->V2;
        E->Weight = DefaultWeight;
        InsertEdge(Graph, E);
    }

    BFSToSix(Graph);//六度分隔理论模拟

    return 0;
}


void BFSToSix(LGraph Graph)
{
    int SixVertexNum;
    float percent;
    if (Graph->Nv != 0) {
        for (Vertex v = 1; v < Graph->Nv; v++) {
            //在六步内可遍历到的顶点数（其中还要加上结点本身）
            SixVertexNum = BFS(Graph, v) + 1;
            //在六步内可遍历到的顶点数占总结点数的百分比（结点从1开始，需要减去0这个无用结点）
            percent = float(SixVertexNum) / float(Graph->Nv - 1);
            printf("%d: %.2f%\n", v, percent * 100);
            //清空结点被遍历状态
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

    Q = CreateQueue(MaxVertexNum);//创建队列

    Graph->visited[v] = true;
    AddQ(Q, v);
    AddQ(Q, 0);//插入队列中的0，用于表示新的一层的开始
    ++D;//所在的层数
    while (!QIsEmpty(Q)) {
        v = DeleteQ(Q);
        if (v == 0 && D >= MaxDistance) break; //表示层数已超过6
        if (v == 0 && D < MaxDistance) {//层数还未超过6
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
    //插入<V1,V2>
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //插入<V2,V1>
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
    Graph->Nv = N + 1; //结点从1开始
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

