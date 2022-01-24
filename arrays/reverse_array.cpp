#include <bits/stdc++.h>
#define ll long long
using namespace std;

void revese(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - i - 1]);
    }
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
    revese(a);

    for (auto it : a)
        cout << it << " ";
    return 0;
}