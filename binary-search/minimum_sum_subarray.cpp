#include <bits/stdc++.h>
using namespace std;
// binary search on length and then check all subarrays of that sum
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
            minl = min(minl, r - l);/// r-l+1 nahi kara kyunki already ek aage jaa chuka hai
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