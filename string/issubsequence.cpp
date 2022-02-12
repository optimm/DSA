#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool issubsequence(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        // cerr << s[i] << " " << t[j] << "\n";
        if (s[j] == t[i])
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (ans == m);
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << issubsequence(s, t);

    return 0;
}