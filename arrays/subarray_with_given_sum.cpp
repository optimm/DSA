#include <bits/stdc++.h>
#define ll long long
using namespace std;
// sliding window - important
vector<int> subarraySum(int arr[], int n, long long s)
{
    int l = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum >= s)
        {
            if (sum == s)
            {
                return vector<int>{l + 1, i + 1}; /// important of return vector
            }
            sum -= arr[l];
            l++;
        }
    }
    return vector<int>{-1};
}
/// when negatives are present
/// interesting approach - check at - https://leetcode.com/problems/subarray-sum-equals-k/solution/
// basic idea is that we maintain a map with sum and frequencies say at i sum is s and s-k already exists before at some j so the sum of elemnts in between will be k thats the basic idea of this approach
int count_subarray(vector<int> &v, int k)
{
    map<int, int> mp;
    int sum = 0;
    int n = v.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (mp[sum - k] > 0)
        {
            c += mp[sum - k];
        }
        mp[sum]++;
    }
    return c;
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
    long long s = 12;
    vector<int> v = subarraySum(a, n, s);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}