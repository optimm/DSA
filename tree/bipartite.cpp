#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[10], col, vis;

bool checkBipartite(int node, int c)
{
    vis[node] = 1;
    col[node] = c;
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            if (checkBipartite(x, !c) == false)
                return false;
        }
        else if (col[x] == col[node])
            return false;
    }
    return true;
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