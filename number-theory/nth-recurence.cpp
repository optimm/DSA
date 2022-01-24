#include <bits/stdc++.h>
#define ll long long
#define max 1000000007
using namespace std;

int magic[2][2] = {{0, 1}, {1, 1}};

int nth(int a[][2], int n)
{
    int i[2][2] = {{1, 0}, {0, 1}};
    int res[2][2];
    while (n != 0)
    {
        if (n % 2 == 0)
        {

            for (int l = 0; l < 2; l++)
            {
                for (int j = 0; j < 2; j++)
                {
                    res[l][j] = 0;
                    for (int k = 0; k < 2; k++)
                    {
                        res[l][j] += magic[l][k] * magic[k][j];
                    }
                }
            }
            for (int l = 0; l < 2; l++)
            {
                for (int j = 0; j < 2; j++)
                {
                    magic[l][j] = res[l][j];
                    // cout << magic[l][j] << " ";
                }
                // cout << "\n";
            }
            n = n / 2;
            // cout << n << "\n";
        }
        else
        {
            for (int l = 0; l < 2; l++)
            {
                for (int j = 0; j < 2; j++)
                {
                    res[l][j] = 0;
                    for (int k = 0; k < 2; k++)
                    {
                        res[l][j] += magic[l][k] * i[k][j];
                    }
                }
            }

            for (int l = 0; l < 2; l++)
            {
                for (int j = 0; j < 2; j++)
                {
                    i[l][j] = res[l][j];
                    // cout << i[l][j] << " ";
                }
                // cout << "\n";
            }
            n--;
            // cout << n << "\n";
        }
    }

    int result = a[0][0] * i[0][0] + a[0][1] * i[1][0];
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        cin >> x >> y >> n;
        if (n == 0)
        {
            cout << x << "\n";
            continue;
        }
        if (n == 1)
        {
            cout << y << "\n";
            continue;
        }

        int a[1][2] = {x, y};
        cout << "\n"
             << nth(a, n) << "\n";
    }
}