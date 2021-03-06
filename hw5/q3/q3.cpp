#include "adjListGraph.h"
#include <fstream>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int ver_num;
	int edge_num;
	int we;

	ifstream in;
	in.open(argv[1]);
	in >> ver_num;
	in >> edge_num;
	int *verList = new int[ver_num];
	cout << ver_num <<'\t' << edge_num << endl;
	for (int i = 0; i< ver_num; i++) {
		verList[i] = i;
	}
	cout << "init complete" << endl;
	adjListGraph <int, int> g(ver_num, verList);

	for (int i = 0; i< edge_num; i++) {
		int ver1,ver2;
		in >> ver1 >> ver2 >> we;
		if (ver1 > ver_num-1 || ver2 > ver_num-1) {
			cout << "invalid value: line " << i <<endl;
			return 0; 
		}
		/* Undirect Graph*/
		g.insert(ver1, ver2, we);
		// g.insert(ver2, ver1, we);
	}
	cout << "insert complete" << endl;
	g.dfs();
	g.bfs();
	return 0;
}