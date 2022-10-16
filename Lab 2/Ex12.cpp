#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int numberOfTheWinner(int N, int k)
{
  queue<int> q;
  for (int i = 1; i <= N; i++)
    q.push(i);
  int temp = k;
  while (q.size() != 1)
  {
    temp--;
    if (temp == 0)
    {
      q.pop();
      temp = k;
      continue;
    }
    int value = q.front();
    q.pop();
    q.push(value);
  }
  return q.front();
}

int main()
{
  int N = 6;
  int k = 5;
  cout << numberOfTheWinner(N, k);
  return 0;
}