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

int main()
{

    return 0;
}