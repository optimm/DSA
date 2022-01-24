// iterative - using stack simple

// recursive- we use recursive stack

#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.size() == 1)
    {
        return q;
    }
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(5);
    q.push(3);
    q.push(4);

    reverse(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}