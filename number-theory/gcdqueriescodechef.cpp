
#include <bits/stdc++.h>
#define ll long long
#define max 1000000007
using namespace std;

int gcd(int a, int b)
{

    while (b != 0)
    {
        int tem = b;
        b = a % b;
        a = tem;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
        }
    }
}