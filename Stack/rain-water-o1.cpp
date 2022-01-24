#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll tem = b;
        b = a % b;
        a = tem;
    }
    return a;
}
// for algo check notebook or https://www.youtube.com/watch?v=PwEdhxQkFZs&ab_channel=Pepcoding

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll l = 0, r = n - 1, ml = 0, mr = 0;
    int res = 0;
    while (l <= r)
    {
        ml = max(ml, arr[l]);
        mr = max(mr, arr[r]);
        if (ml > mr)
        {
            res += mr - arr[r];
            r--;
        }
        else
        {
            res += ml - arr[l];
            l++;
        }
    }
    cout << res << endl;
    return 0;
}