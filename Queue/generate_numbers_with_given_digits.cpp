
// Given a number n print first n numbers in increasing order such that they have oly 5 &6 as their digits

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    queue<string> q;

    q.push("5");
    q.push("6");

    for (int i = 1; i <= n; i++)
    {
        string c = q.front();
        cout << c << " ";
        q.pop();
        q.push(c + "5");
        q.push(c + "6");
    }
}