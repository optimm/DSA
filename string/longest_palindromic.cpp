#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool c_p(string s)
{
    string r = s;
    reverse(r.begin(), r.end());
    return (r == s);
}
// brute force approacch
string longest(string s)
{
    int n = s.size();
    int ans = 0;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = ans + 1; j <= n; j++)
        {
            string r = s.substr(i, j);
            int len = r.length();
            // cout << r << " " << res << " \n";

            if (c_p(r) == true && len > ans)
            {

                // cerr << r << " " << len << " " << c_p(r) << " " << ans << "\n";

                ans = len;
                res = r;
            }
        }
    }
    return res;
}
int count(string s)
{
    /// dp baseda approach
    int n = s.length();
    vector<vector<bool>> v(n, vector<bool>(n));
    int ans = 1;
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
            {
                ans = max(ans, gap + 1);
            }
        }
    }
    return ans;
}
/// expand around centre ------- n square---o1--better than dp approach
int expand_around(string s, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}
string count_p(string s)
{
    int n = s.size();
    if (n <= 1)
    {
        return s;
    }
    int start = 0, length = 0;

    for (int i = 0; i < n; i++)
    {
        int l1 = expand_around(s, i, i);
        int l2 = expand_around(s, i, i + 1); // for even strings as unme ek hi point se start nahi kar sakte
        int len = max(l1, l2);
        if (len > length)
        {
            start = i - (len - 1) / 2;
            length = len;
        }
    }
    return s.substr(start, length);
}

int main()
{
    string s;
    cin >> s;
    cout << count_p(s);
    return 0;
}