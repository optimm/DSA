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

int findFloor(Node *root, int val)
{
    int floor = -1;
    while (root)
    {
        if (root->data == val)
            return val;
        if (root->data > val)
            root = root->left;
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
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
}
