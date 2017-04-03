#include <iostream>
using namespace std;

template <class Type>
class RedBlackTree {
private:
	struct RedBlackNode
	{
		Type data;
		RedBlackNode *left;
		RedBlackNode *right;
		bool color; // 0-red, 1-black

		RedBlackNode(const Type &element, RedBlackNode *lt, RedBlackNode *rt, bool h=0):
			data(element), left(lt), right(rt), color(h) {}
	};

	RedBlackNode *root;
	int cost_ins; // cost for each insertion
	int cost_rot; // cost for build rotations

public:
	RedBlackTree(RedBlackNode *t=NULL) {
		root = t;
		cost_rot = 0;
	}
	~RedBlackTree(){
		makeEmpty(root);
	}
	bool find(const Type &x) const {
		RedBlackNode *tmp = root;
		while(tmp != NULL) {
			if (tmp->data == x) {
				return true;
			} else if (x < tmp->data) {
				tmp = tmp->left;
			} else if (x > tmp->data) {
				tmp = tmp->right;
			}
		}
		return false;
	}
	void insert(const Type &x) {
		cost_ins = 0;
		root = insert(x, root);
		root->color = 1;
	}
	void printTree() {
		int tab = 0;
		printTree(root, tab);
	}
	void getCost() {
		cout << "Cost for insertion: " << cost_ins << endl;
		cout << "Cost for rotation: " << cost_rot << endl;
	}
private:
	void makeEmpty(RedBlackNode *&t) {
		if (t->left != NULL)
			makeEmpty(t->left);
		if (t->right != NULL)
			makeEmpty(t->right);
		delete t;
	}

	RedBlackNode *rotateLeft(RedBlackNode *&h) {
		RedBlackNode *x = h->right;
		h->right = x->left;
		x->left = h;
		x->color = h->color;
		h->color = 0;
		return x;
	}

	RedBlackNode *rotateRight(RedBlackNode *&h) {
		RedBlackNode *x = h->left;
		h->left = x->right;
		x->right = h;
		x->color = h->color;
		h->color = 0;
		return x;
	}

	void flipColors(RedBlackNode *&h) {
		h->color = !h->color;
		h->left->color = !h->left->color;
		h->right->color = !h->right->color;
	}

	RedBlackNode *insert(Type x, RedBlackNode *&h) {
		if (h == NULL) {
			return new RedBlackNode(x, NULL, NULL, 0);
		}

		if (x == h->data) {
			return h;
		} else if (x < h->data) {
			h->left = insert(x, h->left);
		} else {
			h->right = insert(x, h->right);
		}
		cost_ins ++;
		if (h->right != NULL){
			if(h->right->color == 0 && (h->left == NULL || h->left->color == 1)) {
				h = rotateLeft(h);
				cost_rot ++;
			}
		}
		if (h->left != NULL) {
			if (h->left->left != NULL) {
				if(h->left->color == 0 && h->left->left->color == 0) {
					h = rotateRight(h);
					cost_rot ++;
				}
			}
		}
		if (h->left != NULL && h->right != NULL) {
			if (h->left->color == 0 && h->right->color == 0) {
				flipColors(h);
				cost_rot ++;
			}			
		}
		return h;
	}

	void printTree(RedBlackNode *t, int tab) {
		for (int i = 0; i < tab; i++) {
			cout << "\t";
		}
		if (t == NULL) {
			cout << "-B-> NULL" << endl;
			return; 
		}
		if (t->color) {
			// black
			cout << "-B-> ";
		} else {
			// red
			cout << "-R-> ";
		}
		cout << t->data << endl;
		if (t->left != NULL || t->right != NULL) {
			++tab;
			printTree(t->left, tab);
			printTree(t->right, tab);
		}
	}

};