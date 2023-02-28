#include <iostream>
#include <limits.h>
#include <stack>
#include <string.h>
using namespace std;

#define V 100

bool dfs(int residualGraph[V][V], int s, int t, int parent[], bool visited[])
{
    if (s == t) {
        return true;
    }

    visited[s] = true;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && residualGraph[s][v] > 0) {
            parent[v] = s;
            if (dfs(residualGraph, v, t, parent, visited)) {
                return true;
            }
        }
    }

    return false;
}

int maxFlowFordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    int residualGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            residualGraph[u][v] = graph[u][v];

    int parent[V];

    int maxFlow = 0;
    bool visited[V];

    memset(visited, false, sizeof(visited));

    while (dfs(residualGraph, s, t, parent, visited)) {	 	  	 	 		      	  		      	     	 	
        int pathFlow = INT_MAX;

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;

        memset(visited, false, sizeof(visited));
    }

    return maxFlow;
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    int graph[V][V] = {};
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = c;
    }

    cout << "Max Flow is:"<< maxFlowFordFulkerson(graph, s, t);

    return 0;
}	 	  	 	 		      	  		      	     	 	
