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

int kthSmallest(Node *root, int k)
{
    // inorder karo curr badhate jao - if(curr=k) ans lelo us node se
    // morris traversal
    Node *curr = root;
    int ans, tem = 0;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            tem++;
            if (tem == k)
            {
                ans = curr->data;
                break;
            }
            curr = curr->right;
        }
        else
        {
            Node *lefti = curr->left;
            while (lefti->right != NULL && lefti->right != curr)
            {
                lefti = lefti->right;
            }
            if (lefti->right == NULL)
            {
                lefti->right = curr;
                curr = curr->left;
            }
            else
            {
                tem++;
                if (tem == k)
                {
                    ans = curr->data;
                    break;
                }
                lefti->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
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
    int ans = kthSmallest(root, 2);
    cout << ans << endl;
}
