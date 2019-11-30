#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<stack>
#include"subway.h"

#define INF 99999
using namespace std;

LinkedGraph::LinkedGraph(int number) :n(number) {
	list = new AdjList[n];
	check = new bool[n];
	fill(check, check + n, false);
	distance = new int[n];
	fill(distance, distance + n, INF);
}
LinkedGraph::~LinkedGraph() {
	delete[] list;
	delete[] check;
	delete[] distance;
}

void LinkedGraph::linkEdge(Key k1, Key k2, int weight) { //�������� �������� �̾��ش�
	ChainNode* newNode = new ChainNode(k2, weight);
	newNode->link = list[k1.index].first; //k2�� ������ k1����
	list[k1.index].first = newNode;

	newNode = new ChainNode(k1, weight);
	newNode->link = list[k2.index].first; //k1������ k2��

}
void LinkedGraph::dijkstra(int start, int end) {

	int* path = new int[n];
	distance[start] = 0;
	fill(check, check + n, false);
	int index = start;

	for (int i = 0; i < n - 1; i++) {

		for (ChainNode* node = list[index].first->link;
			node != 0; node = node->link) {
			if (distance[node->data.index] > distance[index] + node->weight) { //update �� ��쿡 ��� ����+ update
				path[node->data.index] = index;
				distance[node->data.index] = distance[index] + node->weight;
			}
		}
		int min = INF;
		int minIndex;
		for (int k = 0; k < n; k++) {
			if (!check[k] && min > distance[k]) {
				minIndex = k;
				min = distance[k];
			}
		}
		check[index] = true;
		index = minIndex;

	}
	stack<Key> pa;
	cout << list[end].first->data.name << "(line" << list[end].first->data.line << ")";
	for (int i = end; i != start; i = path[i]) {
		string station = list[i].first->data.name;
		int line = list[i].first->data.line;
		cout << " ->" << station << "(line" << line << ")";
	}
	int minute = distance[end] / 60;
	float second = distance[end] % 60;
	if (second == 0) {
		cout << "�ҿ�ð� :" << minute << "��";
	}
	else {
		cout << "�ҿ�ð� :" << minute << "�� " << second << "��";
	}
}