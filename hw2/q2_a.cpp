#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct node {
	char name[20];
	struct node *next;

	node() {next=NULL;}
};
/* Hash node for cities */
struct cityNode {
	char name[20];
	struct cityNode *nextCity;
	struct node *dests;
	bool isVisited;
	cityNode() {nextCity=NULL;dests=NULL;}
};

/* Hash array for cities*/
static	cityNode **hashArray;

/* Calculate hash value for cities */
int hash(char ch) {
	if (ch>='a' && ch<='z') {
		return ('z'-ch);
	}
	if (ch>='A' && ch<='Z') {
		return 'Z'-ch;
	}
	cout << "Invalid character" << endl;
	return -1;
}

/* Initialize city nodes */
void init() {
	cityNode *tt;
	for (int i=0; i<26; i++) {
		tt = hashArray[i]->nextCity;
		while(tt != NULL) {
			tt->isVisited = false;
			tt = tt->nextCity;
		}
	}
}
/* Recursive find route between two cities */
int find(char city1[], char city2 []) {
	if (strcmp(city1, city2) == 0) {
		return 1;
	}
	cityNode *p;
	int val = hash(city1[0]);
	p = hashArray[val];
	/* Locate the node*/
	while(p->nextCity != NULL && strcmp(p->nextCity->name, city1)) {
		p = p->nextCity;
	}
	if (p->nextCity == NULL) {
		cout << "Undefined city: " << city1 << endl;
		return 0;
	}
	p = p->nextCity;

	if (p->isVisited) {
		/* All nodes can be visited only once */
		return 0;
	}
	p->isVisited = true;
	node *q;
	q = p->dests->next;
	while(q != NULL) {
		/* Recursively search adjacent cities */
		if (find(q->name, city2)) {
			cout << q->name << " ";
			return 1;
		} else {
			q = q->next;
		}
	}
	return 0;
}
/* Load city names to hash array*/
void load(char city[]) {
	int hashVal = hash(city[0]);
	if (hashVal < 0) {
		return;
	}
	cityNode *p;
	p = hashArray[hashVal]->nextCity;

	while(p!=NULL && !(p->name == city)) {
		p = p->nextCity;
	}
	if (p == NULL) {
		p = new cityNode();
		strcpy(p->name, city);
		p->nextCity = hashArray[hashVal]->nextCity;
		hashArray[hashVal]->nextCity = p;
		p->dests = new node();
	}	
}
/* Insert pairs to hash nodes */
void insert(char city1[], char city2[]) {
	int hash1 = hash(city1[0]);
	// cout << hash1 << endl;
	cityNode *p;
	p = hashArray[hash1];
	while(p->nextCity != NULL && !!strcmp(p->nextCity->name,city1)) {
		p = p->nextCity;
	}
	if (p->nextCity == NULL) {
		cout << "Undefined city1: " << city1 << endl;
		return;
	} else {
		p = p->nextCity;
		node *q,*r;
		q = p->dests;
		r = q->next;
		while (r!=NULL && !(r->name==city2)) {
			r = r->next;
		}
		if (r == NULL) {
			r = new node();
			strcpy(r->name, city2);
			r->next = q->next;
			q->next = r;
		}
	}
}
/* Print all nodes */
void traversal() {
	cityNode *tt;
	for (int i=0; i<26; i++) {
		cout << i <<":" << endl;
		tt = hashArray[i]->nextCity;
		while(tt != NULL) {
			cout << tt->name << endl;
			node *ss;
			ss = tt->dests->next;
			while (ss != NULL) {
				cout << ss->name << " ";
				ss = ss->next;
			}
			cout << endl;
			tt = tt->nextCity;
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	hashArray = new cityNode *[26];
	for (int i=0; i<26; i++) {
		hashArray[i] = new cityNode;
	}
	/* Load city names */
	fstream cityIn;
	cityIn.open(argv[1]);
	char tmp[20];
	while(cityIn >> tmp) {
		load(tmp);
	}
	cityIn.close();

	/* Insert city pairs */
	ifstream pairIn;
	pairIn.open(argv[2]);
	char city1[20];
	char city2[20];
	while (pairIn>>city1 && pairIn>>city2) {
		insert(city1,city2);
	}
	pairIn.close();

	/* Search for request flight */
	ifstream reqIn;
	reqIn.open(argv[3]);
	// cout << "Open complete" << endl;
	while(reqIn >> city1 && reqIn >> city2) {
		init();
		cout << city2 <<" <---------------------------- "<< city1 << endl; 
		if (find(city1, city2)) {
			cout << city1 << endl;
		} else {
			cout << "No way between *" << city1 << "* and *" << city2 << "*" << endl;
		}
	}

	return 0;
}