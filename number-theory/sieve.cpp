#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000
int prime[1000000];

void sieve()
{

    for (int i = 0; i < maxn; i++)
    {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;

    for (int i = 0; i * i < maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < maxn; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
int main()
{
    sieve();
    cout << prime[37];
}