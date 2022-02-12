#include <bits/stdc++.h>
#define ll long long
using namespace std;
// pick dont pick --method - for each element make two calls - one with chosen and one without chosen
void print_subseq(string input, string output)
{
    cerr << input << "\n";
    if (input.size() == 0)
    {
        cout << output << " ";
        return;
    }
    print_subseq(input.substr(1), output + input[0]);
    print_subseq(input.substr(1), output);
}
int main()
{
    string s;
    cin >> s;
    print_subseq(s, "");

    return 0;
}