#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
/// core concept was to find ba pairs and for each ba pair i.e a b before a we had to perform one deletion
int minimumDeletions(string s)
{
    int count = 0;
    stack<char> st;
    char c = ' ';
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        if (!st.empty() && (st.top() == 'b' && c == 'a'))
        {
            st.pop();
            count++;
        }
        else if (c == 'b')
        {
            st.push(c);
            // count++;
        }
        int x = st.size();
        // debug(x)
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    string s;
    cin >> s;
    cout << minimumDeletions(s);
    return 0;
}