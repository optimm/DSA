// check if a string is valid shuffle of
/// cannot use map - order same rehna chahiye

#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(string a, string b, string c)
{
    int l1 = a.size();
    int l2 = b.size();
    int r = c.size();
    if ((l1 + l2) != r)
        return false;
    int i = 0, j = 0, k = 0;
    while (k < r)
    {
        if (a[i] == c[k])
            i++;
        else if (b[j] == c[k])
            j++;
        else
        {
            break;
        }
        k++;
    }
    return (i == l1 && j == l2);
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