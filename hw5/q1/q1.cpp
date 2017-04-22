#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


int qufind_w(int id[], int p) {
	while (p != id[p]) {
		p = id[p];
	}
	return p;
}

void quunion_w(int id[], int height[], int p, int q)
{
	int pid = qufind_w(id, p);
	int qid = qufind_w(id, q);
	if (pid == qid)
	{
		return;
	}
	if (height[pid] < height[qid]) {
		id[pid] = qid;
		height[qid] = (height[qid]>height[pid])?height[qid]:(height[pid]+1);
	} else {
		id[qid] = pid;
		height[pid] = (height[pid]>height[qid])?height[pid]:(height[qid]+1);
	}
}

int main(int argc, char const *argv[])
{
	int ver_num;
	int edge_num;
	float we;
	ifstream in;

	/* Read data from file */
	in.open(argv[1]);
	in >> ver_num;
	in >> edge_num;
	cout << ver_num <<"\t" <<edge_num << endl;

	// Init
	int *id = new int[ver_num];
	int *height = new int[ver_num];
	for(int i=0; i<ver_num; i++) {
		id[i] = i;
		height[i] = 1;
	}
	for (int i=0; i<edge_num; i++) {
		int tmp1, tmp2;
		in >> tmp1 >> tmp2 >> we;
		if (qufind_w(id, tmp1) == qufind_w(id, tmp2)) {
			cout << "Make a circle when connect " << tmp1 << " and " << tmp2<< endl;
			return 0;
		} else {
			quunion_w(id, height, tmp1, tmp2);
		}
	}
	cout << "No circle" << endl;
	return 0;
}