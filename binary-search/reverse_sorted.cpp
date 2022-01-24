#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int> v, int x)
{
    int n = v.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;

        if (v[mid] < x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
    //upper bound -r
    // lower bound -l
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {10,9,8,7,6,4,3,1};

    cout << binary_search(v, 11);

    return 0;
}