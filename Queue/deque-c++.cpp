#include <bits/stdc++.h>
using namespace std;

// insert and erase are O(n)

// Queue is a container adapter , it is built over deque

int main()
{
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(20);

    cout << dq.back() << "\n";

    auto it = dq.begin();
    it++;

    dq.insert(it, 12);
    for (auto it : dq)
        cout << it << " ";

    return 0;
}