#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c(int n)
{
    int ans = 0;
    int p = 1;
    while (n > 0)
    {
        int m = n & 1;
        ans += m * p;
        p *= 10;
        n = n >> 1;
    }
    return ans;
}
/// method 2
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
int main()
{
    int n;
    cin >> n;
    cout << c(n);

    return 0;
}