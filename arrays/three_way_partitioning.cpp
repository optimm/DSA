#include <bits/stdc++.h>
#define ll long long
using namespace std;
void threeWayPartition(vector<int> &arr, int a, int b)
{
    int n = arr.size();
    int j = 0;
    // sabse pehle less than a ko aage laado fir <=b wale uske baad
    // pehle <=a mat karna kyunki for ex 3 22 5 hai or a 22 hai to ishi order me reh jaega
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < a)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int i = j; i < n; i++)
    {
        if (arr[i] <= b)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    //  for (int i = 0; i < n; i++)
    // {
    //   cout<<arr[i]<<" ";
    // }
}
// another approach - sort it
// another two pointer
void threeway(vector<int> &v, int a, int b)
{
    int n = v.size(), i = 0;
    int start = 0, end = n - 1;
    while (i <= end)
    {
        if (v[i] < a)
        {
            swap(v[i], v[start]);
            i++;
            start++;
        }
        else if (v[i] > b)
        {
            swap(v[i], v[end]);
            end--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    return 0;
}