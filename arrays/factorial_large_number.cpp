#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> factorial(int N)
{
    vector<int> fac = {1};
    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        for (int j = 0; j < fac.size(); j++)
        {
            int z = fac[j] * i + carry;
            fac[j] = z % 10;
            carry = z / 10;
        }
        while (carry)
        {
            fac.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(fac.begin(), fac.end());
    return (fac);
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