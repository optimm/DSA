#include <bits/stdc++.h>
#define ll long long
using namespace std;
int rearrange(vector<int> &a)
{
    int n = a.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            if (i != j)
                swap(a[i], a[j]);
            j++;
        }
    }
    rotate(a.begin(), a.begin() + j, a.begin() + j);
    return j;
}
// set 1 when order does not matter
void arrange(vector<int> &a)
{
    int n = a.size();
    int x = rearrange(a);
    int k = 0;
    // cout << x << " ";
    // while (k < n && x < n && a[k] >= 0 && a[x] < 0)
    // {
    //     swap(a[k], a[x]);
    //     x++;
    //     k += 2;
    // }
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
    arrange(a);
    for (auto it : a)
        cout << it << " ";
    return 0;
}