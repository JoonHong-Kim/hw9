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
	int line;	//��ȣ��
	string name;	//���̸�
};

class Graph {
private:
	int v;	//vertex ����
	int e;	//edge ����
	Key verticies[MAX_S]; //ȣ��+�̸�
	Vertex adjlist[MAX_S]; //��������Ʈ
public:
	
	void insertVertex(int, string);
	void insertEdge()
};


void Graph::insertVertex(int l, string n) {

}
*/
struct Key {
	Key(int l=0, string n=0,int in=0) :line(l), name(n),index(in) {}
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
			list[i].first = NULL; //�ʱ�ȭ
	}
	void linkEdge(Key k1, Key k2,int weight){ //�������� �������� �̾��ش�
		ChainNode* newNode = new ChainNode(k2,weight);
		newNode->link = list[k1.index].first; //k2�� ������ k1����
		list[k1.index].first = newNode;

		newNode = new ChainNode(k1,weight);
		newNode->link = list[k2.index].first; //k1������ k2��
		
	}
};

