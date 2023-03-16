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

int lca(Node *root, int p, int q)
{
    if (root == NULL)
        return -1;
    cerr << root->data << endl;
    if (root->data == p || root->data == q)
        return root->data;

    int l = lca(root->left, p, q);
    int r = lca(root->right, p, q);
    if (l != -1 && r != -1)
        return root->data;
    if (r == -1)
        return l;
    return r;
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
    cout << lca(root, 5, 6) << endl;
}