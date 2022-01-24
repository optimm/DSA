#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
int count_occ(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return 0;
    }
    int mid = (high + low) / 2;
    if (arr[mid] > x)
    {
        return count_occ(arr, low, mid - 1, x);
    }
    if (arr[mid] < x)
    {
        return count_occ(arr, mid + 1, high, x);
    }
    if (arr[mid] == x)
    {
        return count_occ(arr, low, mid - 1, x) + count_occ(arr, mid + 1, high, x) + 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << count_occ(a, 0, n - 1, x) << endl;
    return 0;
}