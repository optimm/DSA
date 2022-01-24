#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
struct mystack
{
    node *head;
    int sz = 0;
    void push(int d)
    {
        node *x = new node(d);
        x->next = head;
        head = x;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        node *temp = head;
        head = head->next;
        int x = temp->data;
        delete (temp);
        sz--;
        return x;
    }
    int size()
    {
        return sz;
    }
    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    int peak()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    struct mystack s;
    s.push(5);
    s.push(10);
    s.push(11);
    s.push(11);

    cout << s.pop() << endl;
    cout << s.peak() << endl;
    cout << s.size() << endl;
    cout << s.isempty() << endl;
}
