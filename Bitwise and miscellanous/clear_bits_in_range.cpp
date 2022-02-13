#include <bits/stdc++.h>
#define ll long long
using namespace std;
void set_range(int &n, int x, int y) // assuming y>x
{
    // int mask = 1 << y;
    // for (int i = y - 1; i >= x; i--)
    // {
    //     mask += 1 << i;
    // }
    // mask = ~mask;
    // n = n & mask;
    /// better method
    // // we wanna form a mask say 111100001111 so we divide in two parts a= 111100000000 and b 000000001111 then mask is a|b
    // int a = (~0) << (y + 1);
    // int b = (1 << x) - 1;
    // mask = a | b;
    // n = n & mask;
}

int main()
{
    int n = 31;
    set_range(n, 1, 3);
    cout << n;

    return 0;
}