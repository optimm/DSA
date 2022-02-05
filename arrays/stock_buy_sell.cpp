#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// naive method recursive  - refere to notebook
// very great implementation in the problem
int maxProfit(int price[], int start, int end)
{
    if (end <= start)
        return 0;

    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (price[j] > price[i])
            {
                int curr_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}
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