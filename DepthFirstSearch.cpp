#include <iostream>
#include <map>
#include <list>
using namespace std;
 
// Creating a custom data type called graph with custom properties
class Graph {
public:
    // using a map to check the visited nodes here itself
    map<int, bool> visited;
    // using an adjacency list 
    map<int, list<int> > adj;
 
    
    void addEdge(int v, int w); // function to add an edge to graph
    void DFS(int v); // DFS traversal
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // recursively do the same for all the nodes till all the nodes are visited    
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 
// Driver code
int main()
{
     int DfsElement,input1,input2;
    Graph g;
    cout << "Enter the edge the DFS should take place from" << endl;
    cin >> DfsElement;
    cout << "Enter the edge of the graph followed by the vertice it is connected to." << endl;
    cout << "Enter any string to escape the input section of the code" << endl;
    while (cin >> input1 && cin >> input2) {
        g.addEdge(input1,input2);
    }    
    
    cout << "The depth first search traversal of the graph is: ";
    g.DFS(DfsElement);
    cout << endl;
    return 0;
}