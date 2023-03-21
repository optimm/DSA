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
// one method is to store the inorder -- sorted
// other method -- if root's val is larger than largest in the left subtree and smaller than the smallest in the right subtree then it is valid  and left subtree and right subtree should also be valid - tc(n**2), sc(o(H))
 
// efficient - ham har node pe parent node ki value pass karenge - like root se right jaa raha hu to min hogaya rootval+1 -- issey >= hone chahiye aage ke sab value - Tc(o(n)), sp(o(h))
// types ka dhyan rakhna isme
bool validate(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data < min || root->data > max)
        return false;

    if (!validate(root->left, min, root->data - 1) || !validate(root->right, root->data + 1, max))
        return false;

    return true;
}

// inorder manner - passing the prev node
bool isBSTUtil(Node *root, Node *&prev)
{

    if (root)
    {
        if (!isBSTUtil(root->left, prev))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}

int main()
{
    Node *root = new Node(5);
    Node *r = new Node(7);
    Node *l = new Node(1);
    Node *l1 = new Node(6);
    Node *r1 = new Node(8);
    root->left = l;
    root->right = r;
    r->left = l1;
    r->right = r1;
    cout << validate(root, INT32_MIN, INT32_MAX);
}
