#include <bits/stdc++.h>
#define ll long long

using namespace std;

// In this problem the approach is simple if element occured is less than st.top then we check in each step that let x elements be in stack to n-k-x are present ahead ith position so that the requirement of deleting k elements is fulllfilled

string removeKdigits(string s, int k)
{
    string z = "0";
    if (s == "0" || k == s.size())
        return z;

    stack<char> st;
    st.push(s[0]);
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        char x = s[i];
        // debug(x)
        if (s[i] >= st.top())
        {
            st.push(s[i]);
            continue;
        }
        // debug(st.top())
        // pop while the number of elements in (the stack + in the remaining string) are greater
        // than desired length, and the current number is smaller than stack top
        while (!st.empty() && s[i] < st.top() && i < k + st.size())
        {

            st.pop();
        }
        st.push(s[i]);
        // debug(st.top())
    }
    // debug(st.top())

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    res = res.substr(0, n - k);
    // leave only the first desired numbers
    // debug(res)
    int i = 0;
    for (i; i < res.size(); i++)
    {
        if (res[i] != '0')
            break;
    }
    // trim zeroes in the beginning
    if (i == res.size())
    {
        return z;
    }
    return res.substr(i);
}
int main()
{
    cout << removeKdigits("10", 2);
    return 0;
}