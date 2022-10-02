#include <iostream>

using namespace std;

int shortestString(string s)
{
    // STUDENT ANSWER
    if (s.length() == 1)
        return 1;
    if (s.length() == 2)
        return (s[0] == s[1] ? 2 : 1);
    if (s[0] == s[1])
        return shortestString(s.substr(1));
    int length1 = shortestString(s.substr(1));
    int length2 = shortestString(s.substr(2));
    return length1 < length2 ? length1 : length2;
}

int main()
{
    cout << shortestString("01110");
    return 0;
}