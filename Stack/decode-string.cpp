#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
//////// Recurive approach////////
// string decode(string s)
// {
//     string res = "";
//     int n = s.size();
//     int i = 0;

//     while (i < n)
//     {
//         if (isdigit(s[i]))
//         {
//             int j = i + 1;

//             while (j < s.size() && s[j] != '[')
//                 j++;

//             int rep = stoi(s.substr(i, j - i)), open = 1;

//             i = ++j;

//             while (open)
//             {
//                 if (s[j] == '[')
//                     ++open;
//                 else if (s[j] == ']')
//                     --open;
//                 j++;
//             }

//             string reps = decode(s.substr(i, j - i - 1));

//             while (rep--)
//                 res += reps;
//             i = j;
//         }
//         else
//         {
//             res += s[i++];
//         }
//     }

//     return res;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // cout << decode(s);
    }
    return 0;
}
// Simple approach is to find bracket closing one and replace it with its decoding
// string repeat(string str, int times)
// {
//     string result = "";
//     for (int i = 0; i < times; i++)
//         result += str;
//     return result;
// }
// string decodeString(string s)
// {
//     int i = 0;
//     while (i < s.size())
//     {
//         if (s[i] != ']')
//         {
//             i++;
//             continue;
//         }
//         // The string that needs to get repeated after the first parenthesis '['
//         int j = i;
//         while (s[j] != '[')
//             j--;
//         // The letters that we will be repeating
//         string repeatLetters = s.substr(j + 1, i - j - 1);

//         int k = j;
//         j--;
//         // checking the number before opening the parenthesis so we can get a count that how many times we need to repeat the strin
//         while ((j > 0) && (isdigit(s[j])))
//             j--;
//         debug(j)
//             debug(k)
//             // Corner case : When we r at the start of our string
//             if (j != 0)
//                 j++;
//         // Find the number of times the letter should be repeated
//         int repeatTimes = stoi(s.substr(j, k - j));
//         // replace the encoded part of string with decoded part
//         s.replace(j, i - j + 1, repeat(repeatLetters, repeatTimes));
//         // Putting i in the right place of our string
//         i = j + repeatLetters.size() * repeatTimes;
//         debug(repeatTimes)
//             debug(i)
//     }
//     return s;
// }

////// stack based approach

// In this approach if s[i] is not a closing bracket we push to stack as closing arrives we pop till top is opening and then add the chars in between to a string and then pop again till top is digit to find the times we have to repeat the string wqe have made previously then we make that string and push it back to the stack;

// Can aslo do using two stack one for string other for number;

//     Using 1 stack
//         Time Complexity = O(N),
//              Space Complexity = O(N)

//                  class Solution
// {
// public:
string decodeString(string s)
{
    stack<char> st; // char stack
    for (int itr = 0; itr < s.size(); itr++)
    {
        if (s[itr] == ']')
        {
            string str = "";
            while (st.top() != '[')
            {
                str = st.top() + str;
                st.pop();
            }
            st.pop();

            string times = "";
            while (!st.empty() && isdigit(st.top()))
            {
                times = st.top() + times;
                st.pop();
            }

            int count = stoi(times);

            while (count--)
            {
                for (int jtr = 0; jtr < str.size(); jtr++)
                {
                    st.push(str[jtr]);
                }
            }
        }
        else
        {
            st.push(s[itr]);
        }
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

/// Another proper recursive
