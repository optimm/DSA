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
map<int, int> mp;
void topView(Node *root, int hor)
{
    // iske liye bhi same baat height ka logic dalna padega
    //  if (root == NULL)
    //      return;
    //  if (mp.count(hor) == 0)
    //      mp[hor] = root->data;

    // topView(root->left, hor - 1);
    // topView(root->right, hor + 1);
}
void bottomView(Node *root, int hor)
{
    if (root == NULL)
        return;
    // will have to check for vertical order also if using this method thus use level ord
    //  mp[hor] = root->data;

    // bottomView(root->left, hor - 1);
    // bottomView(root->right, hor + 1);

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int x = q.size();
        for (int i = 0; i < x; i++)
        {
            auto it = q.front();
            q.pop();
            mp[it.second] = it.first->data;
            if (it.first->left != NULL)
            {
                q.push({it.first->left, it.second - 1});
            }
            if (it.first->right != NULL)
            {
                q.push({it.first->right, it.second + 1});
            }
        }
    }
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

    bottomView(root, 0);
    for (auto it : mp)
    {
        cout << it.second << " ";
    }
}