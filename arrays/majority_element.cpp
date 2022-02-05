#include <bits/stdc++.h>
#define ll long long
using namespace std;
// naive- using map- O(n), O(n)
// better - O(n+logn), O(1)- sort then contigious is the element
// the other sol
int majority(vector<ll> v)
{
    int res = 0;
    int c = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[res])
        {
            c++;
        }
        else
        {
            c--;
        }
        if (c == 0)
        {
            res = i;
            c = 0;
        }
    }
    // another loop maybe added to count the occc of v[res] and checked if it is a majority if there is no gurantee that the array has a majority
    return v[res];
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