#include <iostream>
#include <ctime>

using namespace std;

int qufind(int id[], int p) {
	int i = p;
	while (p != id[p]) {
		p = id[p];
	}
	id[i] = p;
	return p;
}

void quunion(int id[], int height[], int p, int q)
{
	int pid = qufind(id, p);
	int qid = qufind(id, q);
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

int percolate(int id[], int len) {
	int size = len * len - 1;
	for (int i=0; i<len; i++) {
		for (int j=0; j<len; j++) {
			int pid = qufind(id, i);
			int qid = qufind(id, size - j);
			if (pid == qid) {
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int step = 0;	
	// size of grid: len * len
	int len = atoi(argv[1]);
	int grid_size = len * len;
	cout << "size:" << grid_size << endl;
	int *id = new int[grid_size];
	int *height = new int[grid_size]; 
	for (int i=0; i<grid_size; i++) {
		id[i] = i;
		height[i] = 1;
	}

	// Loop until the system percolates
	while (!percolate(id, len)) {
		// srand(time(NULL));
		int site_1 = (double)rand()/ (RAND_MAX) * (grid_size - 1);
		int site_2 = (double)rand()/ (RAND_MAX) * (grid_size - 1);
		while(site_2 == site_1) {
			site_2 = (double)rand()/ (RAND_MAX) * (grid_size - 1);
		}
		// cout << site_1 << "		" << site_2 << endl;

		quunion(id, height, site_1, site_2);
		step ++;
	}

	cout << "steps = " << step << endl;
	return 1;
}