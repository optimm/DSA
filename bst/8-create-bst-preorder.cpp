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
// using stack - self written
Node *createBST(vector<int> pre)
{
    int n = pre.size();
    stack<Node *> st;
    Node *root = new Node(pre[0]);
    st.push(root);
    for (int i = 1; i < n;)
    {
        Node *x = st.top();
        Node *curr = new Node(pre[i]);
        if (pre[i] < x->data)
        {
            x->left = curr;
            st.push(curr);
            i++;
        }
        else
        {
            st.pop();
            if (!st.empty())
            {
                Node *y = st.top();
                if (y->data > pre[i])
                {
                    x->right = curr;
                    st.push(curr);
                    i++;
                }
            }
            else
            {
                x->right = curr;
                st.push(curr);
                i++;
            }
        }
    }
    return root;
}

// using min and max // time and space same
Node *createBST1(vector<int> &pre, int i, int bound)
{
    if (i == pre.size() || pre[i] > bound)
        return NULL;
    Node *root = new Node(pre[i]);
    root->left = createBST1(pre, i + 1, root->data);
    root->right = createBST1(pre, i + 1, bound);
    return root;
}

int main()
{
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    int i = 0;
    // pass int max as bound and call the 1named function
}
