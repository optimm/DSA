#include <bits/stdc++.h>
using namespace std;
/// this is kind of a tricky problem
// approach -1 - using priority queue
int kthSmalles(vector<vector<int>> &matrix, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            pq.push(matrix[i][j]);
        }
    }
    k = k - 1;
    while (k--)
    {
        pq.pop();
    }
    return pq.top();
}
// another is using binary search
// in this we for each k_dash find out hwo many of the numbers are smaller than k_dash and if that number >=k then we have reduce search space kyonki 8th smallest ke liye ussey chote 7 hone chahiye
// ab maanlo 14 aaya usse chote 8 hai par 14 matrix me nahi hai ab socho ki ussey chota jo number hai  matrix me maanlo aisa hai 1 2 3 4 5 6 7 12 to jo 12 hai uske liye bhi to 8 hi dega ans or 12 present bhi hai matrix me to vohi hua na 8th smallest element

int kthSmallest(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    long long low = mat[0][0], high = mat[n - 1][n - 1];

    while (low <= high)
    {
        int ans = 0;
        long long k_dash = (high + low) / 2;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = n - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (mat[i][m] <= k_dash)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            ans += l;
        }
        if (ans >= k)
        {
            high = k_dash - 1;
        }
        else
        {
            low = k_dash + 1;
        }
    }
    return low;
}
int main()
{
    vector<vector<int>> mat = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};

    cout << kthSmallest(mat, 8);
    return 0;
}