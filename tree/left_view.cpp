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
void helper(Node *root, int lev, int &maxi)
{
    if (root == NULL)
        return;
    if (lev > maxi)
    {
        cout << root->data << " ";
        maxi = lev;
    }
    helper(root->left, lev + 1, maxi);
    helper(root->right, lev + 1, maxi);
}

vector<int> leftView(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0) // right view me sz-1;
            {
                res.push_back(curr->data);
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return res;
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

    int maxi = 0;
    helper(root, 1, maxi);
    cout << endl;

    vector<int> res = leftView(root);
    for (auto x : res)
    {
        cout << x << " ";
    }
}
