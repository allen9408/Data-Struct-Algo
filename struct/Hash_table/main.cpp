#include "hashTable.h"

using namespace std;

int main() {
	int data[8] = {4371, 1323, 6173, 4199, 4344, 9679, 1989, 6151};
	HashTable<int> tmp(11);
	for (int i=0; i<8; ++i) {
		tmp.insert(data[i]);
	}
	cout << "result of find 4371: " << tmp.find(4371) << endl;
	cout << "result of find 4888: " << tmp.find(4888) << endl;
	cout << "result of find 9679: " << tmp.find(9679) << endl;
}