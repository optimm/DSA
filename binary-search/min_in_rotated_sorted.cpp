// withe the duplicates we can find using thins algo here

#include <bits/stdc++.h>
using namespace std;

int findNumberRotation(vector<int> v)
{
    int n = v.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[low] <= v[high])
        {
            return low;
        }
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (v[mid] <= v[prev] && v[mid] <= v[next])
        {
            return mid;
        }
        else if (v[mid] <= v[high])
        {
            high = mid - 1;
        }
        else if (v[mid] >= v[low])
        {
            low = mid + 1;
        }
    }
    return -1;
}
/////-------------------------------------------------------------
int findMin(vector<int> &v)
{
    int n = v.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (low == high)
            return v[low];
        if (v[low] < v[high])
        {
            return v[low];
        }
        int prev = (mid + n - 1) % n;
        if (v[mid] < v[prev])
        {
            return v[mid];
        }
        else if (v[mid] < v[high])
        {
            high = mid - 1;
        }
        else if (v[mid] > v[low])
        {
            low = mid + 1;
        }
        else
        {
            low++;
        }
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