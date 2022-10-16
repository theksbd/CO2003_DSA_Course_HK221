#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> graph, int start)
{
  //  traverse all the nodes of the graph from given start node using Breadth First Search algorithm and data structure queue, and print the order of visited nodes.
  queue<int> q;
  vector<bool> visited(graph.size(), false);
  q.push(start);
  visited[start] = true;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (int i = 0; i < int(graph[node].size()); i++)
    {
      if (!visited[graph[node][i]])
      {
        q.push(graph[node][i]);
        visited[graph[node][i]] = true;
      }
    }
  }
}

int main()
{
  int init_graph[10][10] = {{0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
                            {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                            {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                            {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                            {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}};
  int n = 10;
  vector<vector<int>> graph(n, vector<int>());
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (init_graph[i][j])
        graph[i].push_back(j);
    }
  }

  bfs(graph, 0);
  return 0;
}