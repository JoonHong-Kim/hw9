#include<iostream>
using namespace std;

struct Key {
	Key(int l = 0, string n = "", int in = 0) :line(l), name(n), index(in) {}
	int line;	//��ȣ��
	string name;	//���̸�
	int index;		//������ index���� �־������
};
class ChainNode
{
private:
	Key data;
	ChainNode* link;
	int weight;
public:
	ChainNode(Key element = 0, int w = 0, ChainNode* next = NULL) :data(element), link(next), weight(w) {  }
	friend class AdjList;
	friend class LinkedGraph;

};



class AdjList {
	ChainNode* first;
	int weight;
	friend class LinkedGraph;
public:

};

class LinkedGraph {
private:
	AdjList* list;
	int n;	//vertex��
	bool* check;
	int* distance;
public:
	~LinkedGraph();
	LinkedGraph(int);
	void linkEdge(Key, Key, int);
	void dijkstra(int, int);
};
