#include <bits/stdc++.h>
#define ll long long
using namespace std;

int check(vector<int> &v, int k)
{
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        c += v[i] / k;
        if (v[i] % k != 0)
            c++;
    }

    return c;
}

int minEatingSpeed(vector<int> &v, int h)
{
    int l = 1, r = 1000000000, ans = h;
    while (l <= r)
    {
        int k = l + (r - l) / 2;
        int z = check(v, k);
        if (z > h) //// agar zada time lag raha hai to ek din me zada khana hoga
        {
            l = k + 1;
        }
        else
        {
            ans = k;
            r = k - 1;
        }
    }
    return l;
}
int main()
{
    vector<int> v = {30, 11, 23, 4, 20};
    cout << minEatingSpeed(v, 6);
    return 0;
}