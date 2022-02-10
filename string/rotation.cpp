// check if a string is a roatation of other
#include <bits/stdc++.h>
#define ll long long
using namespace std;
//// complexity o(n1+n2)--- another kmp based approach also there
bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    s1 = s1 + s1;
    if (s1.find(s2) != string::npos)
        return true;
    return false;
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