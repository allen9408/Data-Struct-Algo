#include <iostream>
#include "linkQueue.h"
using namespace std;

template <class Type>
class BinaryTree{

private:
	struct node{
		node *left, *right;
		Type data;

		node(): left(NULL), right(NULL) {}
		node(Type item, node *L = NULL, node *R = NULL) :
			data(item), left(L), right(R) {}

		~node() {}	
	};
	
	node *root;

public:
	BinaryTree(): root(NULL) {}
	BinaryTree(const Type &value) {root = new node(value);}
	~BinaryTree() {clear();}

	Type getRoot() const {return root->data;}
	Type getLeft() const {return root->left->data;}
	Type getRight() const {return root->right->data;}

	void makeTree(const Type &x, BinaryTree &lt, BinaryTree &rt) {
		root = new node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}

	void delLeft() {
		clear(root->left);
		root->left = NULL;
	}

	void delRight() {
		clear(root->right);
		root->right = NULL;
	}

	bool isEmpty() const {
		return root == NULL;
	}

	void clear() {
		if (root != NULL) {
			clear(root);
		}
		root = NULL;
	}

	int size() const {
		return size(root);
	}

	int height() const {
		return height(root);
	}

	void preOrder() const {
		if (root != NULL)
			cout << "\nPre order:";
		preOrder(root);
	}

	void postOrder() const {
		if (root != NULL)
			cout << "\nPost order:";
		postOrder(root);
	}

	void inOrder() const {
		if (root != NULL)
			cout << "\nIn order:";
		inOrder(root);
	}

	void createTree(Type flag) {
		linkQueue<node *> que;
		node * tmp;
		Type x, ldata, rdata;

		// create tree, return if input = flag
		cout << "\nInput root node:";
		cin >> x;
		root = new node(x);
		que.enQueue(root);

		while(!que.isEmpty()) {
			tmp = que.deQueue();
			cout << "Input two children of " << tmp->data << "(end with " << flag <<"):";
			cin >> ldata >> rdata;
			if (ldata != flag) {
				que.enQueue(tmp->left = new node(ldata));
			}
			if (rdata != flag) {
				que.enQueue(tmp->right = new node(rdata));
			}
		}

		cout << "Create complete!" << endl;
	}

private:
	int height(node *t) const {
		if (t == NULL)
			return 0;
		int lt = height(t->left);
		int rt = height(t->right);
		return 1 + ((lt>rt)?lt:rt);
	}

	void clear(node *t) {
		if (t->left != NULL) {
			clear(t->left);
		}
		if (t->right != NULL) {
			clear(t->right);
		}
		delete t;
	}

	int size(node *t) const {
		if (t == NULL) 
			return 0;
		return 1 + size(t->left) + size(t->right);
	}

	void preOrder(node *t) const {
		if (t == NULL) 
			return;
		cout << t->data << " ";
		preOrder(t->left);
		preOrder(t->right);
	}

	void postOrder(node *t) const {
		if (t == NULL) 
			return;
		preOrder(t->left);
		preOrder(t->right);
		cout << t->data << " ";
	}

	void inOrder(node *t) const {
		if (t == NULL) 
			return;
		preOrder(t->left);
		cout << t->data << " ";
		preOrder(t->right);
	}
};