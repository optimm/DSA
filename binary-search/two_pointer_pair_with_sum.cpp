#include <bits/stdc++.h>
using namespace std;
bool pair(vector<int> v, int sum)
{
    int l = 0, r = v.size() - 1;

    while (l < r)
    {
        if (v[l] + v[r] == sum)
            return true;
        if (v[l] + v[r] > sum)
            r--;
        else
            l++;
    }
    return false;
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