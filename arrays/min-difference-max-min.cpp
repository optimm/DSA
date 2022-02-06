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
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];

    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    int mi, ma;

    for (int i = 0; i < n - 1; i++)
    {
        mi = min(smallest, arr[i + 1] - k);
        ma = max(largest, arr[i] + k);

        ans = min(ans, ma - mi);
        debug(mi)
            debug(ma)
                debug(ans)
    }
    return ans;
}
int get(int arr[], int n, int k)
{

    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++)
    {
        // manage for positive and negative here
        t.push_back(make_pair(arr[i] - k, i));
        t.push_back(make_pair(arr[i] + k, i));
    }
    sort(t.begin(), t.end());
    vector<int> vis(n, 0);
    int e = 0, r = 0, l = 0;
    while (e < n && r < t.size())
    {
        if (vis[t[r].second] == 0)
        {
            e++;
        }
        vis[t[r].second]++;
        r++;
    }
    int ans = t[r - 1].first - t[l].first;
    while (r < t.size())
    {
        if (vis[t[l].second] == 1)
        {
            e--;
        }
        vis[t[l].second]--;
        l++;
        while (e < n && r < t.size())
        {
            if (vis[t[r].second] == 0)
            {
                e++;
            }
            vis[t[r].second]++;
            r++;
        }
        if (e == n)
        {
            ans = min(ans, t[r - 1].first - t[l].first);
        }
        else
        {
            break;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << get(a, n, k);

    return 0;
}