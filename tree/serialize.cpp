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
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
string serialize(Node *root)
{
    if (root == NULL)
        return "";
    queue<Node *> q;
    q.push(root);
    string res = to_string(root->data) + " ";
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        if (x->left != NULL)
        {
            q.push(x->left);
            res += to_string(x->left->data) + " ";
        }
        else
        {
            res += "# ";
        }
        if (x->right != NULL)
        {
            q.push(x->right);
            res += to_string(x->right->data) + " ";
        }
        else
        {
            res += "# ";
        }
    }
    res.pop_back();
    return res;
}
void deserialize(string data)
{
    if (data.size() == 0)
        return;
    int i = 0;
    vector<int> v;
    string temp = "";
    while (i < data.size())
    {
        if (isspace(data[i]))
        {
            if (temp == "#")
            {
                v.push_back(2000);
            }
            else
                v.push_back(stoi(temp));

            temp = "";
        }
        else
        {
            temp += data[i];
        }
        i++;
    }
    if (temp == "#")
    {
        v.push_back(2000);
    }
    else
        v.push_back(stoi(temp));
    int ind = 1;
    queue<Node *> q;
    Node *root = new Node(v[0]);
    q.push(root);
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (v[ind] == 2000)
        {
            x->left = NULL;
        }
        else
        {
            Node *l = new Node(v[ind]);
            x->left = l;
            q.push(l);
        }
        ind++;
        if (v[ind] == 2000)
        {
            x->right = NULL;
        }
        else
        {
            Node *r = new Node(v[ind]);
            x->right = r;
            q.push(r);
        }
        ind++;
    }
    inorder(root);
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
    r->left = l1;
    r->right = r1;
    string s = serialize(root);
    // cout << s << endl;
    deserialize(s);
}