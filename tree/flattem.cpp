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

void flatten(Node *root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    Node *lefti = root->left;
    Node *righti = root->right;
    root->left = NULL;
    flatten(lefti);
    flatten(righti);
    root->right = lefti == NULL ? righti : lefti;
    while (lefti != NULL && lefti->right != NULL)
    {
        lefti = lefti->right;
    }
    if (lefti != NULL)
    {
        lefti->right = righti;
    }
}

Node *flatten2(Node *root)
{
    if (root == NULL)
        return root;
    stack<Node *> st;
    st.push(root);
    Node *prev = root;
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
        if (curr != prev)
        {
            prev->right = curr;
            prev->left = NULL;
            prev = curr;
        }
    }
    return root;
}

Node *morrisFlatten(Node *root)
{
    if (root == NULL)
        return root;

    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            Node *last = curr->left;
            while (last->right != NULL)
                last = last->right;

            last->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
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

    Node *ans = morrisFlatten(root);

    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->right;
    }
}
