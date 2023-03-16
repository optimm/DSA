#include <bits/stdc++.h>
#define ll long long
using namespace std;

// k levels down - easy using level order traversal
// The basic idea is that we at every node see that the target is found at its left or right and if it is found to kitna doori pe mila hai then uski dusri direction me bhej denge k-dis pe

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
vector<int> res;
void level(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
        res.push_back(root->data);
    else
    {
        level(root->left, k - 1);
        level(root->right, k - 1);
    }
}
int traverse(Node *root, Node *target, int k)
{
    if (root == NULL)
        return -1;
    if (root == target)
    {
        level(target, k);
        return 0;
    }
    int l = traverse(root->left, target, k);
    int r = traverse(root->right, target, k);
    if (l == -1 && r == -1)
        return -1;
    if (l == -1)
    {
        if (k - 1 == r)
        {
            res.push_back(root->data);
        }
        else
            level(root->left, k - r - 2);

        return r + 1;
    }
    if (k - 1 == l)
    {
        res.push_back(root->data);
    }
    else
        level(root->right, k - l - 2);
    return l + 1;
}
int main()
{
    Node *root = new Node(1);
    Node *l = new Node(2);
    Node *r = new Node(3);
    Node *l1 = new Node(4);
    Node *r1 = new Node(5);
    Node *target = new Node(6);
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = r1;
    r1->left = target;

    return 0;
}