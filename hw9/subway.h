#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<math.h>

#define MAX_S 900
#define INF 9999
//필요한것 탐색,최단길이 알고리즘
using namespace std;

/*
struct Vertex {
	Key key;
	Vertex* next;
};

struct Edge{
	int weight;
	Vertex* from;
	Vertex* target;
};

struct Key {
	Key(int l, string n) :line(l), name(n) {}
	int line;	//몇호선
	string name;	//역이름
};

class Graph {
private:
	int v;	//vertex 개수
	int e;	//edge 개수
	Key verticies[MAX_S]; //호선+이름
	Vertex adjlist[MAX_S]; //인접리스트
public:
	
	void insertVertex(int, string);
	void insertEdge()
};


void Graph::insertVertex(int l, string n) {

}
*/
struct Key {
	Key(int l=0, string n=0,int in=0) :line(l), name(n),index(in) {}
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
	ChainNode(Key element, int w = 0,ChainNode* next = NULL) :data(element), link(next), weight(w) {  }
	Key getData(){
		return data;
	}

	ChainNode* Link(){
		return link;
	}
	friend class AdjList;
	friend class LinkedGraph;
	friend ostream& operator<<(ostream& os, LinkedGraph& lg);
};



class AdjList{
	ChainNode* first;
	int weight;
	friend class LinkedGraph;
	friend ostream& operator<<(ostream& os, LinkedGraph& lg);
};

class LinkedGraph{
private:
	AdjList* list;
	int n;
public:
	LinkedGraph(int number) :n(number){
		list = new AdjList[n];
		for (int i = 0; i < n; i++)
			list[i].first = NULL; //초기화
	}
	void linkEdge(Key k1, Key k2,int weight){ //꼭지점과 꼭지점을 이어준다
		ChainNode* newNode = new ChainNode(k2,weight);
		newNode->link = list[k1.index].first; //k2의 다음을 k1으로
		list[k1.index].first = newNode;

		newNode = new ChainNode(k1,weight);
		newNode->link = list[k2.index].first; //k1다음을 k2로
		
	}
};

