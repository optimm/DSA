#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
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
bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;

    // Reverse the string P
    reverse(P.begin(), P.end());

    // If S is equal to P
    if (S == P)
    {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else
    {
        // return "No"
        return false;
    }
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (isPalindrome(s) || k == 0)
        {
            cout << "1\n";
            continue;
        }
        ll ans = 1;
        for (int i = 0; i < k; i++)
        {
            string y = s;
            reverse(y.begin(), y.end());
            if (!isPalindrome(s + y))
            {
                s += y;
                ans++;
                continue;
            }
            else if (!isPalindrome(y + s))
            {
                s = y + s;
                ans++;
                continue;
            }
            else
            {
                ans++;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}