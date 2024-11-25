#include <bits/stdc++.h>
using namespace std;

vector<int> calculateLPS(string s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int j = 0; // Length of previous longest prefix suffix
    int i = 1; // Start checking from the second character

    while (i < n)
    {
        if (s[i] == s[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps; // Ensure the LPS vector is returned properly
}

int main()
{
    string s;
    cout << "Enter the String: ";
    cin >> s;

    vector<int> lps = calculateLPS(s);

    cout << "The LPS array is: ";
    for (int &i : lps)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
