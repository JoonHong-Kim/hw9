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
struct Key {
	Key(int l,string n):line(l),name(n){}
	int line;	//몇호선
	string name;	//역이름
};
struct Vertex {
	Key key;
	Vertex* next;
};

struct Edge{
	int weight;
	Vertex* from;
	Vertex* target;
};

class Graph {
private:
	int v;	//vertex 개수
	int e;	//edge 개수
	int size;
	Vertex* vertices; //정점 목록
public:
	Graph(int v) {
		this->v = v;
		int size = 0;
	}
	void insertVertex(int, string);
	void insertEdge()
};


void Graph::insertVertex(int l, string n) {

}
