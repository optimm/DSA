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
// to find height and depth of each node use a map to store;
// Diameter can also be found in the same code
// Max Path sum can also be done using this - instead of height we return max sums
int dia = 0;
int heightBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;

    // depth[root->left]= depth[root]+1 and similar for right
    int lh = heightBinaryTree(root->left);
    int rh = heightBinaryTree(root->right);
    dia = max(dia, lh + rh);
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