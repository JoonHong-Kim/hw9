#include"subway.h"
#include<fstream>

#define MAX_S 1000


using namespace std;
int main(int argc, char* argv[])
{
	int numLine;
	int numStation;
	int line1, line2;
	int index = 0;
	string src, dst;
	Key station[MAX_S];
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
	fin >> numStation;
	for (int i = 1; i <= numStation; i++) {// 호선수만큼 반복 i 는 호선수
		fin >> numStation;//호선에 몇개역 있는지 받기
		for (int j = 0; i < numStation; j++,index++) { //한 호선의 개수 만큼 반복
			station[index].line = i;
			fin >> station[index].name;
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
	
	return 0;

}