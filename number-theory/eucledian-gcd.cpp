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
    cout << gcd(7, 18) << "\n\n";
}