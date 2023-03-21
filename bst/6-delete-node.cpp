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
void print(vector<ll> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;

    Node *curr = root->right;
    while (curr->left != NULL)
        curr = curr->left;
    curr->left = root->left;
    return root->right;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data == key)
    {
        return helper(root);
    }
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data > key)
        {
            if (curr->left != NULL && curr->left->data == key)
            {
                curr->left = helper(curr->left);
                break;
            }
            curr = curr->left;
        }
        else
        {
            if (curr->right != NULL && curr->right->data == key)
            {
                curr->right = helper(curr->right);
                break;
            }

            curr = curr->right;
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(5);
    Node *r = new Node(7);
    Node *l = new Node(1);
    Node *l1 = new Node(6);
    Node *r1 = new Node(8);
    root->left = l;
    root->right = r;
    r->left = l1;
    r->right = r1;
}
