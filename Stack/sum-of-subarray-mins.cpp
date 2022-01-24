#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;

/// There can be two approaches one  is the right left method i.e let till b on right and a elements on left arr[i] is min than in subarrays arr[i] is min are a+b +a*b;

// another is the running solution like histogram in this we remove the contribution of the previous element as a new minimum is acquired.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {3, 1, 2, 4, 0};

    // cout << sumSubarrayMins(arr);
    return 0;
}

///// This is monotonic stack approach do not use at first -- isme subtract isliye kar rahe ki lets say ki jo element hai vo chota hai to uspe end hone walon me prev ka hat jaana chahiye par maanlo bada hai lets say 3 1 2 4 me 4 aaya to vo bada hai to isme peeche wale 1 ka contri hona chahiye hi kyonki ye to bada hai iski min nahi le sakte

// int sumSubarrayMins(vector<int> &arr)
// {

//     stack<int> s;

//     s.push(-1);

//     int minsum = 0;

//     int sum = 0;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         // debug(i)
//         while (s.top() != -1 && arr[i] < arr[s.top()])
//         {
//             int idx = s.top();
//             //  debug(idx)
//             s.pop();
//             sum -= arr[idx] * (idx - s.top()); // removing contribution of old minima
//             // debug(sum)
//         }
//         sum += (i - s.top()) * arr[i]; // adding contribution of new element
//                                        // debug(sum)

//         s.push(i);

//         minsum = (minsum + sum) % 1000000007;
//         // debug(minsum)
//     }

//     return minsum;
// }