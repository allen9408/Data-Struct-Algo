#include <iostream>

using namespace std;

template <class Type>
class HashTable
{
private:
	struct node {
		Type data;
		struct node *next;

		node(const Type &d) {data=d;next=NULL;}
		node() {next=NULL;}
	};

	node **array;
	int size;

protected:
	int( *key)(const Type &x);
	static int defaultKey(const int &k) {return k;}

public:
	HashTable(int length = 101, int(*f)(const Type &x)=defaultKey) {
		size = length;
		array = new node *[size];
		key = f;
		for (int i = 0; i < size; ++i) {
			array[i] = new node;
		}
	}

	~HashTable() {
		node *p, *q;

		for (int i=0; i<size; ++i) {
			p = array[i];
			do {
				q = p->next;
				delete p;
				p = q;
			} while(p != NULL);
		}

		delete [] array;
	}

	bool insert(const Type &x) {
		int pos;
		node *p;

		pos = key(x) % size;
		p = array[pos]->next;
		while(p != NULL && !(p->data == x)) {
			p = p->next;
		}
		if (p == NULL) {
			p = new node(x);
			p->next = array[pos]->next;
			array[pos]->next = p;
			return true;
		}
		return false;
	}

	bool remove(const Type &x) {
		int pos;
		node *p, *q;
		pos = key(x) % size;
		p = array[pos];
		while(p->next != NULL && !(p->next->data==x)) {
			p=p->next;
		}
		if (p->next == NULL) {
			return false;
		} else {
			q = p->next;
			p->next = q->next;
			delete q;
			return true;
		}
	}

	bool find(const Type &x) const {
		int pos;
		node *p;

		pos = key(x) % size;
		p = array[pos];
		while(p->next != NULL && !(p->next->data==x)) {
			p=p->next;
		}
		if (p->next != NULL) {
			return true;
		} else {
			return false;
		}
	}
};