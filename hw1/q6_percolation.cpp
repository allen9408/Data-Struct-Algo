#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int qufind(int id[], int p) {
	// Return the root of the node
	int i = p;
	while (p != id[p]) {
		p = id[p];
	}
	// Path compression
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
	// Lower tree becomes a child of the taller tree
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
	int pid = qufind(id, 0);
	int qid = qufind(id, size - 1);
	if (pid == qid) {
		return 1;
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
	int *site = new int[grid_size];

	// Init
	for (int i=0; i<grid_size; i++) {
		id[i] = i;
		height[i] = 1;
		site[i] = 0;
	}

	srand(time(NULL));

	site[0] = 1;
	site[grid_size-1] = 1;
	for (int i=1; i<len; i++) {
		// Union the first row
		quunion(id, height, 0, i);
		// Union the bottom row
		quunion(id, height, grid_size-1, grid_size-1-i);
		site[i] = 1;
		site[grid_size-1-i] = 1;
	}
	// Loop until the system percolates
	while (!percolate(id, len)) {
		int open = (double)rand()/ (RAND_MAX) * (grid_size - 1);
		if (!site[open]) {
			// if site is closed before
			site[open] = 1;
			// Union the upper site
			if (open >= len) {
				if (site[open-len])
					quunion(id, height, open, open-len);
			}
			// Union the lower site
			if (open < grid_size-len) {
				if (site[open+len])
					quunion(id, height, open, open+len);
			}
			// Union the left site
			if (!(open%len)) {
				if (site[open-1])
					quunion(id, height, open, open-1);
			}
			// Union the right site
			if (!((open+1)%len)) {
				if (site[open+1]) 
					quunion(id, height, open, open+1);
			}
			step ++;
		}
	}

	cout << "steps = " << step << endl;
	return 1;
}