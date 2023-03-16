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
int calc(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = findHeightleft(root);
    int rh = findHeightRight(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + calc(root->left) + calc(root->right);
}
int findHeightleft(Node *root)
{
    int ans = 0;
    while (root != NULL)
    {
        ans++;
        root = root->left;
    }
    return ans;
}
int findHeightRight(Node *root)
{
    int ans = 0;
    while (root != NULL)
    {
        ans++;
        root = root->right;
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    return 0;
}