
#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;

// In this problem one approach is that we start from back and push strings between two // into the answer and if there is .. we increment a back variable so that we do not have to include the last back directories is that we have to go out of directerios back times and if . comes means we have to do nothing and if there is nothing between the two slashes we just take one of the slash

// int index = path.size() - 1;
// string ans = "";
// int back = 0;

// while (index >= 0)
// {
//     string temp = "";
// while (index >= 0 && path[index] != '/') ----- jab tak slash tak na pohoche temp me beech ka data
//     {

//         temp += path[index];
//         index--;
//     }

//     index--; ************** jaise hi ek / pe phonche to ab uske peeche se chalu karna hai to -- kardia

//     if (temp == "" || temp == ".") -- agar empty hai ya . hai to kuch nahi karna to bas continue
//         continue;

//     if (temp == "..") ---- agar .. hai to back variable ko badha dia
//         back++;
//     else if (back > 0)
//     {
//         back--;  ---------    agar back >0 hai to  ans me kuch na add karke back ko ghata dia --
//     }
//     else
//     {
//         ans += temp;  warna ans me /data jod dia -ulta - final me reverse kar denge
//         ans += "/";
//     }
// }
// reverse(ans.begin(), ans.end());
// if (ans == "")  - agar khali hai to / return karna hai
//     return "/";
// return ans;

// another stack aproach

string simplifyPath(string path)
{
    stack<string> s;
    string directory, result;

    path += '/'; //-- add at last to check data between two // if a slash is not present at last

    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] != '/') //--- if not / so add the data in between
            directory += path[i];
        else
        {
            if (directory.length() == 0 || directory == ".")
            {
                // if data is empty or . do nothing
            }
            else if (directory == "..")
            {
                if (!s.empty()) // if .. then pop the last string
                    s.pop();
            }
            else
                s.push(directory); // else push
            directory = "";
        }
    }

    if (s.size() == 0)
        return "/";

    while (!s.empty())
    {
        result = "/" + s.top() + result;
        s.pop();
    }

    return result;
}

int main()
{
    cout << simplifyPath("/home/../foo/./ayush/deepika/..");
}