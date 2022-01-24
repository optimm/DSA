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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    stack<int> s;
    stack<int> min;

    int n;
    cin >> n;
    int arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    min.push(arr[0]);
    int mi = arr[0];
    for (ll i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }

    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < mi)
        {
            mi = arr[i];
        }
        min.push(mi);
    }

    return 0;
}