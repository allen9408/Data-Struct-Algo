#include "twothreeTree.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	// open file
	ifstream infile;
	infile.open(argv[1]);

	twothreeTree<int> tt;
	int x;
	while (infile >> x) {
		// cout <<"insert: " << x << endl;	
		tt.insert(x);
		// cout << "-----------------------------------" << endl;
		// tt.printTree();
	}
	infile.close();
	tt.printTree();
	return 0;
}