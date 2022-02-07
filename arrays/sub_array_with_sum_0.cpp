#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(vector<int> v)
{
    map<int, int> mp;
    int curr = 0;
    for (int i = 0; i < v.size(); i++)
    {
        curr += v[i];
        if (mp[curr] > 0)
            return true;
        mp[curr]++;
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