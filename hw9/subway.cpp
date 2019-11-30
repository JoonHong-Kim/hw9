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
	for (int i = 0; i < n; i++)list[i].first = 0;
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

void LinkedGraph::linkEdge(Key k1, Key k2, int weight) { //꼭지점과 꼭지점을 이어준다
	ChainNode* newNode = new ChainNode(k2, weight);
	newNode->link = list[k1.index].first; //k2의 다음을 k1으로
	list[k1.index].first = newNode;

	newNode = new ChainNode(k1, weight);
	newNode->link = list[k2.index].first; //k1다음을 k2로
	list[k2.index].first = newNode;
}
void LinkedGraph::dijkstra(int start, int end,Key station[]) {

	int* path = new int[n];
	distance[start] = 0;
	fill(check, check + n, false);
	int index = start;

	for (int i = 0; i < n - 1; i++) {
		
		for (ChainNode* node = list[index].first;
			node != 0; node = node->link) {
			if (distance[node->data.index] > distance[index] + node->weight) { //update 될 경우에 경로 저장+ update
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
	cout <<station[start].name<< "(line" << station[start].line << ")";
	for (int i = end; i != start; i = path[i]) {
		pa.push(station[i]);
	}
	for (; !pa.empty();) {
		cout <<" -> "<<pa.top().name << "(line" << pa.top().line << ")";
		pa.pop();
	}
	int minute = distance[end] / 60;
	float second = distance[end] % 60;
	if (second == 0) {
		cout << "\n" << "소요시간 :" << minute << "분";
	}
	else {
		cout << "\n" << "소요시간 :" << minute << "분 " << second << "초";
	}
}