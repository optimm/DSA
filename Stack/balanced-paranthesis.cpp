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
    string s;
    cin >> s;
    stack<char> m;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            m.push(s[i]);
            continue;
        }
        if (m.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
        {
            return false;
        }
        if (s[i] == ')')
        {
            if (m.top() == '{' || m.top() == '[')
            {
                return false;
            }
            m.pop();
            continue;
        }
        if (s[i] == '}')
        {
            if (m.top() == '(' || m.top() == '[')
            {
                return false;
            }
            m.pop();
            continue;
        }
        if (s[i] == ']')
        {
            if (m.top() == '(' || m.top() == '{')
            {
                return false;
            }
            m.pop();
            continue;
        }
    }
    return m.empty();
}