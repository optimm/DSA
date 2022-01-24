#include <bits/stdc++.h>
using namespace std;

void primefact(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int c = 0;
            while (n % i == 0)
            {
                c++;
                n = n / i;
            }
            cout << " (" << i << "^" << c << ")"
                 << " ";
        }
    }
    if (n > 1)
    {
        cout << n << "^" << 1;
    }
}

int main()
{
    primefact(36);
}