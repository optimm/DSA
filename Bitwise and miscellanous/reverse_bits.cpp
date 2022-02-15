#include <bits/stdc++.h>
#define ll long long
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    uint32_t rev = 0, mask = 0;
    for (int i = 0; i < 32; i++)
    {
        mask = (1 << i); // iterate over each bit from right to left
        if (n & mask)
        {                           // check if bit is set in the number
            rev |= (1 << (31 - i)); // set that ith bit from left to right position i.e ( 31 - i )
        }
    }
    return rev;
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