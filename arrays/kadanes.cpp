

/// This is an algorithm for max sum contiguous subarray

#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;

    int n;
    cin >> n;
    ll nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // int n = nums.size();
    /// initialised sum as the first element so that if all elements are negative then ans can be max negative number
    int sum = nums[0], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cerr << ans << " " << nums[i] << "\n";
        if (ans < 0)
        {
            ans = 0;
        }
        ans += nums[i];
        sum = max(ans, sum);
    }

    cout << sum << "\n";

    return 0;
}