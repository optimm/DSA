#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)
{
    if (a.size() > b.size())
        return addBinary(b, a);

    int x = b.size() - a.size();
    string pd(x, '0');
    a = pd + a;
    char carry = '0';
    string res;
    for (int i = a.size(); i >= 0; i--)
    {
        if (a[i] == '1' && b[i] == '1')
        {
            if (carry == '1')
            {
                res.push_back('1');
            }
            else
            {
                res.push_back('0');
                carry = '1';
            }
        }
        else if (a[i] == '0' && b[i] == '0')
        {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        else if (a[i] != b[i])
        {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
    if (carry == '1')
        res.push_back(carry);

    reverse(res.begin(), res.end());

    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
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