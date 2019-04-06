#pragma once
#include "LinkQueue.h"

template<class T, class E>
class Edge
{
public:
	int dest;//�߽��Ķ���;
	E cost;//���ϵ�Ȩֵ;
	Edge<T, E> *link;//��һ��������ָ��;
	Edge() { link = NULL; }//���캯��;
	Edge(int num, E weight) :dest(num), cost(weight), link(NULL) {}//���캯��;
};

template<class T,class E>
class Vertex
{
public:
	Vertex() { adj = NULL; }
	T data;//���������;
	Edge<T, E>* adj;//�������ͷָ��;
};

template<class T,class E>
class graph
{
public:
	graph(int size);//������󶥵���;
	graph();
	~graph();
	bool IsVertex(int value) { return (value >= 0 && value < vertexNum) ? true : false; }//�Ƿ���ڵ�value�����;
	T getValue(int i) { return (IsVertex(i)) ? NodeTable[i].data : NULL; }//��ȡλ��Ϊi�Ķ����е�ֵ;
	T getValue(T& vertex) { return getValue(getVertexPos(vertex)); }
	E getWeight(int value1, int value2);//��ȡ��������֮��ıߵ�Ȩֵ;
	E getWeight(T& vertex1, T& vertex2) { return getWeight(getVertexPos(vertex1), getVertexPos(vertex2)); }
	bool insertVertex(T& vertex);//����һ������,���洢��������鲻����,����������20;
	bool removeVertex(int v);//ɾ������v,����ն���v������;
	bool removeVertex(T& vertex) { return removeVertex(getVertexPos(vertex)); }
	bool insertEdge(int value1, int value2, E weight = 0);//����v1��v2֮��ı�;
	bool insertEdge(T& vertex1, T& vertex2, E weight = 0) { return insertEdge(getVertexPos(vertex1), getVertexPos(vertex2), weight); }
	bool removeEdge(int value1, int value2);//ɾ��v1,v2֮��ı�;
	bool removeEdge(T& vertex1, T& vertex2) { return removeEdge(getVertexPos(vertex1), getVertexPos(vertex2)); }
	int getFirstNeighbor(int v);//ȡ����v�ĵ�һ���ڽӽڵ�;
	int getNextNeighbor(int v, int w);//ȡv���ڽӽڵ�w����һ�ڽӶ���;
	int getVertexPos(const T vertex);//��������vertex��λ��;
	T getVertexName(int i);//��ȡλ��Ϊi�Ķ��������;
	int getNeighborNum(int values);//��ȡvalues���ڽӶ���ĸ���;
	int getAllNeighbor(int value, int* &allNeighbor);//��ȡvalue�������ڽӶ���,����һ������,����Ϊ����ֵ;
	int depthTraverse(int* &allNeighbor, int postion);//ͼ����ȱ���,����ֵΪ����ĳ���;
	int breadthSearch(int* &allNeighbor, int postion);//ͼ�Ĺ�ȱ���,����ֵΪ����ĳ���;
private:
	bool expandSize();//����ǰ����󶥵�������20;
	Vertex<T, E>* NodeTable;//�������������ͷ���;
	int maxsize;//��󶥵���;
	int edgesNum;//��ǰ����;
	int vertexNum;//��ǰ������;
};

template<class T, class E>
inline graph<T, E>::graph(int size)
{
	maxsize = size;
	vertexNum = 0;
	edgesNum = 0;
	NodeTable = new Vertex<T, E>[maxsize];
}

template<class T, class E>
inline graph<T, E>::graph()
{
	maxsize = 20;
	vertexNum = 0;
	edgesNum = 0;
	NodeTable = new Vertex<T, E>[maxsize];
}

template<class T, class E>
inline graph<T, E>::~graph()
{
	while (vertexNum != 0)
		removeVertex(0);
	delete[] NodeTable;
}

