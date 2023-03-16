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
int ans = 0;
int maxPath(Node *root)
{
    if (root == NULL)
        return 0;
    int ls = maxPath(root->left);
    int rs = maxPath(root->right);
    ans = max(ans, ls + rs + root->data);
    return root->data + max(ls, rs);
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
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = r1;
    r1->left = target;
    r->left = target1;
    r->right = target2;

    int m = maxPath(root);
    cout << ans << endl;

    return 0;
}