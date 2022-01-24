///// In c++ deque is implemented using array while in java it is implemented using doubly linked list

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//// this is o(n*k)
// void max_sub(vector<int> v, int k)
// {
//     int n = v.size();
//     vector<int> prev(n, -1);
//     stack<int> st;
//     st.push(0);
//     for (int i = 1; i < n; i++)
//     {
//         while (!st.empty() && v[st.top()] <= v[i])
//         {
//             st.pop();
//         }
//         prev[i] = st.empty() ? -1 : st.top();
//         st.push(i);
//     }
//     for (int i = k - 1; i < n; i++)
//     {
//         if (prev[i] < i - k + 1)
//         {
//             cout << v[i] << " ";
//             continue;
//         }
//         int ans = i;
//         while (prev[ans] >= i - k + 1)
//         {
//             ans = prev[ans];
//         }
//         cout << v[ans] << " ";
//     }
// }

/// better with deque----\n // 2n insertions and removals - O(n)
void print_max_k(vector<int> v, int k)
{
    int n = v.size();
    cout << n << "\n";
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        cout << v[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    cout << v[dq.front()] << " ";
}
int main()
{
    vector<int> v = {20,40,30,10,60};
    // max_sub(v, 3);
    print_max_k(v, 3);

    return 0;
}