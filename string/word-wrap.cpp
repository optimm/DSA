#include <bits/stdc++.h>
#define ll long long
using namespace std;
int word_wrap(vector<int> arr, int m)
{
    int n = arr.size();
    int a[n + 1];
    /// amking one based indexing
    for (int i = 1; i <= n; i++)
        a[i] = arr[i - 1];

    int space[n + 1][n + 1];
    ///// calculating spaces left if we put from i-j in line i;
    int ls[n + 1][n + 1];
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        space[i][i] = m - a[i];
        for (int j = i + 1; j <= n; j++)
        {
            space[i][j] = space[i][j - 1] - a[j] - 1;
        }
    }
    //// calculating cost --- if space negative -- change to infinite
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (space[i][j] < 0)
                ls[i][j] = INT_MAX;
            else if (j == n && space[i][j] >= 0) //// for last line cost-zero
                ls[i][j] = 0;
            else
                ls[i][j] = space[i][j] * space[i][j];
        }
    }
    /// making the cost array
    //// yahi dekh rahe hai ki kisi j tak ki cost or fir c[j][i] ko add karne se current cost se kam hai to current cost ko update kar denge
    // kis j pe split karenge vohi nikal rahe hai
    for (int i = 1; i <= n; i++)
    {
        c[i] = INT_MAX;
        for (int j = 1; j <= i; j++)
        {
            if (c[j - 1] != INT_MAX && ls[j][i] != INT_MAX && c[j - 1] + ls[j][i] < c[i])
                c[i] = c[j - 1] + ls[j][i];
        }
    }
    return c[n];
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