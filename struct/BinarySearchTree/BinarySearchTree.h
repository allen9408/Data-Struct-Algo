#include <stdlib.h>

template <class Type>
class BinarySearchTree
{
private:
	struct BinaryNode {
		Type data;
		BinaryNode *left;
		BinaryNode *right;
		int count;

		BinaryNode(const Type &thedata, BinaryNode *lt, BinaryNode *rt)
			: data(thedata), left(lt), right(rt) {}
	};

public:
	BinarySearchTree(BinaryNode *t = NULL) {root = t;}
	~BinarySearchTree() {makeEmpty(root);}
	bool find(const Type &x) const {return find(x,root);}
	void insert(const Type &x) {insert(x,root);}
	void remove(const Type &x) {remove(x,root);}
	int size() {return size(root);}
	int rank(const Type &x) {return rank(x, root);}
	Type select(const int r) {
		BinaryNode *tmp;
		tmp = select(r, root);
		return tmp->data;
	}

private:
	BinaryNode *root;

	int size(BinaryNode *t) {
		if (t == NULL)
			return 0;
		return t->count;
	}
	bool find(const Type &x, BinaryNode *t) const {
		if (t==NULL)
			return false;
		else if (x < t->data)
			return find(x,t->left);
		else if (x > t->data)
			return find(x,t->right);
		else
			return true;
	}

	void insert(const Type &x, BinaryNode *&t) {
		if (t == NULL)
			t = new BinaryNode(x, NULL, NULL);
		else if(x < t->data)
			insert(x, t->left);
		else if(x > t->data)
			insert(x, t->right);
		t->count = 1 + size(t->left) + size(t->right);
	}

	void remove(const Type &x, BinaryNode *&t) {
		if (t == NULL)
			return;
		if (x < t->data)
			remove(x, t->left);
		else if (x > t->data)
			remove(x, t->right);
		else if (t->left != NULL && t->right != NULL) {
			BinaryNode *tmp = t->right;
			while (tmp->left != NULL) {
				tmp = tmp->left;
			}
			t->data = tmp->data;
			remove(t->data, t->right);
		} 
		else {
			BinaryNode *oldNode = t;
			t = (t->left != NULL)? t->left: t->right;
			delete oldNode;
		}
		t->count = size(t->left) + size(t->right) + 1;
	}

	void makeEmpty(BinaryNode *&t) {
		if (t->left != NULL)
			makeEmpty(t->left);
		if (t->right != NULL)
			makeEmpty(t->right);
		delete t;
	}

	int rank(const Type &x, BinaryNode *t) {
		if (t == NULL)
			return 0;
		if (x < t->data) {
			return rank(x, t->left);
		} else if (x > t->data) {
			return 1 + size(t->left) + rank(x, t->right);
		} else if (x == t->data) {
			return size(t->left);
		}
	}

	BinaryNode *select(const int r, BinaryNode *t) {
		if (t == NULL)
			return NULL;
		int l = size(t->left);
		if (l > r) 
			return select(r, t->left);
		else if (l < r) 
			return select(r-l-1, t->right);
		else
			return t;
	}
};