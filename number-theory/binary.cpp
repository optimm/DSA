#include <bits/stdc++.h>
using namespace std;

int expo(int n, int a, int p)
{

    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = (a * a) % p;
            n /= 2;
        }
        else
        {
            res = (res * a) % p;
            n--;
        }
    }

    return res;
}

int main()
{
    cout << expo(5, 2, 100);
}