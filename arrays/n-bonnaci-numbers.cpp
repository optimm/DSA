#include <bits/stdc++.h>
#define ll long long
using namespace std;
// simple formula for n bonnaci numbers are a[i] = a[i-1]+a[i-1]+a[n-i-1];
// kind of dp and can be used 
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