#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

// Given a graph represented by an adjacency-list edges.

// Where edges is the adjacency-list representing the graph (this list has between 0 and 1000 lists). This function returns the number of connected components of the graph.

int connectedComponents(vector<vector<int>> &edges)
{
  // STUDENT ANSWER
  int n = edges.size();
  vector<bool> visited(n, false);
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      count++;
      queue<int> q;
      q.push(i);
      visited[i] = true;
      while (!q.empty())
      {
        int u = q.front();
        q.pop();
        for (int v : edges[u])
        {
          if (!visited[v])
          {
            q.push(v);
            visited[v] = true;
          }
        }
      }
    }
  }
  return count;
}

int main()
{
  vector<vector<int>> graph{
      {1},
      {0, 2},
      {1, 3},
      {2},
      {}};
  cout << connectedComponents(graph);
}