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
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void iterativePre(Node *root)
{

    if (root == NULL)
        return;
    Node *curr = root;
    stack<Node *> st;
    // while (curr != NULL || !st.empty())
    // {
    //     while (curr != NULL)
    //     {
    //         cout << curr->data << " ";
    //         st.push(curr);
    //         curr = curr->left;
    //     }
    //     curr = st.top();
    //     st.pop();
    //     curr = curr->right;
    // }

    //***
    // st.push(root);
    // while (!st.empty())
    // {
    //     curr = st.top();
    //     st.pop();
    //     cout << curr->data << " ";
    //     if (curr->right)
    //         st.push(curr->right);
    //     if (curr->left)
    //         st.push(curr->left);
    // }

    //*** not required to push left just print it
    // while (!st.empty() || curr != NULL)
    // {
    //     while (curr != NULL)
    //     {
    //         cout << curr->data << " ";
    //         if (curr->right)
    //             st.push(curr->right);
    //         curr = curr->left;
    //     }
    //     if (!st.empty())
    //     {
    //         curr = st.top();
    //         st.pop();
    //     }
    // }
}
void iterativeIn(Node *root)
{
    if (root == NULL)
        return;
    Node *curr = root;
    stack<Node *> st;
    // method 1
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
void iterativePost(Node *root)
{
    if (root == NULL)
        return;
}

void allIterative(Node *root)
{
    if (root == NULL)
        return;

    stack<pair<Node *, int>> st;
    st.push(make_pair(root, 1));
    int s = 0;
    vector<ll> pre, in, post;
    while (!st.empty())
    {
        auto it = st.top();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            st.pop();
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push(make_pair(it.first->left, 1));
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            st.pop();
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push(make_pair(it.first->right, 1));
        }
        else
        {
            post.push_back(it.first->data);
            st.pop();
        }
    }
    print(pre);
    print(in);
    print(post);
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    // method 1
    //  while (!q.empty())
    //  {
    //      for (int i = 0; i < q.size(); i++)
    //      {
    //          auto x = q.front();
    //          cout << x->data << " ";
    //          q.pop();
    //          if (x->left != NULL)
    //              q.push(x->left);
    //          if (x->right != NULL)
    //              q.push(x->right);
    //      }
    //      cout << endl;
    //  }

    // method 2 using NULL
    // q.push(NULL);
    // while (!q.empty())
    // {
    //     auto x = q.front();
    //     if (x == NULL)
    //     {
    //         if (q.size() > 1)
    //         {
    //             cout << endl;
    //             q.push(NULL);
    //         }
    //     }
    //     else
    //     {
    //         cout << x->data << " ";
    //         if (x->left != NULL)
    //             q.push(x->left);
    //         if (x->right != NULL)
    //             q.push(x->right);
    //     }
    //     q.pop();
    // }
}

void spiral(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int x = q.size();
        vector<ll> v(x);

        for (int i = 0; i < x; i++)
        {
            auto it = q.front();
            int idx = flag == true ? i : x - i - 1;
            v[idx] = it->data;
            q.pop();
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
        flag ^= 1;
        print(v);
    }
}

void boundary(Node *root)
{
    if (root == NULL)
        return;
    // left
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL && curr->right != NULL)
            cout << curr->data << " ";
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
    // leaves
    stack<Node *> st;
    curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if (curr->left == NULL && curr->right == NULL)
            cout << curr->data << " ";
        curr = curr->right;
    }
    // right ulta lena hai store karke
    curr = root;
    curr = curr->right;
    while (curr != NULL)
    {
        if (curr->left != NULL && curr->right != NULL)
            cout << curr->data << " ";
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
}
map<int, vector<ll>> mp;
void dfs(Node *root, int hor)
{
    if (root == NULL)
        return;

    mp[hor].push_back(root->data);
    dfs(root->left, hor - 1);
    dfs(root->right, hor + 1);
}
void verticalOrder(Node *root)
{
    dfs(root, 0);
    for (auto x : mp)
    {
        print(x.second);
    }
}
// inorder morris
void morrisTraversal(Node *root)
{
    if (root == NULL)
        return;

    Node *curr = root;
    while (curr != NULL)
    {
        Node *lefti = curr->left;
        if (lefti == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            while (lefti->right != NULL && lefti->right != curr)
            {
                lefti = lefti->right;
            }
            // create link
            if (lefti->right == NULL)
            {
                lefti->right = curr;
                curr = curr->left;
            }
            // break link
            else
            {
                lefti->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
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
    inorder(root);
    cout << endl;
    // boundary(root);
    // verticalOrder(root);
    morrisTraversal(root);
}
