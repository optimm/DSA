#include <bits/stdc++.h>
using namespace std;

int binary_searchs(vector<int> v, int l, int r, int x)
{

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == x)
        {
            return binary_searchs(v, l, mid - 1, x) + binary_searchs(v, mid + 1, r, x) + 1;
        }
        else if (v[mid] < x)
        {
            return binary_searchs(v, mid + 1, r, x);
        }
        else
            return binary_searchs(v, l, mid - 1, x);
    }
    return 0;
}

int main()
{
    vector<int> v = {5, 6, 7, 7, 8, 8, 8, 10, 11, 11, 12, 12, 13};
    int n = v.size();
    cout << binary_searchs(v, 0, n - 1, 5);
    return 0;
}