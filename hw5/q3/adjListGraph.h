#include <iostream>
#include "linkQueue.h"
using namespace std;

template <class Type_v, class Type_e>
class adjListGraph {
private:
	struct edgeNode
	{
		int end;
		Type_e weight;
		edgeNode *next;

		edgeNode(int e, Type_e w, edgeNode *n = NULL) {
			end = e;
			weight = w;
			next = n;
		}
	};
	struct verNode
	{
		Type_v ver;
		edgeNode *head;
		verNode(edgeNode *h = NULL) {
			head = h;
		}
	};
	verNode *verList;
	int Vers, Edges, output_counts;
public:
	adjListGraph(int vSize, const Type_v d[]) {
		Vers = vSize;
		Edges = 0;
		verList = new verNode[vSize];
		for (int i=0; i<Vers; ++i)
			verList[i].ver = d[i];
	}
	~adjListGraph() {
		int i;
		edgeNode *p;

		for(i=0; i<Vers; ++i) {
			while((p=verList[i].head) != NULL) {
				verList[i].head = p->next;
				delete p;
			}
		}
		delete [] verList;
	}
	bool insert(int u, int v, Type_e w) {
		verList[u].head = new edgeNode(v, w, verList[u].head);
		++Edges;
		return true;
	}

	bool remove(int u, int v) {
		edgeNode *p = verList[u].head, *q;
		if (p == NULL) return false;
		if (p->end == v) {
			verList[u].head = p->next;
			delete p;
			--Edges;
			return true;
		}
		while(p->next != NULL && p->next->end != v)
			p = p->next;
		if (p->next == NULL)
			return false;
		q= p->next;
		p->next = q->next;
		delete q;
		--Edges;
		return true;
	}

	void dfs()  {
		bool *visited = new bool[Vers];
		for (int i = 0; i<Vers; ++i)
			visited[i] = false;

		cout << "DFS of Graph (First 50 vertices):" << endl;
		output_counts = 0;
		for (int i=0; i<Vers; ++i) {
			if (visited[i] == true)
				continue;
			dfs(i, visited);
			cout << endl;
		}
	}
	bool exist(int u, int v) const {
		edgeNode *p = verList[u].head;
		while(p != NULL && p->end !=v) {
			p->next = p;
		}
		if (p == NULL) {
			return false;
		} else {
			return true;
		}
	}

	void bfs() {
		bool *visited = new bool[Vers];
		int currentNode;
		linkQueue <int> q;
		edgeNode *p;

		for (int i=0; i<Vers; i++)
			visited[i] = false;
		output_counts = 0;
		cout << "BFS of Graph (First 50 vertices):" << endl;
		for (int i=0; i<Vers; ++i) {
			if (visited[i] == true) continue;
			q.enQueue(i);
			while(!q.isEmpty()) {
				currentNode = q.deQueue();
				if (visited[currentNode] == true) continue;
				if (output_counts < 50){
					cout << verList[currentNode].ver <<"\t";
					output_counts++;
				}
				visited[currentNode] = true;
				p = verList[currentNode].head;
				while(p != NULL) {
					if (visited[p->end] == false)
						q.enQueue(p->end);
					p = p->next;
				}
			}
		}
		cout << endl;
	}



private:
	void dfs(int start, bool visited[])  {
		// cout << start << endl;
		edgeNode *p = verList[start].head;
		if (output_counts < 50) {
			// cout <<output_counts <<":";
			cout << verList[start].ver << "\t";
			output_counts++;
		}
		visited[start] = true;
		while (p != NULL) {
			if (visited[p->end] == false)
				dfs(p->end, visited);
			p = p->next;
		}
	}
	
};