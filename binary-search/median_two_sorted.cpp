#include <bits/stdc++.h>
using namespace std;
// if there are total odd elements then div happens such that the left half has one extra element
// the main concept here is that we divide array in two havles of equal elements and check if all elements in left half are smaller than that in right half if yes than we have reached the median point
double median(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
        return median(b, a);
    int n1 = a.size(), n2 = b.size();
    int l = 0, r = n1;
    while (l <= r)
    {
        int i = l + (r - l) / 2;
        int j = (n1 + n2 + 1) / 2 - i;
        int min1 = i == n1 ? INT_MAX : a[i];
        int max1 = i == 0 ? INT_MIN : a[i - 1];
        int min2 = j == n2 ? INT_MAX : b[j];
        int max2 = j == 0 ? INT_MIN : b[j - 1];
        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((double)max(max1, max2) + min(min1, min2)) / 2;
            else
                return ((double)max(max1, max2));
        }
        if (max1 > min2)
            r = i - 1;
        else
            l = i + 1;
    }
    return ((double)-1);
}
int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};

    cout << median(a, b);

    return 0;
}