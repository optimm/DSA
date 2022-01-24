#include <bits/stdc++.h>
#define ll long long
using namespace std;
int equalizeArray(int N, int k, int arr[])
{

    long long steps = 0;
    sort(arr, arr + N);
    int mid = 0;
    if (N % 2 == 1)
    {
        mid = N / 2;
    }
    else
    {
        mid = N / 2 - 1;
    }
    for (long long int i = 0; i < N; i++)
    {

        if ((abs(arr[i] - arr[mid])) % k != 0)
        {
            return -1;
        }
    }
    for (long long int i = 0; i < N; i++)
    {
        long long diff = abs(arr[i] - arr[mid]);
        steps += (diff / k) % 1000000007;
    }
    return steps % 1000000007;
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