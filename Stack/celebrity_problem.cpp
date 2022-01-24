#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &v, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() >= 2)
    {
        int x = st.top();
        st.pop();
        int y = st.top();
        st.pop();
        if (v[x][y] == 1)
        {
            st.push(y);
        }
        else
        {
            st.push(x);
        }
    }
    int m = st.top();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (v[m][i] == 1)
            return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != m && v[i][m] == 0)
            return -1;
    }
    return m;
}
int main()
{
    vector<vector<int>> v = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};

    cout << celebrity(v, 3);
    return 0;
}