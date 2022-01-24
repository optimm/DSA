#include <bits/stdc++.h>
using namespace std;
/// proof for this working
// let array 8 8 7 6 6 6
// pehle 8 8 se c 2 hogaya fir 7 pe 1 fir 6 pe 0 and final ans 6 hoagay now we have to prove that ye  8 8 7 inme se koi majority nahi hoga , -- simple agar inme se koi n/2 se zada hota to count n/2 se zada hota and then wapis 0 na ho paata
int majority(vector<int> v)
{
    int res = 0, count = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[res])
            count++;
        else
            count--;

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    // sometimes we may have to check that the final result is a majority or not
    // so for that just iterate through all elemnts and check if res element occurs more than n/2
    return res; // or -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    return 0;
}