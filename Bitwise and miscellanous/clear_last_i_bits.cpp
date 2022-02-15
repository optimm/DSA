#include <bits/stdc++.h>
#define ll long long
using namespace std;
void clear(int &n, int k)
{
    int mask = (~0) << k; /// not zero or -1
    n = n & mask;
}
int main()
{
    int n;
    cin >> n;
    clear(n, 3);
    cout << n << "\n";

    return 0;
}
