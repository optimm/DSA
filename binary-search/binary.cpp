#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
// iterative binary search
int binary_search(vector<int> v, int x)
{
    int n = v.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {5, 6, 7, 8, 8, 8, 8, 10, 11, 12, 13};
//                   0  1  2  3  4  5  6   7   8   9   10
    cout << binary_search(v, 0);

    return 0;
}