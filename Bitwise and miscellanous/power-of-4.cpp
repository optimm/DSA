#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPowerOfFour(int n)
{
    if (n <= 0)
    {
        return false;
    }

    int m = n & (n - 1);
    if (m != 0)
        return false;
    int r = (int)log2(n);

    if (r % 2 != 0)
        return false;

    return true;
    // return bitset<32>(n).count() == 1 && (31 - __builtin_clz(n)) % 2 == 0;
    // this built in gives leading zeroes in number--binary
    // if it is power of 4 in zero based indexing one will be presnt at even position
    /// if and with 1431655765 is not zero means 1 is at even position as in this position 1 is present at all even poss
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