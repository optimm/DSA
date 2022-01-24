
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define pb push_back

#define all(a) (a).begin(), (a).end()
#define foi(n) for (ll i = 0; i < n; i++)
#define foj(n) for (ll j = 0; j < n; j++)
#define fok(n) for (ll k = 0; k < n; k++)
#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrr(i, b, a) for (ll i = b; i >= a; i--)

#define sz(v) v.size()

void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll t; cin >> t;
    // while (t--)

    solve();
    cout << "\n";

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> m;
    foi(n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(all(a));
    vector<ll> b;
    ll x = *max_element(a.begin(), a.end());
    foi(x + 1)
    {
        b.pb(m[i] * i);
    }
    // debug(b)
    vector<ll> dp(b.size() + 1, 0);
    if (b.size() == 1)
    {
        cout << b[0];
        return;
    }
    dp[0] = b[0];
    // cout << "hello\n";
    dp[1] = max(b[0], b[1]);
    if (b.size() == 2)
    {
        cout << dp[1];
        return;
    }
    foi(b.size())
    {
        if (i < 2)
            continue;
        dp[i] = max(dp[i - 1], dp[i - 2] + b[i]);
    }
    cout << dp[b.size() - 1];
}