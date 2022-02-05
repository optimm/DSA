#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, r, c;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> r >> c;
        int f1 = 0, f2 = 0;
        char arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'B')
                    f1 = 1;
                if (arr[r - 1][j] == 'B' || arr[i][c - 1] == 'B')
                    f2 = 1;
            }
        }
        if (f1 == 0)
            cout << "-1\n";
        else
        {
            if (arr[r - 1][c - 1] == 'B')
                cout << "0\n";
            else if (f2 == 1)
                cout << "1\n";
            else
                cout << "2\n";
        }
        f1 = 0, f2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cerr << arr[i][j];
            }
            cerr << "\n";
        }
    }
    return 0;
}