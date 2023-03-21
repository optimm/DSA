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
stack<Node *> small;
stack<Node *> large;
// one approach is to store inorder , other to use stacks
void push(Node *root, bool flag)
{
    while (root != NULL)
    {
        if (flag)
        {
            small.push(root);
            root = root->left;
        }
        else
        {
            large.push(root);
            root = root->right;
        }
    }
}
bool twoSum(Node *root, int k)
{
    push(root, true);
    push(root, false);
    while (!small.empty() && !large.empty())
    {
        auto x = small.top();
        auto y = large.top();
        if (x->data + y->data == k)
            return true;
        if (x->data + y->data < k)
        {
            small.pop();
            push(x->right, true);
        }
        else
        {
            large.pop();
            push(y->left, false);
        }
    }
    return false;
}

void clearAll()
{
    while (!small.empty())
        small.pop();
    while (!large.empty())
        large.pop();
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        clearAll();
        cout << twoSum(root, n) << endl;
    }
}
