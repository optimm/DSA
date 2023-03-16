// objective is to find max distance node from this leaf
// another method - store parent of each node in a map and then do bfs from that node in left right and top direction and also use a vis 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int res = 0;
int burnTime(Node *root, int leaf, int &dist)
{

    if (root == NULL)
        return 0;
    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }
    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);

    if (ldist != -1)
    {
        dist = ldist + 1;
        res = max(res, rh + dist);
    }
    if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, lh + dist);
    }

    return 1 + max(lh, rh);
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