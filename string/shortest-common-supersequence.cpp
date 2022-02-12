#include <bits/stdc++.h>
#define ll long long
using namespace std;
int lc[1001][1001];
void lcs(string x, string y)
{
    int n = x.size();
    int m = y.size();

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
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
}
/// printing method 1 -- or find lcs and then three pointer-- approach
// int p1=0,p2=0;
// for (char c : lcs)
// {
//     while (str1[p1] != c) // Add all non-LCS chars from str1
//         ans += str1[p1++];
//     while (str2[p2] != c) // Add all non-LCS chars from str2
//         ans += str2[p2++];

//     ans += c; // Add LCS-char and increment both ptrs
//     ++p1;
//     ++p2;
// }
// ans += str1.substr(p1) + str2.substr(p2);
// return ans;
string shortestCommonSupersequence(string x, string y)
{
    lcs(x, y);
    string res = "";
    int i = x.size();
    int j = y.size();

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            res += x[i - 1];
            i--;
            j--;
        }
        else
        {
            if (lc[i - 1][j] >= lc[i][j - 1])
            {
                res += x[i - 1];
                i--;
            }
            else
            {
                res += y[j - 1];
                j--;
            }
        }
    }
    while (i != 0)
    {
        res += x[i - 1];
        i--;
    }
    while (j != 0)
    {
        res += y[j - 1];
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    return 0;
}