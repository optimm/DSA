#include <bits/stdc++.h>
#define ll long long
using namespace std;
int count(string s)
{
    /// dp baseda approach
    int n = s.length();
    vector<vector<bool>> v(n, vector<bool>(n));
    int ans = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                v[i][j] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    v[i][j] = true;
                else
                    v[i][j] = false;
            }
            else
            {
                if (s[i] == s[j] && v[i + 1][j - 1] == true)
                    v[i][j] = true;
                else
                    v[i][j] = false;
            }
            if (v[i][j] == true)
                ans++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << count(s) << "\n";

    return 0;
}