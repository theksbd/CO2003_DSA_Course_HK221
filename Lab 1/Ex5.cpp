#include <iostream>

using namespace std;

string reverseSentence(string s)
{
    // using recursion
    if (s.length() == 0)
        return "";
    int pos = s.find(" ");
    if (pos == -1)
        return s;
    return reverseSentence(s.substr(pos + 1)) + " " + s.substr(0, pos);
}

int main()
{
    cout << reverseSentence("data structure and algorithm is scary");
    return 0;
}