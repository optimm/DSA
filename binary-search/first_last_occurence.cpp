#include <bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> v, int x)
{
    int n = v.size();
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
        {
            ans = mid;
            r = mid - 1; /// last occurence me l = mid+1
        }
        else if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    vector<int> v = {5, 6, 7, 7, 8, 8, 8, 10, 11, 11, 12, 12, 13};
    cout << first_occurence(v, 13);

    return 0;
}