#include "RedBlackTree.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream infile;
	infile.open(argv[1]);

	RedBlackTree<int> rbt;
	int x;
	while (infile >> x) {
		rbt.insert(x);
	}
	infile.close();
	// rbt.printTree();
	rbt.getCost();
	return 0;
}