#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;

int arr[15], n = 15, k = 3, top[3], nex[15], freetop = 0;
void stac()
{
    fill(top, top + 3, -1);
    for (ll i = 0; i < n - 1; i++)
    {
        nex[i] = i + 1;
    }
    nex[n - 1] = -1;
}
void push(int x, int m)
{
    int i = freetop;
    arr[i] = x;
    freetop = nex[i];
    nex[i] = top[m];
    top[m] = i;
}
void pop(int m)
{
    int i = top[m];
    top[m] = nex[i];
    nex[i] = freetop;
    freetop = i;
    cout << arr[i] << "\n";
}
int main()
{
    stac();
    push(3, 0);
    push(4, 0);
    push(5, 1);
    pop(0);
    pop(1);
    return 0;
}