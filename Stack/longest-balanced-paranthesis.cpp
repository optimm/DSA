#include <bits/stdc++.h>
using namespace std;
// brute force is to check every non empty substring and check if it is balance dor not
// Time complexity: O(n^3). Generating every possible substring from a string of length nn requires O(n^2Checking validity of a string of length nn requires O(n)O

// Space complexity: O(n). A stack of depth nn will be required for the longest substring.

// kind of tricky problem - but easy - we need to store a start index and then push and pop and make answer with use of that prev value
// for ex we push -1 first so like () comes so ans equals 1- -1 = 2 and then say ) comes and stack is empty so we push this as new prev 2

// class Solution
// {
// public:
//     int longestValidParentheses(string s)
//     {
//         int result = 0;
//         stack<int> st;
//         st.push(-1);
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '(')
//             {
//                 st.push(i);
//             }
//             else
//             {
//                 if (!st.empty())
//                 {
//                     st.pop();
//                 }

//                 if (!st.empty())
//                 {
//                     result = max(result, i - st.top());
//                 }

//                 else
//                 {
//                     st.push(i); - a new start *****************
//                 }
//             }
//         }
//         return result;
//     }
// };

// another approach without any extra space ---
// In this approach, we make use of two counters leftleft and rightright. First, we start traversing the string from the left towards the right and for every‘(’encountered, we increment the leftleft counter and for every ‘)’ encountered, we increment the rightright counter. Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string and keep track of maximum length substring found so far. If rightright becomes greater than leftleft we reset leftleft and rightright to 00.

// public
// class Solution
// {
// public
//     int longestValidParentheses(String s)
//     {
// int main()
// {
//     string s;
//     int left = 0, right = 0, maxlength = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         // if (s.charAt(i) == '(')
//         {
//             left++;
//         }
//         // else
//         {
//             right++;
//         }
//         if (left == right)
//         {
//             maxlength = max(maxlength, 2 * right);
//         }
//         else if (right >= left)
//         {
//             left = right = 0;
//         }
//     }
//     left = right = 0;
//     for (int i = s.length() - 1; i >= 0; i--)
//     {
//         // if (s.charAt(i) == '(')
//         {
//             left++;
//         }
//         // else
//         {
//             right++;
//         }
//         if (left == right)
//         {
//             maxlength = max(maxlength, 2 * left);
//         }
//         else if (left >= right)
//         {
//             left = right = 0;
//         }
//     }
//     return maxlength;
// }
//     }
// }

/// there is also a dp implementation
// prev prev jaake dekh rahe hai ki udhar ( ye hai ki nahi agar hai to dp[i-2] where i is the position jahan ( hai wahan se update karenge

int main()
{
    string s;
    cin >> s;
    int result = 0;
    int n = s.size();
    int dp[30001] = {0};

    for (int i = 1; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                cout << dp[i - dp[i - 1] - 2] << endl;
            }
            result = max(dp[i], result);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << result;
}