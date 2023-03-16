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
void convert(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = new Node(root->data);
    Node *le = root->left;
    root->left = temp;
    temp->left = le;
    convert(le);
    convert(root->right);
}
void convertBack(Node *root)
{
    if (root == NULL)
        return;
    Node *le = root->left;
    Node *act = le->left;
    root->left = act;
    convertBack(act);
    convertBack(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    Node *l = new Node(2);
    Node *r = new Node(3);
    Node *l1 = new Node(4);
    Node *r1 = new Node(5);
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = r1;

    convert(root);
    convertBack(root);
    preorder(root);
    return 0;
}