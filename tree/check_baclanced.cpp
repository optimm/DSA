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
int check(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = check(root->left);
    int rh = check(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

int main()
{
    Node *root = new Node(1);
    Node *l = new Node(2);
    Node *r = new Node(3);
    Node *l1 = new Node(4);
    Node *r1 = new Node(5);
    Node *target = new Node(6);
    Node *target1 = new Node(7);
    Node *target2 = new Node(8);
    Node *target3 = new Node(9);
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = r1;
    r1->left = target;
    r->left = target1;
    r->right = target2;
    target->left = target3;

    int lr = check(root);
    if (lr == -1)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}