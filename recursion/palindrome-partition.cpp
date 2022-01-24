#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
// 
bool ispal(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void recur(string s, vector<vector<string>> &res, vector<string> temp)
{
    if (s.size() == 0)
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string first = s.substr(0, i + 1);
        if (ispal(first))
        {
            temp.push_back(first);
            recur(s.substr(i + 1), res, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> temp;
    recur(s, res, temp);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<vector<string>> v = partition(s);
    // for (ll i = 0; i < v.size(); i++)
    // {
    //     debug(v[i]);
    // }

    return 0;
}