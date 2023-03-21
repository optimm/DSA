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

int pre(Node *root, int target)
{
    int pre = -1;
    while (root != NULL)
    {
        if (root->data >= target)
        {
            root = root->left;
        }
        else
        {
            pre = root->data;
            root = root->right;
        }
    }
    return pre;
}
int succ(Node *root, int target)
{
    int succ = -1;
    while (root != NULL)
    {
        if (root->data <= target)
        {
            root = root->right;
        }
        else
        {
            succ = root->data;
            root = root->left;
        }
    }
    return succ;
}

int main()
{
    Node *root = new Node(5);
    Node *r = new Node(7);
    Node *l = new Node(2);
    Node *l2 = new Node(1);
    Node *r2 = new Node(3);
    Node *l1 = new Node(6);
    Node *r1 = new Node(8);
    root->left = l;
    root->right = r;
    r->left = l1;
    r->right = r1;
    l->left = l2;
    l->right = r2;
    cout << succ(root, 3);
}
