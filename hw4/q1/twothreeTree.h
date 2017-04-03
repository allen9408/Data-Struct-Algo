#include <iostream>
using namespace std;

template <class Type>
class twothreeTree {
private:
	struct node
	{
		Type key[3];
		node *parent, *child[4];
		bool isThree;

		node(Type data = -1) {
			key[0] = data;
			key[1] = -1;
			key[2] = -1;
			parent = NULL;
			child[0] = NULL;
			child[1] = NULL;
			child[2] = NULL;
			child[3] = NULL;
			isThree = false;
		}	
	};

	node *root;
public:
	twothreeTree(node *t = NULL) {root = t;}
	~twothreeTree() {/* TBD*/};
	bool search(const Type &x) const {
		node *tmp = search(x, root);
		return (tmp!=NULL);
	}
	void insert(const Type &x) {
		// cout << "inserting: " << x << endl;
		insert(x, root);
	}
	void printTree() {
		int tab = 0;
		printTree(root, tab);
	}

private:
	node *search(const Type &x, node *t) {
		if (!t->isThree) {
			// two node
			if (x < t->key[0]) 
				return search(x, t->child[0]);
			else if (x > t->key[0])
				return search(x, t->child[1]);
			else
				return t; 
		} else {
			// three node
			if (x < t->key[0]) 
				return search(x, t->child[0]);
			else if (x > t->key[1])
				return search(x, t->child[2]);
			else if (x > t->key[0] && x < t->key[1])
				return search(x, t->child[1]);
			else 
				return t; 
		}
		return t;
	}

