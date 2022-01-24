
// we do operation and then push the result to stack

// int evalRPN(vector<string> &s)
// {

//     stack<int> st;
//     int n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] != "+" && s[i] != "*" && s[i] != "/" && s[i] != "-")
//         {
//             int x = stoi(s[i]);
//             st.push(x);
//         }
//         else
//         {
//             int n2 = st.top();
//             st.pop();
//             int n1 = st.top();
//             st.pop();

//             if (s[i] == "+")
//                 st.push(n1 + n2);
//             else if (s[i] == "*")
//                 st.push(n1 * n2);
//             else if (s[i] == "-")
//                 st.push(n1 - n2);
//             else if (s[i] == "/")
//                 st.push(n1 / n2);
//         }
//     }
//     return st.top();
// }