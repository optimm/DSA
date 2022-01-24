#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// finds distinct second largest
int second_largest(vector<int> a)
{
    int n = a.size();

    int maxi = a[0], smaxi = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxi)
        {
            smaxi = maxi;
            maxi = a[i];
        }
        else if (a[i] > smaxi && a[i] < maxi)
        {
            smaxi = a[i];
        }
    }
    return smaxi;
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