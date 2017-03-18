#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream fin;
	int length = atoi(argv[2]);
	int *array = new int[length];
	BinarySearchTree<int> bst;
	fin.open(argv[1]);
	for (int i=0; i<length; i++) {
		fin >> array[i];
	}
	fin.close();
	for (int i=0; i<length; i++) {
		bst.insert(array[i]);
	}

	cout << bst.size() << endl;
	cout << bst.select(9) << endl;
	cout << bst.rank(15) << endl;

	return 0;
}