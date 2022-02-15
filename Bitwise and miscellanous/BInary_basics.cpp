/// left shift --- a<<b - a*2^b
/// odd even if a&1--- odd else even
//// power of two check---- if n is a power of two then n & n-1 === 0
/// set ith bit
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n = 5;
    n = n << 1;
    cout << n << "\n";

    return 0;
}