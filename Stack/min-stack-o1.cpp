
// we have two approaches - if there are only positives as we reach another smaller number we push i-last_min to stack and update new min so as we pop and a negative number comes we can find again the previous min by min-that element
//********************************************************************************************************
//
/// in case of negatives also we use 2min-t and insted of checking for <=0 we chech for <=min and update min by 2*min-t as this will always be less than min so as we reach a number less than min we can find the next min again with 2*element - current min.

#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define repe(i, a, b) for (long long int i = a; i <= b; i++)
#define MOD 1048576
#define pb(a) push_back(a)
using namespace std;
stack<int> s;
int mi;
void stac(int arr[], int n)
{
    mi = arr[0];
    s.push(mi);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= mi)
        {
            s.push(arr[i] - mi);
            mi = arr[i];
        }
        else
        {
            s.push(arr[i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<ll> v;

    int n;
    cin >> n;
    int arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stac(arr, n);
    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
    return 0;
}