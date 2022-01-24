
//////  This is a vey tricky and good problem in this we maintain one visited array and another array for the last index of elements and start pushing the elemnts into the stack one by one  and let if top of array is larger than the current elemnt and that top element also occures after that index i.e last index of top > i then we keep on popping and also make visited of popped as false and at start of loop we check if element is visited then we continue;

#include <bits/stdc++.h>
#define ll long long
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
// void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
// void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    string s;
    cin >> s;

    vector<int> mp(26, 0);
    vector<bool> vis(26, false);
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i] - 'a'] = i;
    }
    debug(mp) for (int i = 0; i < s.size(); i++)
    {
        if (vis[s[i] - 'a'] == true)
            continue;

        if (!st.empty())
        {
            char x = st.top();
            debug(x);
        }
        debug(s[i]);
        debug(mp[s[i] - 'a'])

            while (!st.empty() && st.top() > s[i] && mp[st.top() - 'a'] > i)
        {
            vis[st.top() - 'a'] = false;

            st.pop();
        }
        vis[s[i] - 'a'] = true;
        st.push(s[i]);
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}