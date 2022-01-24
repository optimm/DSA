#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
int findTheLargestRectangeInHistogram(vector<int> &heights)
{
    stack<int> s;
    int itr = 0, maxArea = -1;
    while (itr < heights.size())
    {
        if (s.empty() || heights[s.top()] <= heights[itr])
        {
            s.push(itr++);
        }
        else
        {
            int top = s.top();
            s.pop();
            int area = heights[top] * (s.empty() ? itr
                                                 : itr - s.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        int area = heights[top] * (s.empty() ? itr
                                             : itr - s.top() - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int ans = 0;
    vector<int> rowArr(cols);
    for (int itr = 0; itr < rows; itr++)
    {
        for (int jtr = 0; jtr < cols; jtr++)
        {
            if (itr == 0)
                rowArr[jtr] = matrix[itr][jtr] == '1' ? 1 : 0;
            else
            { // if value is 1 then add it with the value of rowArr otherwise simple put 0
                if (matrix[itr][jtr] == '1')
                    rowArr[jtr] += matrix[itr][jtr] == '1' ? 1 : 0;
                else
                    rowArr[jtr] = 0;
            }
        }
        ans = max(ans, findTheLargestRectangeInHistogram(rowArr));
    }

    // using the rectangle in histogram solution
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin >> n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++){cin >> a[i];}
    }
    return 0;
}