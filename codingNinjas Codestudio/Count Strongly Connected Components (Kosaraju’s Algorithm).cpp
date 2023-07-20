#include<bits/stdc++.h>
using namespace std;
// can't say why the topological sort applied using kahn's algorithm gives wrong result

void topologicalSortDFS(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk, int node){
	// Base Case
	if(visited[node]) return;
	visited[node] = true;
	for(auto neighbour : adj[node]){
		topologicalSortDFS(adj, visited, stk, neighbour);
	}
	stk.push(node);
}

void dfsSCC(vector<vector<int>> &rAdj, vector<bool> &visited, int node){
	// Base Case
	if(visited[node]) return;
	visited[node] = true;
	for(auto neighbour : rAdj[node]){
		dfsSCC(rAdj, visited, neighbour);
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Kusaraju Algorithm
	// Step 1: Topological Sort.
	// Step 2: Reversed the edges of the graph.
	// Step 3: DFS Traversal to get the strongly conected components.
	// Time Complexity: O(E + V)
	// Space Complexity: O(E + V)
	// Build the Adjacency List and Reverse Adjasency list together.
	vector<vector<int>> adj(v);
	vector<vector<int>> rAdj(v);
	for(auto edge : edges){
		adj[edge[0]].push_back(edge[1]);
		rAdj[edge[1]].push_back(edge[0]);
	}
	// Step 1: Topological sort
	// Visited Array
	vector<bool> visited(v, false);
	// Stack to store the sorted vertices
	stack<int> stk;
	// Topological Sort
	for(int i = 0; i < v; i++){
		if(!visited[i]) topologicalSortDFS(adj, visited, stk, i);
	}
	// Step 2: Reverse the Graph
	// already done while making the adjacency list
	// Reseting the visited array
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}
	// Step 3: DFS Traversal
	int totalSCC = 0;
	while(!stk.empty()){
		int curr = stk.top();
		stk.pop();
		if(!visited[curr]){
			totalSCC++;
			dfsSCC(rAdj, visited, curr);
		}
	}
	return totalSCC;
}

int main()
{
    int v=5;
    vector<vector<int>> edges={{0,1},{1,2},{1,4},{2,3},{3,2},{4,0}};
    cout<<stronglyConnectedComponents(v,edges);
    return 0;
}
/*
int v=5;
vector<vector<int>> edges={{0,1},{1,2},{1,4},{2,3},{3,2},{4,0}};

int v=8;
vector<vector<int>> edges={{0,1},{1,2},{2,0},{1,3},{3,2},{3,4},{2,4},{5,3},{4,5},{6,4},{5,6},{7,5},{6,7}};
*/
