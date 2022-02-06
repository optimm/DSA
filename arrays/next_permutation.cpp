#include <bits/stdc++.h>
#define ll long long
using namespace std;
void print(vector<int> &v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << "\n";
}
void nextPermutation(vector<int> &a)
{
    int n = a.size();
    bool flag = true;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                flag = false;
            }
        }
        if(flag){
            reverse(a.begin(),a.end());
            return ;
        }
    int x = n - 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            cout << a[i] << " \n";
            for (int j = i; j < n; j++)
            {
                if (a[j] <= a[i-1])
                {
                    x = j - 1;
                    break;
                }
            }
            cout<<x<<"\n";
            swap(a[i-1], a[x]);
            print(a);
            reverse(a.begin() + i, a.end());
            break;
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
    nextPermutation(a);
    print(a);
    return 0;
}