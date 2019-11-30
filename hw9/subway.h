#include<iostream>
using namespace std;

struct Key {
	Key(int l = 0, string n = "", int in = 0) :line(l), name(n), index(in) {}
	int line;	//몇호선
	string name;	//역이름
	int index;		//넣을때 index값도 넣어줘야함
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
	int n;	//vertex수
	bool* check;
	int* distance;
public:
	~LinkedGraph();
	LinkedGraph(int);
	void linkEdge(Key, Key, int);
	void dijkstra(int, int);
};
