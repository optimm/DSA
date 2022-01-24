#include <bits/stdc++.h>
using namespace std;

////// This is kind of a tricky approach in this we just push charcters to queue and at front we keep the first non repeating char like  in aqizqazpn first we push aqizq and keep on adding a to ans as its front but then another a comes so we pop the front and then q but q has also 2 in map so pop then i comes at front and then we push z p n in queue and add i to ans for them;

string FirstNonRepeating(string s)
{
    int n = s.size();
    string ans = "";

    map<char, int> mp;
    queue<char> q;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        q.push(s[i]);

        while (!q.empty())
        {
            char x = q.front();
            if (mp[x] > 1)
                q.pop();
            else
            {
                ans += x;
                break;
            }
        }
        if (q.empty())
            ans += "#";
    }
    return ans;
}
int main()
{
    cout << FirstNonRepeating("aqizqazpn");
}