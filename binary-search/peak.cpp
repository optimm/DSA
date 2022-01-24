#include <bits/stdc++.h>
using namespace std;
int peak(vector<int> v)
{
    int n = v.size();
    int l = 0, h = n - 1;
    if (n == 1)
        return 0;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ((mid == 0 || v[mid - 1] < v[mid]) && (mid == n - 1 || v[mid + 1] < v[mid]))
            return mid;
        if (mid > 0 && v[mid - 1] > v[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
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