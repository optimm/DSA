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
vector<Node *> help(int s, int e)
{
    vector<Node *> res;
    if (s > e)
    {
        res.push_back(NULL);
        return res;
    }
    for (int i = s; i <= e; i++)
    {
        vector<Node *> lefti = help(s, i - 1);
        vector<Node *> righti = help(i + 1, e);
        for (int j = 0; j < lefti.size(); j++)
        {
            Node *left = lefti[j];
            for (int k = 0; k < righti.size(); k++)
            {
                Node *right = righti[k];
                Node *root = new Node(i);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }
    return res;
}

int main()
{
    vector<Node *> ans = help(1, 5);
}
