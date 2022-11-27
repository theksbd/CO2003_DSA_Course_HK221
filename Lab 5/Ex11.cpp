#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
  list<int> adjList;
  int size;

public:
  Adjacency() {}
  Adjacency(int V) {}
  void push(int data)
  {
    adjList.push_back(data);
    size++;
  }
  void print()
  {
    for (auto const &i : adjList)
      cout << " -> " << i;
  }
  void printArray()
  {
    for (auto const &i : adjList)
      cout << i << " ";
  }
  int getSize() { return adjList.size(); }
  int getElement(int idx)
  {
    auto it = adjList.begin();
    advance(it, idx);
    return *it;
  }
};

class Graph
{
private:
  int V;
  Adjacency *adj;

public:
  Graph(int V)
  {
    this->V = V;
    adj = new Adjacency[V];
  }

  void addEdge(int v, int w)
  {
    adj[v].push(w);
    adj[w].push(v);
  }

  void printGraph()
  {
    for (int v = 0; v < V; ++v)
    {
      cout << "\nAdjacency list of vertex " << v << "\nhead ";
      adj[v].print();
    }
  }

  void DFSUtil(int v, bool visited[], Adjacency *adjList)
  {
    visited[v] = true;
    adjList->push(v);
    for (int i = 0; i < adj[v].getSize(); i++)
    {
      int n = adj[v].getElement(i);
      if (!visited[n])
        DFSUtil(n, visited, adjList);
    }
  }

  Adjacency *DFS(int v)
  {
    // v is a vertex we start DFS
    // TODO
    Adjacency *result = new Adjacency(V);
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
      visited[i] = false;
    DFSUtil(v, visited, result);
    return result;
  }
};

int main()
{
  int V = 8, visited = 0;

  Graph g(V);
  Adjacency *arr;
  int edge[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {2, 5}, {2, 6}, {4, 6}, {6, 7}};
  for (int i = 0; i < 9; i++)
  {
    g.addEdge(edge[i][0], edge[i][1]);
  }

  // g.printGraph();
  // cout << endl;
  arr = g.DFS(visited);
  arr->printArray();
  delete arr;
}