#include <bits/stdc++.h>
#define ll long long
using namespace std;
int get_ith(int n, int k)
{
    int y = 1 << k;
    return (n & y > 0) ? 1 : 0;
}
void set_ith(int &n, int k)
{
    int y = 1 << k;
    n = n | y;
}
void clear(int &n, int k)
{
    int y = 1 << k;
    y = ~y;
    n = n & y;
}
void update_ith(int &n, int k, int v)
{
    clear(n, k);
    int y = v << k;
    n = n | y;
}
int main()
{
    int x = 7;
    clear(x, 1);
    cout << x << endl;

    return 0;
}