template<class T, class E>
inline E graph<T, E>::getWeight(int value1, int value2)
{
	if (!IsVertex(value1) || !IsVertex(value2))
		return false;
	Edge<T, E>* temNode = NodeTable[value1].adj;
	while (temNode != NULL)
	{
		if (temNode->dest == value2)
			return temNode->cost;
		temNode = temNode->link;
	}
	return false;
}

template<class T, class E>
inline bool graph<T, E>::insertVertex(T & vertex)
{
	if (vertexNum > maxsize)
		expandSize();
	NodeTable[vertexNum].data = vertex;
	vertexNum++;
	return true;
}

template<class T, class E>
inline bool graph<T, E>::removeVertex(int v)
{
	if (!IsVertex(v))
		return false;
	if (NodeTable[v].adj != NULL)
	{
		int temporInt = 0;
		while (NodeTable[v].adj != NULL)
		{
			temporInt = NodeTable[v].adj->dest;
			removeEdge(v, temporInt);
		}
	}

	NodeTable[v] = NodeTable[vertexNum - 1];//���������һ������������λ��;
	Edge<T, E>* temNode = NodeTable[v].adj;
	Edge<T, E>* temporNode;
	int temInt = 0;
	while (temNode != NULL)
	{
		temInt = temNode->dest;
		temporNode = NodeTable[temInt].adj;
		while (temporNode != NULL)
		{
			if (temporNode->dest == vertexNum - 1)
			{
				temporNode->dest = v;
				break;
			}
		}
		temNode = temNode->link;
	}
	vertexNum--;
	return true;
}

template<class T, class E>
inline bool graph<T, E>::insertEdge(int value1, int value2, E weight)
{
	if (!IsVertex(value1) || !IsVertex(value2))//���������ǽ��;
		return false;
	Edge<T, E> *one, *two = NodeTable[value1].adj;
	while (two != NULL&&two->dest != value2)
		two = two->link;
	if (two != NULL)//�ҵ��������ߣ�������;
		return false;
	two = new Edge<T, E>;
	two->dest = value1;
	two->cost = weight;
	two->link = NodeTable[value2].adj;
	NodeTable[value2].adj = two;
	one = new Edge<T, E>;
	one->dest = value2;
	one->cost = weight;
	one->link = NodeTable[value1].adj;
	NodeTable[value1].adj = one;
	edgesNum++;
	return true;
}

template<class T, class E>
inline bool graph<T, E>::removeEdge(int value1, int value2)
{
	if (!IsVertex(value1) || !IsVertex(value2))
		return false;

	Edge<T, E>* temNode = NodeTable[value1].adj;
	Edge<T, E>* deleNode;
	if (temNode->dest == value2)
	{
		NodeTable[value1].adj = NodeTable[value1].adj->link;
		delete temNode;
	}
	else
	{
		while (temNode->link != NULL)
		{
			if (temNode->link->dest == value2)
			{
				deleNode = temNode->link;
				temNode->link = temNode->link->link;
				delete deleNode;
				break;
			}
			temNode = temNode->link;
		}
	}
	temNode = NodeTable[value2].adj;
	if (temNode->dest == value1)
	{
		NodeTable[value2].adj = NodeTable[value2].adj->link;
		delete temNode;
	}
	else
	{
		while (temNode->link != NULL)
		{
			if (temNode->link->dest == value1)
			{
				deleNode = temNode->link;
				temNode->link = temNode->link->link;
				delete deleNode;
				break;
			}
			temNode = temNode->link;
		}
	}
	edgesNum--;
	return true;
}

template<class T, class E>
inline int graph<T, E>::getFirstNeighbor(int v)
{
	if (!IsVertex(v))
		return -1;
	else
		if (NodeTable[v].adj != NULL)
			return NodeTable[v].adj->dest;
		else
			return -1;
}

template<class T, class E>
inline int graph<T, E>::getNextNeighbor(int v, int w)
{
	if (!IsVertex(v) || !IsVertex(w))
		return -1;
	else
	{
		Edge<T, E>* temNode = NodeTable[v].adj;
		while (temNode != NULL)
		{
			if (temNode->dest == w)
				return NodeTable[w].adj->dest;
			temNode = temNode->link;
		}
		return -1;
	}
}

