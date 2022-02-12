#include <bits/stdc++.h>
#define ll long long
using namespace std;
// brute force approach --
int lcs_recursive(string s, string s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (s[n - 1] == s2[m - 1])
        return 1 + lcs_recursive(s, s2, n - 1, m - 1);

    return max(lcs_recursive(s, s2, n, m - 1), lcs_recursive(s, s2, n - 1, m));
}
// memozization
int t[1001][1001];

int lcs_memo(string s, string s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (t[n - 1][m - 1] != -1)
        return t[n - 1][m - 1];
    if (s[n - 1] == s2[m - 1])
        return (t[n - 1][m - 1] = 1 + lcs_memo(s, s2, n - 1, m - 1));

    return (t[n - 1][m - 1] = max(lcs_memo(s, s2, n, m - 1), lcs_memo(s, s2, n - 1, m)));
}
// top down----
int lcs(string x, string y)
{
    int n = x.size();
    int m = y.size();
    int lc[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                lc[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                lc[i][j] = lc[i - 1][j - 1] + 1;
            }
            else
            {
                lc[i][j] = max(lc[i - 1][j], lc[i][j - 1]);
            }
        }
    }
    return lc[n][m];
}
int main()
{
    memset(t, -1, sizeof(t));
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    cout << lcs(a, b);

    return 0;
}