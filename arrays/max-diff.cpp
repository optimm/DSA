#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mx = a[n - 1];
    int res = -1;
    for (int i = n - 2; i >= 0; i--)
    {

        if (a[i] > mx)
        {
            mx = a[i];
        }
        else if (a[i] < mx)
        {
            res = max(res, mx - a[i]);
        }
    }
    cout << res << "\n";
    return 0;
}