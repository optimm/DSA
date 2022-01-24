#include <bits/stdc++.h>
using namespace std;
int search(vector<int> v, int x)
{
    int n = v.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == x)
            return mid;
        if (mid - 1 >= l && v[mid - 1] == x)
            return mid - 1;
        if (mid + 1 <= r && v[mid + 1] == x)
            return mid + 1;
        if (v[mid] < x)
            l = mid + 2;
        else
            r = mid - 2;
    }
    return -1;
}
int main()
{
    vector<int> v = {5, 10, 30, 20, 40};
    cout << search(v, 40);

    return 0;
}