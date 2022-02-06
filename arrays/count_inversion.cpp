

/// policy based data structure also learned
//find_by_order(k) - kth element in a set counting from 0
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
// if i write greater here will arrange in decreasing order
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

long long int inversionCount(long long a[], long long n)
{

    ll ans = 0;
    omset<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += s.order_of_key(a[i]); // gives elements strictly smaller than this element
        s.insert(a[i]);
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << inversionCount(a, n);

    return 0;
}