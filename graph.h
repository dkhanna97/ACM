#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

/* Generic Graph Class 
   Devruth Khanna
*/

class Graph{

	int V; //# of vertices
	list<int> *adj; //adjacency list, or an array of linked lists
	bool* visited;
	Graph(int v){
		V = v;
		adj = new list<int>[V];
		visited = new bool[V];
		for (int i = 0; i < V; ++i){
			visited[i] = 0;
		}
	}
	void AddEdge(int v, int w){ //add w to v's list
		adj[v].push_back(w);
	}

	void DFS(int start){ //Depth first traversal of all vertices reachable from start
		
		visited[start] = 1;
		list<int>::iterator i; 
		
		for (i = adj[start].begin(); i != adj[start].end(); ++i){
			if (!visited[*i])
				DFS(*i);	
		}
	}

};
