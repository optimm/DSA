#include <bits/stdc++.h>
using namespace std;

//// simple stack application
vector<vector<int>> merge(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> ans;
    vector<pair<int, int>> v;

    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(a[i][0], a[i][1]));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(v[i]);
        }
        else
        {
            if (v[i].first <= st.top().second)
            {
                if (v[i].second > st.top().second)
                {
                    int x = st.top().first;
                    st.pop();
                    st.push(make_pair(x, v[i].second));
                }
            }
            else
            {
                st.push(v[i]);
            }
        }
    }
    // cout<<st.size();
    while (!st.empty())
    {
        vector<int> m = {st.top().first, st.top().second};
        ans.push_back(m);
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
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