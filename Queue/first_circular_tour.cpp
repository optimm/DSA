#include <bits/stdc++.h>
#define ll long long
using namespace std;

//// n square approach
int tour_nsquare(int dist[], int petrol[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        int start = i, end = i;
        while (true)
        {
            curr += petrol[end] - dist[end];
            if (curr < 0)
                break;

            end = (end + 1) % n;

            if (start == end)
                return (start + 1);
        }
    }
    return -1;
}
//// queue approach
int tour_on(int dist[], int petrol[], int n)
{
    queue<int> q;
    int i = 0, curr = 0, start = 0;

    while (true)
    {
        bool flag = true;
        q.push(i);
        curr += petrol[i] - dist[i];

        while (!q.empty() && curr < 0)
        {
            int x = q.front();

            curr -= petrol[x] - dist[x];
            q.pop();

            if (x == n - 1)
            {
                flag = false;
                break;
            }
        }

        if (q.size() == n)
            return (q.front());

        if (!flag)
            break;

        i = (i + 1) % n;
    }
    return -1;
}

///////// Another approach o1 space and on time - one pass solution

int tour_oone(int dist[], int petrol[], int n)
{
    int curr = 0, prev = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        curr += petrol[i] - dist[i];
        if (curr < 0)
        {
            start = i + 1;
            prev += curr;
            curr = 0;
        }
    }
    return (curr + prev >= 0 ? (start) : -1);
}

int main()
{
    int petrol[] = {1, 2, 6};
    int dist[] = {2, 3, 3};

    // cout << tour_nsquare(dist, petrol, 4) << endl;
    cout << tour_oone(dist, petrol, 3) << endl;
    return 0;
}