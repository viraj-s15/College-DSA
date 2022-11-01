#include <iostream>
#include <vector>
#include <list>
using namespace std;

// creating a custom data type that represents a graph
class Graph {
    //number of vertices is gonna be one data type
    int numberOfVertices;
    // adjacency list is a way to represent a graph
    // it is essentially a linked list of node.
    // each node represents other nodes in the Graph
    // that it is connected to
    vector<list<int>> adjacencyList;

    public:

    Graph(int numberOfVertices); // contructor
    void addEdge(int v, int w); // function that adds edges to the adjacency list
    void BFS(int s); // breadth first search function
};

Graph::Graph(int numberOfVertices) {
    // changing the size of the adjacency list based on the number of vertices in the graph
    this->numberOfVertices = numberOfVertices;
    adjacencyList.resize(numberOfVertices);
}

void Graph::addEdge(int v, int w) {
    // add element to the graph
    adjacencyList[v].push_back(w);
}


// using the adjacency list gives a time complexity of O(v+w)
// this function is only valid for connected graphs i.e. each vertex must be connected to atleast 
// one other vertex
void Graph::BFS(int s) {
    // checking all vertices that are not visited
    vector<bool> visited;
    visited.resize(numberOfVertices, false);
    // mark current node as visited and enqueue it
    visited[s] = true;
    // creating a queue for BFS
    list<int> queue;
    queue.push_back(s);
    while (!queue.empty()) {
        // dequeue the vertex and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        // get all the adjacent vertices of the dequeued vertex. 
        // if any vertex has not been visited, mark it visited and enqueue it
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
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(0);
    return 0;
}