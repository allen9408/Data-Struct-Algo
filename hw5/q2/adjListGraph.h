#include <iostream>
#include "linkQueue.h"
#include "priorityQueue.h"
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
	struct edge
	{
		int beg, end;
		Type_e w;
		bool operator < (const edge &rp) const {
			return w<rp.w;
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

	void kruskal() {
		int edgeAccepted = 0, u, v;
		edgeNode *p;
		edge e;
		int id[Vers];
		int height[Vers];
		priorityQueue <edge> pq;

		for (int i=0; i<Vers; i++) {
			/* Initialize for union find */
			id[i] = i;
			height[i] = 1;
		}
		/* Add all edges to priority queue*/
		for (int i=0; i<Vers; i++) {
			for (p = verList[i].head; p!=NULL; p = p->next) {
				if (i < p->end) {
					e.beg = i;
					e.end = p->end;
					e.w = p->weight;
					pq.enQueue(e);
				}
			}
		}
		// cout << "Start choose edges" << endl;
		/* Start choose */
		while (edgeAccepted < Vers-1 && !pq.isEmpty()) {
			e = pq.deQueue();
			// cout << e.beg << "\t" << e.end << endl;
			u = qufind_w(id, e.beg);
			v = qufind_w(id, e.end);
			// cout << u << "\t" << v << endl;
			if (u != v) {
				edgeAccepted++;
				quunion_w(id, height, u, v);
				cout << "(" << verList[e.beg].ver << "," << verList[e.end].ver <<")\t";
			} 
		}
	}

	void prim(Type_e noEdge) {
		bool *flag = new bool[Vers];
		Type_e *lowCost = new Type_e[Vers];
		int *startNode = new int[Vers];
		edgeNode *p;
		Type_e min;
		int start, i, j;
		for(i = 0; i < Vers; ++i) {
			flag[i] = false;
			lowCost[i] = noEdge;
		}
		start =0;
		for (i = 1; i < Vers;  ++i) {
			for (p=verList[start].head; p!=NULL;p=p->next) {
				if (!flag[p->end] && lowCost[p->end] > p->weight) {
					lowCost[p->end] = p->weight;
					startNode[p->end] = start;
				}				
			}
			flag[start] = true;
			min = noEdge;
			for (j=0; j<Vers; ++j) {
				if (lowCost[j] < min) {
					min = lowCost[j];
					start = j;
				}
			}
			cout << "(" << verList[startNode[start]].ver << "," << verList[start].ver << ")\t";
			lowCost[start] = noEdge;
		}
		delete [] flag;
		delete [] startNode;
		delete [] lowCost;
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
	
	int qufind_w(int id[], int p) {
		while (p != id[p]) {
			p = id[p];
		}
		return p;
	}

	void quunion_w(int id[], int height[], int p, int q)
	{
		int pid = qufind_w(id, p);
		int qid = qufind_w(id, q);
		if (pid == qid)
		{
			return;
		}
		if (height[pid] < height[qid]) {
			id[pid] = qid;
			height[qid] = (height[qid]>height[pid])?height[qid]:(height[pid]+1);
		} else {
			id[qid] = pid;
			height[pid] = (height[pid]>height[qid])?height[pid]:(height[qid]+1);
		}
	}
};