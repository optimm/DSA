#include <bits/stdc++.h>
#define ll long long
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
// There are two appoaches to the problem
// 1-n square - dynamic programming - for each index we find out the min jumps required to reach it
int min_jumps(vector<int> v)
{
    int n = v.size();
    int t[n];
    fill(t, t + n, INT_MAX);
    t[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j + v[j] >= i)
            {
                t[i] = max(t[i], t[j] + 1);
                // kisi element tak pohonchne me uske peeche wale(jisse yahan tak jump possible hai) tak pohonchna + 1
            }
        }
    }
    if (t[n - 1] == INT_MAX)
        return false;
    else
        return true;
}
int min_jumpss(vector<int> v)
{
    int n = v.size();
    if (n == 1)
        return 0;
    if (v[0] == 0)
        return -1;
    int r = v[0], ans = 1, steps = v[0];

    for (int i = 1; i < n; i++)
    {
        if (r < i)
            return -1;
        if (i == n - 1)
            return ans;

        r = max(r, i + v[i]);
        steps--;
        if (steps == 0)
        {
            ans++;
            steps = r - i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << min_jumpss(a);
    return 0;
}