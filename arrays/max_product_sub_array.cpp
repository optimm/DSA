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
// right left dono side se chalne ka kar sakte hai - observation-hai
// just keep finding max prod -- if prod ==0 prod =1;
/// this is another approach-- checlk notebook
long long maxProduct(vector<int> arr, int n)
{
    long long ans = LLONG_MIN, curr = 1, last = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            curr *= arr[i];
            last = min(last * arr[i], 1LL);
            ans = max(ans, curr);
        }
        else if (arr[i] < 0)
        {
            int y = curr;
            curr = max(last * arr[i], 1LL);
            last = y * arr[i];
            ans = max(ans, curr);
        }
        else
        {
            curr = last = 1;
        }
    }

    return ans;
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
    cout << maxProduct(a, n);
    return 0;
}