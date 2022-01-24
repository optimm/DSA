#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &v, int x)
{
    int i = 0, j = v[0].size() - 1;
    int n = v.size(), m = v[0].size();
    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (v[i][j] == x)
            return true;

        if (v[i][j] > x)
            j--;

        else
            i++;
    }
    return false;
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