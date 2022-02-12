#include <bits/stdc++.h>
#define ll long long
using namespace std;
string lcs(string x, string y)
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
    string res = "";
    int i = n, j = m;

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
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << lcs(x, y);
}