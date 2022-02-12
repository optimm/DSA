#include <bits/stdc++.h>
#define ll long long
using namespace std;
int longest_substring(string x, string y)
{
    int n = x.size();
    int m = y.size();
    int lc[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            lc[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                lc[i][j] = lc[i - 1][j - 1] + 1;
            }
            ans = max(ans, lc[i][j]);
        }
    }
    return ans;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << longest_substring(x, y);

    return 0;
}