#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
/// main goal is to simply find the first occurence of one
int count_ones(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == 1)
        {
            if (mid == 0 || (mid != 0 && arr[mid - 1] != 1))
            {
                return n - mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (arr[mid] == 0)
        {
            if (mid == n - 1 || (mid != n - 1 && arr[mid + 1] == 1))
            {
                return n - mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
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
    cout << count_ones(a, n);

    return 0;
}