template<class T, class E>
inline int graph<T, E>::getVertexPos(const T vertex)
{
	for (int i = 0; i < maxsize; i++)
	{
		if (NodeTable[i].data == vertex)
			return i;
	}
	return -1;
}

template<class T, class E>
inline T graph<T, E>::getVertexName(int i)
{
	if (!IsVertex(i))
		return NULL;
	else
		return NodeTable[i].data;
}

template<class T, class E>
inline int graph<T, E>::getNeighborNum(int values)
{
	if (!IsVertex(values))
		return -1;
	int theSize = 0;
	Edge<T, E>* temNode = NodeTable[values].adj;
	while (temNode != NULL)
	{
		theSize++;
		temNode = temNode->link;
	}
	return theSize;

}

template<class T, class E>
inline int graph<T, E>::getAllNeighbor(int value, int * &allNeighbor)
{
	if (!IsVertex(value))
		return -1;
	int theSize = getNeighborNum(value);
	if (theSize != 0)
	{
		allNeighbor = new int[theSize];
		Edge<T, E>* temNode = NodeTable[value].adj;
		for (int i = 0; i < theSize; i++)
		{
			allNeighbor[i] = temNode->dest;
			temNode = temNode->link;
		}
		return theSize;
	}
	else
		return -1;
}

template<class T, class E>
inline int graph<T, E>::depthTraverse(int *& allNeighbor, int postion)
{
	if (!IsVertex(postion))
		return -1;
	allNeighbor = new int[vertexNum];
	int *temArrary = new int[vertexNum];//��¼�������Ķ��㣬Ϊ-1�������;
	for (int i = 0; i < vertexNum; i++)
		temArrary[i] = i;
	LinkQueue<int> verQueueu;
	int prePos = postion;
	int j = 0;
	Edge<T, E>* temNode = NULL;
	do
	{
		while (temArrary[prePos] != -1)
		{
			allNeighbor[j] = prePos;
			j++;
			temArrary[prePos] = -1;
			temNode = NodeTable[prePos].adj;
			while (temNode != NULL)
			{
				verQueueu.InQueue(temNode->dest);
				temNode = temNode->link;
			}
			if (NodeTable[prePos].adj != NULL)
				prePos = NodeTable[prePos].adj->dest;
			else
				break;
		}
		prePos = verQueueu.OutQueue();
	} while (verQueueu.GetSize() != 0);
	return vertexNum;
}

template<class T, class E>
inline int graph<T, E>::breadthSearch(int *& allNeighbor, int postion)
{
	if (!IsVertex(postion))
		return -1;
	allNeighbor = new int[vertexNum];
	int *temArrary = new int[vertexNum];//��¼�������Ķ��㣬Ϊ-1�������;
	for (int i = 0; i < vertexNum; i++)
		temArrary[i] = i;
	LinkQueue<int> verQueueu;
	int prePos = postion;
	int j = 0;
	Edge<T, E>* temNode = NULL;
	
	do 
	{
		if (temArrary[prePos] != -1)
		{
			temArrary[prePos] = -1;
			allNeighbor[j] = prePos;
			j++;
			temNode = NodeTable[prePos].adj;
			while (temNode != NULL)
			{
				verQueueu.InQueue(temNode->dest);
				temNode = temNode->link;
			}
		}
		prePos = verQueueu.OutQueue();
	} while (verQueueu.GetSize() != 0);
	return vertexNum;
}


template<class T, class E>
inline bool graph<T, E>::expandSize()
{
	maxsize += 20;
	Vertex<T, E> *temNode = new Vertex<T, E>[maxsize];
	for (int i = 0; i < (maxsize - 20); i++)
		temNode[i] = NodeTable[i];
	delete[]NodeTable;
	NodeTable = temNode;
	return true;
}
