#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<math.h>

#define MAX_S 900
#define INF 9999
//�ʿ��Ѱ� Ž��,�ִܱ��� �˰���
using namespace std;
struct Key {
	Key(int l,string n):line(l),name(n){}
	int line;	//��ȣ��
	string name;	//���̸�
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
	int v;	//vertex ����
	int e;	//edge ����
	int size;
	Vertex* vertices; //���� ���
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
