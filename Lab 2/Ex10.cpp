#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long nthNiceNumber(int n)
{
  queue<long long> q;
  q.push(2);
  q.push(5);
  long long result = 0;
  for (int i = 0; i < n; i++)
  {
    result = q.front();
    q.pop();
    q.push(result * 10 + 2);
    q.push(result * 10 + 5);
  }
  return result;
}

int main()
{
  int n = 10000;
  cout << nthNiceNumber(n) << endl;
  return 0;
}