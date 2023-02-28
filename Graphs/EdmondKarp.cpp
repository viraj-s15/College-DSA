#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

#define V 100

bool bfs(int residualGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> que;
    que.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && residualGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                que.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}	 	  	 	 		      	  		      	     	 	

int maxFlowEdmondkarp(int graph[V][V], int s, int t)
{
    int u, v;
    int residualGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            residualGraph[u][v] = graph[u][v];

    int parent[V];

    int maxFlow = 0;
    while (bfs(residualGraph, s, t, parent)) {
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
    }

    return maxFlow;
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int graph[V][V] = {0};
    for (int i = 0; i < m; i++) {	 	  	 	 		      	  		      	     	 	
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout << "Max Flow is:" << maxFlowEdmondkarp(graph, s, t);

    return 0;
}
