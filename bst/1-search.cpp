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
bool search(Node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data = val)
        return true;
    if (root->data > val)
        return search(root->left, val);
    return search(root->right, val);
}

int main()
{
    Node *root = new Node(5);
}
