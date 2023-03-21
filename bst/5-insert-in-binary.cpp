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

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    Node *curr = root;
    while (true)
    {
        if (curr->data < val)
        {
            if (curr->right != NULL)
                curr = curr->right;
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else
        {
            if (curr->left != NULL)
                curr = curr->left;
            else
            {
                curr->left = new Node(val);
                break;
            }
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
