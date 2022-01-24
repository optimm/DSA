#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
// sqrt functions c++--- sqrl for long long - and convert type
// bool isPerfectSquare(long long x)
// {
//     // Find floating point value of
//     // square root of x.
//     if (x >= 0)
//     {

//         long long sr = sqrt(x);

//         // if product of square root
//         // is equal, then
//         // return T/F
//         return (sr * sr == x);
//     }
//     // else return false if n<0
//     return false;
// }
// check if its a perfect square
/// by floor
int root(int x)
{
    int low = 1, high = x / 2, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sq = (mid) * (mid);
        if (sq == x)
        {
            return mid;
        }
        else if (sq > x)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
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
        int n;
        cin >> n;
        cout << root(n) << endl;
    }
    return 0;
}