#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
/// lower bound
/// another method is to store the potential answers in ans
int findFloor(vector<long long> v, long long n, long long x)
{

    long long l = 0, r = n - 1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (l - 1 >= 0)
        return l - 1;

    else
    {
        return -1;
    }
}
/// another method by storing in ans
int find_floor(vector<long long> v, long long n, long long x)
{

    long long l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    vector<ll> v = {5, 6, 7, 8, 8, 8, 8, 10, 11, 12, 13};
    ll n = v.size();
    cout << find_floor(v, n, 13);
    return 0;
}