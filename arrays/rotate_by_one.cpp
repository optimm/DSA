#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[i], arr[i - 1]);
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

    return 0;
}