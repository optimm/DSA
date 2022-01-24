#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;

///// This is the recursive itr approach , in this we did not pass small string into the function instead we passed the value of i from where we are starting to decode in our code
// for other solutions refer to stack

//     Recursive Approach
//         Time Complexity = O(N),
//              Space Complexity = O(N), considering the resursion stack

string decodeTheString(string s, int &itr)
{
    string res = "";
    while (itr < s.size() && s[itr] != ']')
    {
        if (isdigit(s[itr]))
        {
            int num = 0;
            while (itr < s.size() && isdigit(s[itr]))
            {
                num = num * 10 + (s[itr++] - '0');
            }
            // to escape the '['
            itr++;
            cerr << "call--" << itr << "\n";
            // store the return result and repeat it num times
            string temp = decodeTheString(s, itr);

            // to escape the ']'
            itr++;

            while (num--)
            {
                res += temp;
            }
        }
        else
        {
            res += s[itr++];
        }
    }

    return res;
}

string decodeString(string s)
{
    int itr = 0;
    return decodeTheString(s, itr);
}

int main()
{
    string s;
    cin >> s;
    cout << decodeString(s);
}