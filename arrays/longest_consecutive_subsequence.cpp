#include <bits/stdc++.h>
#define ll long long
using namespace std;
// another simple approach by set
//
// int longestConsecutive(vector<int> &nums)
// {
//     set s;
//     int n = nums.size();
//     if (n == 0)
//     {
//         return 0;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         s.insert(nums[i]);
//     }
//     int ans = 1, prev = INT_MIN, res = 1;
//     for (auto x : s)
//     {
//         // cout<<x<<" ";
//         if (x == prev + 1)
//         {
//             ans++;
//             res = max(ans, res);
//         }
//         else
//         {
//             ans = 1;
//         }
//         prev = x;
//     }

//     return res;
// }
int longest_sequence(vector<int> v)
{
    int n = v.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        int x = v[i] - 1;

        if (s.find(x) == s.end())
        {
            int curr = 0;
            x++;
            while (s.find(x) != s.end())
            {
                curr++;
                x++;
            }
            ans = max(ans, curr);
        }
    }
    return ans;
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
    cout << longest_sequence(a);
    return 0;
}