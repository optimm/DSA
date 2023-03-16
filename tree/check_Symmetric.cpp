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

bool check(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    // have to do it like a mirror image- have to check for opposite directions
    return check(left->left, right->right) && check(left->right, right->left);
}

int main()
{
    Node *root;
    if (root == NULL)
    {
        cout << true;
    }
    else
    {
        cout << check(root->left, root->right);
    }
}