#include <bits/stdc++.h>
using namespace std;
int main()
{
}
// naive method is to find the pivot  ,, i.e the min element and then search in left and right halfs
///---------------------------------------code----------------------------------------------------------
// int binary_search(vector<int> v, int x, int l, int r)
// {

//     while (l <= r)
//     {
//         int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
//         if (v[mid] == x)
//             return mid;

//         if (v[mid] < x)
//             l = mid + 1;
//         else
//             r = mid - 1;
//     }
//     return -1;
// }

// int pivot(vector<int> v)
// {
//     int n = v.size();
//     int low = 0, high = n - 1;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (v[low] <= v[high])
//         {
//             return low;
//         }
//         int next = (mid + 1) % n;
//         int prev = (mid + n - 1) % n;
//         if (v[mid] <= v[prev] && v[mid] <= v[next])
//         {
//             return mid;
//         }
//         else if (v[mid] <= v[high])
//         {
//             high = mid - 1;
//         }
//         else if (v[mid] >= v[low])
//         {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }

// int search(vector<int> &nums, int target)
// {
//     int mi = pivot(nums);
//     int y = binary_search(nums, target, 0, mi - 1) + binary_search(nums, target, mi, nums.size() - 1) + 1;
//     return y;
// }
///---------------------------------------code----------------------------------------------------------

/// one more using binary search is to check which half is rotated and then search in it

int binary_search(vector<int> v, int x, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;
        else if (v[mid] >= v[l])
        {
            if (x >= v[l] && x <= v[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (x >= v[mid] && x <= v[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

///// solution for with duplicates

int binary_search(vector<int> v, int x, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // use this as can overflow in (h+l)/2
        if (v[mid] == x)
            return mid;
        if (v[mid] == v[l] && v[mid] == v[r]) /// the corner case here we have to decrease the search space
            r--, l++;
        else if (v[l] <= v[mid])
        {
            if (x >= v[l] && x < v[mid])
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        else
        {

            if (x <= v[r] && x > v[mid])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    return -1;
}
