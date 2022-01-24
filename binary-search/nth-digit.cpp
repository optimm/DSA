#include <bits/stdc++.h>
#define ll long long
using namespace std;
// this is a good problem
// we first find the min value that is less than our i.e i we find the range like for 38 range se 9-99 and start value is 10 and len is 2 which means 2 digit number is there now we see how many steps ahead we are of 9 i.e 38-9 29 now we will see that n-1/len gives the steps ahead we have to move from min n-1 because 10 we have taken
int findNthDigit(int n)
{
    long long int len = 1;
    long long int cnt = 9;
    long long int start = 1;
    while (n > len * cnt)
    {
        n -= len * cnt;
        cnt *= 10;
        start *= 10;
        len++;
    }

    start += (n - 1) / len;
    string s = to_string(start);

    int z = s[(n - 1) % len] - '0';
    return z;
}
int main()
{
    cout << findNthDigit(38);

    return 0;
}