#include <bits/stdc++.h>
#define ll long long
using namespace std;
// split into equal substrs of equal 0s and 1s
int split(string s)
{
    int n = s.size();
    int ans = 0;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            c0++;
        else
            c1++;

        if (c0 == c1)
        {
            ans++;
        }
    }
    if (c0 != c1)
        return -1;

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << split(s);
    return 0;
}