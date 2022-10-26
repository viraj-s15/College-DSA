#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int numberOfVertices;
    vector<list<int>> adjacencyList;

    public:

    Graph(int numberOfVertices);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;
    adjacencyList.resize(numberOfVertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int s) {
    vector<bool> visited;
    visited.resize(numberOfVertices, false);
    visited[s] = true;
    list<int> queue;
    queue.push_back(s);
    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjacent: adjacencyList[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3,1);    
    g.BFS(2);
    return 0;
}