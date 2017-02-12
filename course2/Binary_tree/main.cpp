#include "binaryTree.h"

int main(int argc, char const *argv[])
{
	BinaryTree<int> tmp;
	int flag = -1;
	tmp.createTree(flag);
	cout << "size = " << tmp.size() << endl;
	cout << "height = " << tmp.height() << endl;
	tmp.preOrder();
	tmp.postOrder();
	tmp.inOrder();

	return 0;
}