#include <bits/stdc++.h>
#define ll long long
using namespace std;
// sliding window - important
vector<int> subarraySum(int arr[], int n, long long s)
{
    int l = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum >= s)
        {
            if (sum == s)
            {
                return vector<int>{l + 1, i + 1};/// important of return vector
            }
            sum -= arr[l];
            l++;
        }
    }
    return vector<int>{-1};
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long s = 12;
    vector<int> v = subarraySum(a, n, s);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}