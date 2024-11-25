#include <bits/stdc++.h>
using namespace std;

string makeSubString(string s, int start, int end)
{
    string t = "";
    for (int i = start; i < end; i++)
    {
        t += s[i];
    }
    return t;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int n = s.size();
    string t;
    cout << "Enter the substring: ";
    cin >> t;
    int m = t.size();
    for (int i = 0; i <= n - m; i++)
    {
        if (makeSubString(s, i, i + m) == t)
        {
            cout << "The substring is present at index " << i << endl;
            return 0;
        }
    }
    cout << "The substring is not present" << endl;
    return 0;
}