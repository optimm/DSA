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
Node *helper(vector<int> &preo, int ps, int pe, vector<int> &ino, int is, int ie)
{
    if (ps > pe || is > ie)
        return NULL;
    Node *root = new Node(preo[ps]);
    int ind = mp[preo[ps]];
    // ind-is- elements to left
    // ie-ind - elements to right

    // elements kaise divide honge vo likha hai - check karlo samajh aa jaega
    Node *left = helper(preo, ps + 1, ps + ind - is, ino, is, ind - 1);
    Node *right = helper(preo, ps + ind - is + 1, ps + ie - is, ino, ind + 1, ie);
    root->left = left;
    root->right = right;
    return root;
}
Node *buildTree(vector<int> &preo, vector<int> &ino)
{
    for (int i = 0; i < ino.size(); i++)
    {
        mp[ino[i]] = i;
    }
    return helper(preo, 0, preo.size() - 1, ino, 0, ino.size() - 1);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{

    vector<int> ino = {9, 3, 15, 20, 7};
    vector<int> preo = {3, 9, 20, 15, 7};
    Node *root = buildTree(preo, ino);
    postorder(root);
    return 0;
}