	void insert(const Type &x, node *&t) {
		if (t == NULL)
			t = new node();
		if (t->child[0] == NULL){
			// first three insertion, make the root
			if (t->key[0] == -1) {
				//first insertion
				t->key[0] = x;
				return;
			} else if (!t->isThree && t->key[2] == -1) {
				// second insertion
				if (x > t->key[0]) {
					t->key[1] = x;
					t->isThree = true;
					return;
				} else if (x < t->key[0]) {
					t->key[1] = t->key[0];
					t->key[0] = x;
					t->isThree = true;
				} else {
					return;
				}
			} else if (t->isThree) {
				//third insertion
				if (x == t->key[0] || x == t->key[1]) {
					return;
				}
				if (x > t->key[1]) {
					t->child[0] = new node(t->key[0]);
					t->child[1] = new node(x);
					t->key[0] = t->key[1];
				} else if (x < t->key[0]) {
					t->child[0] = new node(x);
					t->child[1] = new node(t->key[1]);
				} else {
					t->child[0] = new node(t->key[0]);
					t->child[1] = new node(t->key[1]);
					t->key[0] = x;
				}
				t->child[0]->parent = t;
				t->child[1]->parent = t;
				t->key[1] = -1;
				t->isThree = false;
				return;
			}
		}
		node *tmp = t;
		while(tmp->child[0] != NULL) {
			if (!tmp->isThree) {
				// two node
				if (tmp->child[0] != NULL) {
					for (int i=0; i<2; i++) {
						tmp->child[i]->parent = tmp;
					}
				}
				if (x < tmp->key[0]) 
					tmp = tmp->child[0];
				else if (x > tmp->key[0])
					tmp = tmp->child[1];
				else
					return; 
			} else {
				// three node
				if (tmp->child[0] != NULL) {
					for (int i=0; i<3; i++) {
						tmp->child[i]->parent = tmp;
					}
				}
				if (x < tmp->key[0]) 
					tmp = tmp->child[0];
				else if (x > tmp->key[1])
					tmp = tmp->child[2];
				else if (x > tmp->key[0] && x < tmp->key[1])
					tmp = tmp->child[1];
				else 
					return; 
			}
		}
	
		if (!tmp->isThree) {
			// insert into a 2-node
			if (x > tmp->key[0]) {
				tmp->key[1] = x;
			} else {
				tmp->key[1] = tmp->key[0];
				tmp->key[0] = x;
			}
			tmp->isThree = true;
			return;
		}

		// insert into a three node
		node *ptmp = tmp->parent;
		// parent is 2-node
		if (!ptmp->isThree) {
			Type mid;
			node *midchild = new node(-1);
			if (x < ptmp->key[0]) {
				// insert on the left node
				if (x < tmp->key[0]) {
					// split current node
					mid = tmp->key[0];
					midchild->key[0] = tmp->key[1];
					tmp->key[0] = x;
					
				} else if (x > tmp->key[1]) {
					mid = tmp->key[1];
					midchild->key[0] = x;
					// tmp->key[0] = x;
				} else {
					mid = x;
					midchild->key[0] = tmp->key[2];
				}
				// insert into parent node
				ptmp->key[1] = ptmp->key[0];
				ptmp->key[0] = mid;
			} else {
				// insert on the right node
				if (x < tmp->key[0]) {
					mid = tmp->key[0];
					midchild->key[0] = x;
					tmp->key[0] = tmp->key[1];
				} else if (x > tmp->key[1]) {
					mid = tmp->key[1];
					midchild->key[0] = tmp->key[0];
					tmp->key[0] = x;
				} else {
					mid = x;
					midchild->key[0] = tmp->key[0];
					tmp->key[0] = tmp->key[1];
				}
				// insert into parent node
				ptmp->key[1] = mid;
			}
			midchild->parent = ptmp;
			ptmp->isThree = true;
			ptmp->key[2] = -1;
			tmp->key[1] = -1;
			tmp->isThree = false;
			ptmp->child[2] = ptmp->child[1];
			ptmp->child[1] = midchild;

			return;
		}

		// parent is 3-node
		Type mid;
		node *newchild = new node(-1);
		if (x < ptmp->key[0]) {
			// insert on the left 
			if (x < tmp->key[0]) {
				mid = tmp->key[0];
				newchild->key[0] = tmp->key[1];
				tmp->key[0] = x;
			} else if (x > tmp->key[1]) {
				mid = tmp->key[1];
				newchild->key[0] = x;
			} else {
				mid = x;
				newchild->key[0] = tmp->key[1];
			}
			// make parent 3-node to 4-node
			ptmp->key[2] = ptmp->key[1];
			ptmp->key[1] = ptmp->key[0];
			ptmp->key[0] = mid;
			ptmp->child[3] = ptmp->child[2];
			ptmp->child[2] = ptmp->child[1];
			newchild->parent = ptmp;
			ptmp->child[1] = newchild;
		} else if (x > ptmp->key[1]) {
			//insert on the right
			if (x < tmp->key[0]) {
				mid = tmp->key[0];
				newchild->key[0] = x;
				tmp->key[0] = tmp->key[1];
			} else if (x > tmp->key[1]) {
				mid = tmp->key[1];
				newchild->key[0] = tmp->key[0];
				tmp->key[0] = x;
			} else {
				mid = x;
				newchild->key[0] = tmp->key[0];
				tmp->key[0] = tmp->key[1];
			}
			// make parent 3-node to 4-node
			ptmp->key[2] = mid;
			ptmp->child[3] = ptmp->child[2];
			newchild->parent = ptmp;
			ptmp->child[2] = newchild;
		} else {
			// insert on the middle
			if (x < tmp->key[0]) {
				mid = tmp->key[0];
				newchild->key[0] = tmp->key[1];
				tmp->key[0] = x;
			} else if (x > tmp->key[1]) {
				mid = tmp->key[1];
				newchild->key[0] = x;
			} else {
				mid = x;
				newchild->key[0] = tmp->key[1];
			}
			// make parent 3-node to 4-node
			ptmp->key[2] = ptmp->key[1];
			ptmp->key[1] = mid;
			ptmp->child[3] = ptmp->child[2];
			newchild->parent = ptmp;
			ptmp->child[2] = newchild;
		}
		tmp->key[1] = -1;
		tmp->isThree = false;
		// First insert complete, split
		tmp = tmp->parent;
		ptmp = tmp->parent;
		while (ptmp != NULL) {
			node *child1 = new node(tmp->key[0]);
			node *child2 = new node(tmp->key[2]);
			child1->child[0] = tmp->child[0];
			child1->child[1] = tmp->child[1];
			tmp->child[0]->parent = child1;
			tmp->child[1]->parent = child1;
			child2->child[0] = tmp->child[2];
			child2->child[1] = tmp->child[3];
			tmp->child[2]->parent = child1;
			tmp->child[3]->parent = child1;
			
			child1->parent = ptmp;
			child2->parent = ptmp;
			ptmp->key[2] = tmp->key[1];
			if (!ptmp->isThree){
				//ptmp is a 2-node	
				if (ptmp->key[2] > ptmp->key[0]) {
					ptmp->key[1] = ptmp->key[2];
					ptmp->child[1] = child1;
					ptmp->child[2] = child2;
				} else {
					ptmp->key[1] = ptmp->key[0];
					ptmp->key[0] = ptmp->key[2];
					ptmp->child[2] = ptmp->child[1];
					ptmp->child[0] = child1;
					ptmp->child[1] = child2;
				}
				ptmp->key[2] = -1;
				ptmp->isThree = true;
				break;
			} else {
				// ptmp is a 3-node
				if (ptmp->key[2] > ptmp->key[1]) {
					ptmp->child[2] = child1;
					ptmp->child[3] = child2;
				} else if (ptmp->key[2] < ptmp->key[0]) {
					Type v = ptmp->key[2];
					ptmp->key[2] = ptmp->key[1];
					ptmp->key[1] = ptmp->key[0];
					ptmp->key[0] = v;
					ptmp->child[3] = ptmp->child[2];
					ptmp->child[2] = ptmp->child[1];
					ptmp->child[1] = child2;
					ptmp->child[0] = child1;
				} else {
					Type v = ptmp->key[2];
					ptmp->key[2] = ptmp->key[1];
					ptmp->key[1] = v;
					ptmp->child[3] = ptmp->child[2];
					ptmp->child[2] = child2;
					ptmp->child[1] = child1;				
				}
			}
			tmp = ptmp;
			ptmp = tmp->parent;
		}
		// check root
		if (tmp->key[2] != -1) {
			// cout << "check root" << endl;
			node *newroot = tmp;
			node *newchild1 = new node(-1); 
			node *newchild2 = new node(-1);
			newchild1->key[0] = tmp->key[0];
			newchild2->key[0] = tmp->key[2];
			newchild1->child[0] = tmp->child[0];
			newchild1->child[1] = tmp->child[1];
			newchild2->child[0] = tmp->child[2];
			newchild2->child[1] = tmp->child[3];
			tmp->child[0]->parent = newchild1;
			tmp->child[1]->parent = newchild1;
			tmp->child[2]->parent = newchild2;
			tmp->child[3]->parent = newchild2;


			newchild1->parent = newroot;
			newchild2->parent = newroot;

			newroot->key[0] = tmp->key[1];
			newroot->child[0] = newchild1;
			newroot->child[1] = newchild2;
			newroot->child[2] = 0;
			newroot->key[1] = -1;
			newroot->key[2] = -1;
			newroot->isThree = false;
			tmp = newroot;
		}
	}
	void printTree(node *t, int tab) {
		for (int i = 0; i < tab; i++) {
			cout <<"\t";
		}
		if (t == NULL) {
			cout << "--> NULL" << endl;
			return;
		}
		cout << "--> (" << t->key[0] << ", " << t->key[1] << ")" << endl;
		if (t->child[0] != NULL) {
			++tab;
			printTree(t->child[0], tab);
			printTree(t->child[1], tab);
			printTree(t->child[2], tab);
		}
	}

};