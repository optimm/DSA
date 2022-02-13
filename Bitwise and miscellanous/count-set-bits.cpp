#include <bits/stdc++.h>
#define ll long long
using namespace std;
int count(int n)
{
    int ans = 0;
    // while (n > 0)
    // {
    //     int last = (n & 1);
    //     ans += last;
    //     n = n >> 1;
    // }
    // another-hack----
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}