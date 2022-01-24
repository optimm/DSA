#include <bits/stdc++.h>
#define ll long long
using namespace std;
// no smaller on right - find all leaders -- approach can use stack-- next greater
// array based approach - naive - n square
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v;
    int mx = a[n - 1];
    v.push_back(mx);
    // cout << mx << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > mx)
        {
            // cout << a[i] << " ";
            mx = a[i];
            v.push_back(mx);
        }
    }
    reverse(v.begin(), v.end());

    return 0;
}