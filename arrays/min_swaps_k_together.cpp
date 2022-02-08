#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// count the number of ele <=k then in every window of size k count ele >k the window in which its min will be the answer
int minSwap(int a[], int n, int k)
{
    int i = 0;
    int ele = 0;
    for (i; i < n; i++)
    {
        if (a[i] <= k)
            ele++;
    }
    int ans = 0;
    for (i = 0; i < ele; i++)
    {
        if (a[i] > k)
            ans++;
    }
    int j = 0;
    int c = ans;
    for (i = ele; i < n; i++)
    {
        if (a[i] > k)
            c++;
        if (a[j] > k)
            c--;
        ans = min(ans, c);
        j++;
    }

    return ans;
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