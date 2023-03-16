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
vector<vector<ll>> res;
void find(Node *root, vector<ll> &path, int l, int h, int sum)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        sum += root->data;
        if (sum >= l && sum <= h)
        {
            res.push_back(path);
        }
    }
    find(root->left, path, l, h, sum + root->data);
    find(root->right, path, l, h, sum + root->data);
    path.pop_back();
}

int main()
{
    Node *root = new Node(1);
    Node *l = new Node(2);
    Node *r = new Node(3);
    Node *l1 = new Node(4);
    Node *r1 = new Node(5);
    Node *target = new Node(6);
    root->left = l;
    root->right = r;
    l->left = l1;
    l->right = r1;
    r1->left = target;
    vector<ll> path;
    find(root, path, 1, 15, 0);
    for (auto x : res)
    {
        print(x);
    }
    return 0;
}