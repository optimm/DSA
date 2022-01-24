
// a good question and in this what we did - agar + ya minus aarahe hai to to unko result me jodte jao waise ke waise and agar - aaraha hai to -x ko joddo or last number ko update kardo ussey jisko push kia hai  and fir agar * / aaya to evaluate karke last ko fir update kardo

// for example lelet hai 2-3+4/2

// curr last sign  signss[i] result curr last sign
// 0     0     +      .       0      0    0   +
// 2     0     +      .       0      2    0   +
// 2     0     +      -       0      0    2   -
// 3     2     -      .       0      3    2   -
// 3     2     -      +       2      0   -3   +
// 4    -3     +      .       2      4   -3   +
// 4    -3     +      /      -1      0    4   /
// 2     4     /      .      -1      0    2   n-1

//- 1 + 2 = 1
#include <bits/stdc++.h>

using namespace std;

int calculate(string s)
{

    int n = s.length();
    if (n == 0)
        return 0;

    int last = 0, curr = 0, ans = 0;
    char op = '+';

    for (int i = 0; i < n; i++)
    {
        char x = s[i];
        if (isdigit(x))
        {
            curr = curr * 10 + s[i] - '0';
        }
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || i == n - 1)
        {
            if (op == '+' || op == '-')
            {
                ans += last;
                last = op == '+' ? curr : -curr;
            }
            if (op == '/' || op == '*')
            {
                last = op == '/' ? last / curr : last * curr;
            }
            op = s[i];
            curr = 0;
        }
    }
    return ans + last;
}
int main()
{
    cout << calculate("2-3+4/2");
    return 0;
}