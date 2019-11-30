#include"subway.h"
#include<fstream>

#define MAX_S 1000


using namespace std;
int main(int argc, char* argv[])
{
	int numLine;
	int numStation;
	int line1, line2;
	string src, dst;
	//ChainNode* station;
	//station = new ChainNode[MAX_S];
	Key station[MAX_S];
	int* countLine;
	int countEdge;
	int total = 0;
	string insertName;
	if (argc != 3)
	{
		cerr << "Argument Count is " << argc << endl << "Argument must be " << argc << endl;
		return 1;
	}
	fstream fin(argv[1]);
	if (!fin)
	{
		cerr << argv[1] << " open failed" << endl;
		return 1;
	}
	fin >> numLine;
	countLine = new int[numLine];
	fill(countLine, countLine + numLine, 0);
	int k = 0;
	for (int i = 0; i < numLine; i++) {// 호선수만큼 반복 i 는 호선수
		countLine[i] = k;
		fin >> numStation;//호선에 몇개역 있는지 받기
		k += numStation;
		for (int j = 0; j < numStation; j++) { //한 호선의 개수 만큼 반복
			station[total].line = i + 1;
			station[total].index = total;
			fin >> insertName;
			station[total].name = insertName;
			total++;
		}
	}
	fin >> countEdge;
	LinkedGraph subway(total);
	for (int s = 0; s < countEdge; s++) {
		int l1, l2; string n1, n2;
		int edgeIndex1, edgeIndex2;
		fin >> l1 >> n1 >> l2 >> n2;
		for (int i = countLine[l1 - 1]; i < total; i++) {
			if (station[i].name == n1) {
				edgeIndex1 = i;
				break;
			}
		}
		for (int i = countLine[l2 - 1]; i < total; i++) {
			if (station[i].name == n2) {
				edgeIndex2 = i;
				break;
			}
		}
		if (l1 == l2) {
			subway.linkEdge(station[edgeIndex1], station[edgeIndex2], 60);
		}
		else {
			subway.linkEdge(station[edgeIndex1], station[edgeIndex2], 30);
		}
	}
	fin.close();


	fstream fin2(argv[2]);
	if (!fin2)
	{
		cerr << argv[2] << " open failed" << endl;
		return 1;
	}
	fin2 >> line1 >> src;
	fin2 >> line2 >> dst;

	fin2.close();

	cout << "출발역 : " << src << "(line" << line1 << ")" << endl;
	cout << "도착역 : " << dst << "(line" << line2 << ")" << endl;
	cout << "============================================" << endl;
	int startIndex, endIndex;
	for (int i = countLine[line1 - 1]; i < total; i++) {
		if (station[i].name == src) {
			startIndex = i;
			break;
		}
	}
	for (int i = countLine[line2 - 1]; i < total; i++) {
		if (station[i].name == dst) {
			endIndex = i;
			break;
		}
	}
	subway.dijkstra(startIndex, endIndex,station);


}