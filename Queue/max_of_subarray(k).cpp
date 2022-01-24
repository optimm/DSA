#include <bits/stdc++.h>
using namespace std;

/// very simple approach in  this we just evaluate the first k first and then remove the ones which get out of the interval and then add numbers from back if smaller if greater we pop , our goal is to keep the maxs at start

vector<int> maxSlidingWindow(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> res;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        int x = dq.front();
        res.push_back(v[x]);
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    int x = dq.front();
    res.push_back(v[x]);

    return res;
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