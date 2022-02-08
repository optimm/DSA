#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// another solution with binary search can also be done by using lower bound in prefix sum array
int minSubArrayLen(int x, vector<int> &v)
{
    int n = v.size();
    int l = 0, r = 0, minl = n + 1, sum = 0;
    while (r < n)
    {
        while (sum < x && r < n)
        {
            sum += v[r++];
        }
        while (sum >= x && l < n)
        {
            minl = min(minl, r - l);
            sum -= v[l++];
        }
    }
    if (minl == n + 1)
        return 0;
    return minl;
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

    return 0;
}

int minSubArrayLen(int s, vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    vector<int> sums(n + 1, 0); // size = n+1 for easier calculations
    // sums[0]=0 : Meaning that it is the sum of first 0 elements
    // sums[1]=A[0] : Sum of first 1 elements
    // ans so on...
    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1];
    for (int i = 1; i <= n; i++)
    {
        int to_find = s + sums[i - 1];
        auto bound = lower_bound(sums.begin(), sums.end(), to_find);
        if (bound != sums.end())
        {
            ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}