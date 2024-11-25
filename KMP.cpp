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

vector<int> KMP(string s, string t, vector<int> LPS)
{
    int n = s.size(); // Length of the text
    int m = t.size(); // Length of the pattern
    vector<int> res;
    int i = 0, j = 0; // i for text, j for pattern

    while (i < n)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            res.push_back(i - j);
            j = LPS[j - 1]; // Prepare for next potential match
        }
        else if (i < n && s[i] != t[j]) // Mismatch after `j` matches
        {
            if (j != 0)
            {
                j = LPS[j - 1]; // Reset `j` using LPS
            }
            else
            {
                i++; // Move to next character in text
            }
        }
    }
    return res;
}

int main()
{
    string s = "aaaaabcdaaaazzzz";
    string t = "aaabcdaa";
    int m = t.size();
    int n = s.size();
    vector<int> lps = calculateLPS(t);
    vector<int> ans = KMP(s, t, lps);
    cout << "The Pattern Matches at: ";
    if (ans.size() == 0)
    {
        cout << "-1";
        return 0;
    }
    for (int &i : ans)
    {
        cout << i << " ";
    }
    return 0;
}