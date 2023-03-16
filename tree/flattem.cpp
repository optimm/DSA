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

void flatten(Node *root, Node *last)
{

    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cerr << root->data << endl;
        last = root;
        return;
    }

    Node *lefti = root->left;
    Node *righti = root->right;
    root->left = NULL;
    Node *lasti = NULL;
    flatten(lefti, lasti);
    if (lasti != NULL)
        cerr << lasti->data << endl;
    flatten(righti, lasti);
    root->right = lefti;
    while (lefti->right != NULL)
    {
        lefti = lefti->right;
    }
    lefti->right = righti;
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

    flatten(root, NULL);

    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}
