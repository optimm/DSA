
#include <bits/stdc++.h>
#define ll long long
using namespace std;
/// for weighted --vector pair bana lo
/// adjancy matrix --- n square
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    return 0;
}