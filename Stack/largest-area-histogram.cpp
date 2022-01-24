#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int nsl[n], nsr[n];

    stack<int> s, m;
    s.push(0);
    nsl[0] = -1;
    nsr[n - 1] = n;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        nsl[i] = s.empty() ? (-1) : s.top();
        s.push(i);
    }
    m.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!m.empty() && heights[m.top()] >= heights[i])
        {
            m.pop();
        }
        nsr[i] = m.empty() ? (n) : m.top();
        m.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (nsr[i] - nsl[i] - 1)); /// find nsl and nsr and implement this
    }
    return ans;
}
int main()
{
    vector<int> heights = {2, 4};
    cout << largestRectangleArea(heights);
    return 0;
}
/// another space optimised solution is that we keep on calculating the area as in stack we can find the left smaller as previous and as we reach a number which is smaller than s.top it will be right smaller of s.top

// in this type of stack for each elemnt in stack the prev element is the previous smaller

// stack<int> st;
// int maxA = 0;
// int n = heights.size();
// for (int i = 0; i <= n; i++)
// {
//     while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
//     {
//         int height = heights[st.top()];
//         st.pop();
//         int width;
//         if (st.empty())
//             width = i;
//         else
//             width = i - st.top() - 1;

//         // cout << i << " " << width << " " << height << endl;
//         maxA = max(maxA, width * height);
//     }
//     st.push(i);
// }
// return maxA;