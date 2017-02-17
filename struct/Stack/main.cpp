#include "linkStack.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	linkStack<int> tmp;
	for (int i = 0; i < 12; ++i)
	{
		/* code */
		tmp.push(data[i]);
	}
	for (int i = 0; i < 12; ++i)
	{
		/* code */
		cout << tmp.top() <<"    ";
	}
	cout << endl;
	for (int i = 0; i < 12; ++i)
	{
		/* code */
		cout << tmp.pop() <<"    ";
	}
	cout << endl;

	return 0;
}