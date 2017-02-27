#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "linkStack.h"

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

/* City pairs*/
struct cityPair {
	char city1[20];
	char city2[20];
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

/* Load city names to hash array*/
void load(char city[]) {
	int hashVal = hash(city[0]);
	if (hashVal < 0) {
		return;
	}
	cityNode *p;
	p = hashArray[hashVal]->nextCity;

	while(p!=NULL && !!strcmp(p->name,city)) {
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

cityNode *locateCity(char city[]) {
	cityNode *p;
	int hashVal = hash(city[0]);
	p = hashArray[hashVal];
	while (p->nextCity != NULL && !!strcmp(p->nextCity->name, city)) {
		p = p->nextCity;
	}
	p = p->nextCity;
	return p;
}

/* Recursive find route between two cities */
bool find(char start[], char end[]) {
	bool success = false;
	linkStack<cityPair> st;

	if (strcmp(start, end) == 0) {
		return true;
	}
	cityNode *p;
	p = locateCity(start);

	if (p == NULL) {
		cout << "Undefined start: " << start << endl;
		return false;
	}
	while (p!=NULL) {
		bool existPot = false;
		node *q = p->dests->next;
		/* Push all possible pairs into stack*/
		while(q!=NULL && !success) {
			cityPair stPair;
			if (strcmp(q->name,end) == 0) {
				/* find end, success*/
				strcpy(stPair.city1, p->name);
				strcpy(stPair.city2, q->name);
				st.push(stPair);
				success = true;
				break;
			} else {
				cityNode *tmp = locateCity(q->name);
				if (!tmp->isVisited) {
					strcpy(stPair.city1, p->name);
					strcpy(stPair.city2, q->name);
					st.push(stPair);
					tmp->isVisited = true;
					existPot = true;
				}
			}
			q = q->next;
		}

		if (success) {
			/* Back track nodes */
			cout << end << "\t";
			cityPair track;
			while(!st.isEmpty()) {
 				track= st.top();
				cout << track.city1 << "\t";
				if (strcmp(track.city1, start) == 0) {
					/* Back tracking complete*/
					cout << endl;
					return true;
				}
				char tr_tmp[20];
				strcpy(tr_tmp, track.city1);
				/* Pop all pairs with same source*/
				while (strcmp(tr_tmp, track.city1)==0){
					// cout<<"pop"<<endl;
					track = st.pop();
					track = st.top();
				}
			}
		} else {
			/* Not success yet*/
			cityPair track;
			if (!existPot) {
				track = st.pop();
			}
			
			if (st.isEmpty()) {
				return false;
			}
			/* Try next pair*/
			track = st.top();
			// cityNode
			p = locateCity(track.city2);
		}

	}
	return success;
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
	while(reqIn >> city1 && reqIn >> city2) {
		init();
		cout << city2 <<" <---------------------------- "<< city1 << endl; 
		if (!find(city1, city2)) {
			cout << "No way between *" << city1 << "* and *" << city2 << "*" << endl;
		}
	}

	return 0;
}