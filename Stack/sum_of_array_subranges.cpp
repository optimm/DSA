#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
// naive solution is on n square

// long long sum = 0;
// for (int i = 0; i < n; i++)
// {
//     int mini = INT_MAX;
//     int maxi = INT_MIN;
//     for (int j = i; j < n; j++)
//     {
//         mini = min(mini, nums[j]);
//         maxi = max(maxi, nums[j]);
//         sum += maxi - mini;
//     }
// }
// return sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin >> n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++){cin >> a[i];}
    }
    return 0;
}
/// stack based solution--------------------- the key is to find in how many sub arrays x will me min and in how many it will be max

// int[] nextSmallestLeft = findNextSmallestLeftIndex(nums);
// int[] nextSmallestRight = findNextSmallestRightIndex(nums);

// int[] nextLargestLeft = findNextLargestLeftIndex(nums);
// int[] nextLargestRight = findNextLargestRightIndex(nums);

// for (int index = 0; index < nums.length; index++)
// {

//     // how much left and right the current ELement can be the minimum
//     long minleftCount = (index - nextSmallestLeft[index]) - 1;
//     long minrightCount = (nextSmallestRight[index] - index) - 1;

//     // how much left and right the current ELement can be the maximum
//     long maxleftCount = (index - nextLargestLeft[index]) - 1;
//     long maxrightCount = (nextLargestRight[index] - index) - 1;

//     // count of subarrays  for which current elemnt is minimum
//     long totalMinCount = minleftCount + minrightCount + (minleftCount * minrightCount);
//     // count of subarrays  for which current elemnt is maximum
//     long totalMaxCount = maxleftCount + maxrightCount + (maxleftCount * maxrightCount);

//     result += (totalMaxCount - totalMinCount) * nums[index];