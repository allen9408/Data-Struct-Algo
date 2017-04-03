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
		// cout << x << endl;
		rbt.insert(x);
		// rbt.printTree();
	}
	infile.close();
	rbt.printTree();
	return 0;
}