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
vector<int> res;
bool path(Node *root, int target)
{
    if (root == NULL)
        return false;
    if (root->data == target)
    {
        res.push_back(target);
        return true;
    }
    bool l = path(root->left, target);
    bool r = path(root->right, target);
    if (l || r)
    {
        res.push_back(root->data);
    }
    return l || r;
}

bool nodeToRoot(Node *root, int x, vector<int> &ans)
{
    if (root == NULL)
        return false;
    ans.push_back(root->data);
    if (root->data == x)
        return true;
    if (nodeToRoot(root->left, x, ans) || nodeToRoot(root->right, x, ans))
        return true;
    ans.pop_back();
    return false;
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
    // cout << path(root, 6) << endl;
    vector<int> ans;
    bool flag = nodeToRoot(root, 6, ans);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}