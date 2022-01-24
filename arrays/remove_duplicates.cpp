#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
//// This is a problem to remove contiguos zeroes and in this we just count the contigous equals and subtract from n;
// can also maintain a vector to keep that distincts
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    int res = n;
    vector<ll> d;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            count++;
        }
        if (a[i] != a[i + 1] || i == n - 2)
        {
            d.push_back(a[i]);
            res = res - count;
            count = 0;
        }
    }
    if (a[n - 1] != a[n - 2])
        d.push_back(a[n - 1]);
    cout << res << "\n";
    for (auto it : d)
        cout << it << " ";

    return 0;
}