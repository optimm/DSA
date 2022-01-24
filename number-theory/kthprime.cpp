#include <bits/stdc++.h>
using namespace std;
#define maxn 9000001
int prime[9000001];

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
    int k;
    cin >> k;
    int i = 2;
    int y = 0;
    while (i < maxn && y != k)
    {
        if (prime[i])
        {
            y++;
        }
        i++;
    }
    cout << i - 1;
}