#include <bits/stdc++.h>
using namespace std;
#define ll long long

int check(vector<int> &v, int x)
{
    int n = v.size();
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == x)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if (ans != -1)
    {
        return n - ans;
    }
    return n - l;
}
int hIndex(vector<int> &v)
{
    int n = v.size();
    int l = 0, r = v[n - 1], res = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        int z = check(v, mid);
        if (z >= mid)
        {
            res = mid;
            l = mid + 1;
        }
        if (z < mid)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

/// another observation based approach
// int l = 0, n = arr.length, h = n - 1, ans = -1;

// while (l <= h)
// {
//     int mid = l + (h - l) / 2;
//     if (arr[mid] == n - mid)
//     {
//         return arr[mid];
//     }
//     else if (arr[mid] < n - mid)
//     {
//         l = mid + 1;
//     }
//     else
//     {
//         h = mid - 1;
//     }
// }

// return n - l; --- this is the observation if element not present in array then finally jis index par pohonchta hai l say 1 5 6 7 8 to finally l ki value hoti hai 1 to n-1 sahi ans hota hai
int main()
{
    int n;
    cin >> n;
    vector<int> v = {1, 1};
    cout << hIndex(v);

    return 0;
}