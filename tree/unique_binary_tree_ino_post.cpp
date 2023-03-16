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

map<int, int> mp;
Node *helper(vector<int> &post, int ps, int pe, vector<int> &ino, int is, int ie)
{
    if (ps > pe || is > ie)
        return NULL;
    Node *root = new Node(post[ps]);
    int ind = mp[post[ps]];
    // ind-is- elements to left
    // ie-ind - elements to right

    // elements kaise divide honge vo likha hai - check karlo samajh aa jaega
    Node *right = helper(post, ps + 1, ps + ie - ind, ino, ind + 1, ie);
    Node *left = helper(post, ps + ie - ind + 1, ps + ie - is, ino, is, ind - 1);
    root->left = left;
    root->right = right;
    return root;
}
Node *buildTree(vector<int> &post, vector<int> &ino)
{
    for (int i = 0; i < ino.size(); i++)
    {
        mp[ino[i]] = i;
    }
    reverse(post.begin(), post.end());
    return helper(post, 0, post.size() - 1, ino, 0, ino.size() - 1);
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

    vector<int> ino = {9, 3, 15, 20, 7};
    vector<int> post = {9, 15, 7, 20, 3};
    Node *root = buildTree(post, ino);
    preorder(root);
    return 0;
}