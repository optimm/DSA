// void sort()
// {
//     if (s.empty())
//         return;
//     int temp = s.top();
//     s.pop();
//     sort();
//     if (s.empty())
//     {
//         s.push(temp);
//         return;
//     }
//     if (s.top() > temp)
//     {
//         int t = s.top();
//         s.pop();
//         s.push(temp);
//         sort();
//         temp = t;
//     }
//     s.push(temp);
//     return;
// }