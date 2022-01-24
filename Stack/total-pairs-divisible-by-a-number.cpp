// naive solution is n square
// another efficent solution is that when we reach a number we see issey pehle itne kitne elements the jinko add karke isme divisible banaya jaa sakta hai
// map maintain karlia or agar divisible hai number to 0 ki freq badha di or required jo hai vo hai number - current%number i.e itna add karke divisible ban jaega
// problem -link --https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/submissions/
//
//

// class Solution
// {
// public:
//     int numPairsDivisibleBy60(vector<int> &time)
//     {
//         int n = time.size();
//         map<int, int> mp;
//         int result = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (time[i] % 60 == 0)
//             {
//                 result += mp[0];
//                 mp[0]++;
//             }
//             else
//             {
//                 int y = 60 - time[i] % 60;
//                 result += mp[y];
//                 mp[time[i] % 60]++;
//             }
//         }
//         return result;
//     }
// };