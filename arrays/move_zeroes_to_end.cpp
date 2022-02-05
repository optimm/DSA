
// move negative to one side and positive to other in o1 space

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
void _print(T v[]);
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
void debu(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cerr << arr[i] << " ";
    }
    cerr << "\n";
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    debu(a, n);
    ///// two pointer kind of approach we keep track of the first 0 from left we have and then we swap it with the non zero element that occured and j++ willl always will be zero element as if it was non zero we would have swapped already , it can only be non-zer0 when i=j

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            if (i != j)
                swap(a[i], a[j]);
            j++;
        }
    }

    for (auto it : a)
        cout << it << " ";

    return 0;
}