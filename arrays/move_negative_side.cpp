
// move negative to one side and positive to other in o1 space

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ///// two pointer kind of approach we keep track of the first positive from left we have and then we swap it with the negative element that occured and j++ willl always will be positive element as if it was negative we would have swapped already , it can only be negative when i=j
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (i != j)
                swap(a[i], a[j]);
            j++;
        }
    }

    for (auto it : a)
        cout << it << " ";

    return 0;
}