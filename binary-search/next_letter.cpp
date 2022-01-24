#include <bits/stdc++.h>
using namespace std;
char next_letter(vector<char> v, char x)
{
    int low = 0, high = v.size() - 1, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
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