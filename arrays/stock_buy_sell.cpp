#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// naive method recursive  - refere to notebook
// very great implementation in the problem
int stocks(vector<int> a)
{
    int n = a.size();
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            sum += a[i] - a[i - 1];
    }
    return sum;
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