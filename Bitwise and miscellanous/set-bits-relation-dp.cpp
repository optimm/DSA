#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> countBits(int n)
{

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        // even no.s have same no. of bits(1s) as its half
        //  beacuse it is (its half + 0 added at lsb)
        //  eg: 5 = 101 and 10 = 1010
        //  so even no.s will have same no. of set bits as its half

        /// wheareas for odd numbers we have 1 at the lsb so we add (+1)
        // eg: 3= 11 and 7=111
        dp[i] = dp[i / 2] + (i & 1);
    }
    return dp;
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