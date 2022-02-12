#include <bits/stdc++.h>
#define ll long long
using namespace std;
int lrs(string x, string y)
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
            if (x[i - 1] == y[j - 1] && i != j)
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
    /// print karne ke liye dp me travel karo and if(d[i][j]== d[i-1][j-1]+1)// to ans me append kardo char warna max ki taraf move kar jao
}
int main()
{
    string s;
    cin >> s;
    cout << lrs(s, s);
    return 0;
}