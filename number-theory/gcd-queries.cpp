#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
int gcd(int a, int b)
{

    while (b != 0)
    {
        int tem = b;
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, l, r;
        cin >> n >> q;
        int a[n + 10];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int forw[n + 10];
        int backw[n + 10];
        forw[0] = backw[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            forw[i] = gcd(forw[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            backw[i] = gcd(backw[i + 1], a[i]);
        }
        while (q--)
        {
            cin >> l >> r;
            cout << gcd(forw[l - 1], backw[r + 1]) << endl;
        }
    }
    return 0;
}