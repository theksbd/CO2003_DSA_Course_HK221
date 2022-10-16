#include <iostream>
#include <vector>

using namespace std;

string removeDuplicates(string S)
{
  /*TODO*/
  vector<char> v;
  for (char c : S)
  {
    if (v.empty())
    {
      v.push_back(c);
      continue;
    }
    if (v.back() == c)
      v.pop_back();
    else
      v.push_back(c);
  }
  string s;
  for (char c : v)
    s += c;
  return s;
}

int main()
{
  cout << removeDuplicates("abbaca");
  return 0;
}