#include<iostream>
#include<string>
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
void LinkedGraph::dijkstra(int start, int end, Key station[]) {

	int* path = new int[n];
	fill(path, path + n, start);
	distance[start] = 0;
	fill(check, check + n, false);
	int index;
	int minIndex;
	ChainNode* node;

	for (int i = 0; i < n - 1; i++) {
		int min = INF;
	
		
		for (int k = 0; k < n; k++) {
			if (!check[k] && min > distance[k]) {
				minIndex = k;
				min = distance[k];
			}
		}
		index = minIndex;
		check[index] = true;
		
		
		node = list[index].first;
		for (ChainNode* node = list[index].first;
			node != 0 ; node = node->link){
			if (!check[node->data.index]) {
				if (distance[node->data.index] > distance[index] + node->weight) { //update 될 경우에 경로 저장+ update
					path[node->data.index] = index;
					distance[node->data.index] = distance[index] + node->weight;
				}
			}
		}

	}

	stack<Key> pa;
	cout << station[start].name << "(line" << station[start].line << ")";
	for (int i = end; i != start; i = path[i]) {
		pa.push(station[i]);
	}
	for (; !pa.empty();) {
		cout << " -> " << pa.top().name << "(line" << pa.top().line << ")";
		pa.pop();
	}

	float minute = distance[end] / 60;

	
	cout << "\n" << "소요시간 :" << minute << "minutes" << endl;


}
