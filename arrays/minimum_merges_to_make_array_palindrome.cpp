#include <bits/stdc++.h>
#define ll long long
using namespace std;
// problem link https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
int min_operations(vector<int> &a)
{

    int i = 0, j = a.size() - 1;
    int ans = 0;
    while (i <= j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        if (a[i] < a[j])
        {
            a[i + 1] = a[i] + a[i + 1];
            i++;
            ans++;
        }
        else
        {
            a[j - 1] = a[j - 1] + a[j];
            j--;
            ans++;
        }
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