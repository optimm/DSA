#include <bits/stdc++.h>
#define ll long long
using namespace std;
void print(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
        {
            if (v[i] != v[0])
            {
                cout << "from " << i << " to ";
            }
            else
            {
                cout << i - 1 << "\n";
            }
        }
    }
    if (v[0] != v[v.size() - 1])
    {
        cout << v.size() - 1 << "\n";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int b = 0;
    vector<int> ones, zero;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            b++;
        }
    }
    if (b == 0 || b == n)
    {
        cout << "0\n";
    }
    print(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (i == 0 || a[i - 1] == 0)
            {
                ones.push_back(i);
            }
            if (i == n - 1 || a[i + 1] == 0)
            {
                ones.push_back(i);
            }
        }
        if (a[i] == 0)
        {
            if (i == 0 || a[i - 1] == 1)
            {
                zero.push_back(i);
            }
            if (i == n - 1 || a[i + 1] == 1)
            {
                zero.push_back(i);
            }
        }
    }

    return 0;
}