#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// for weighted --vector pair bana lo
/// adjancy matrix --- n square
void dfs(vector<int> adj[], int vertex, vector<bool> &visited)
{
    visited[vertex] = true;
    cout << vertex + 1 << " ";
    for (int child : adj[vertex])
    {
        if (visited[child])
            continue;
        dfs(adj, child, visited);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(v);
    }
    dfs(adj, 0, visited);

    return 0;
}
