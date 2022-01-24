#include <bits/stdc++.h>
using namespace std;
int ceilingInSortedArray(int n, int x, vector<int> &v)
{

    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return x;

        if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (r + 1 <= n - 1)
        return v[r + 1];

    else
        return -1;
}
//// another method by storing in ans
int ceiling(int n, int x, vector<int> &v)
{

    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {5, 6, 7, 8, 8, 8, 8, 10, 11, 12, 13};
    int n = v.size();
    cout << ceiling(n, 9, v);
    return 0;
}