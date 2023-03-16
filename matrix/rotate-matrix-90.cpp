#include <bits/stdc++.h>
#define ll long long
using namespace std;

void method1(vector<vector<ll>> &mat, int n, int m)
{
    // transpose and reverse each row -- rotate by 90 deg

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

// moving in circle
//(i,j)->(j,n-i-i)->(n-i-1,n-j-1)->(n-j-1,i)->(i,j)
void method2(vector<vector<ll>> &mat, int n, int m)
{
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            int temp = mat[n - 1 - j][i];
            mat[n - 1 - j][i] = mat[n - 1 - i][n - j - 1];
            mat[n - 1 - i][n - j - 1] = mat[j][n - 1 - i];
            mat[j][n - 1 - i] = mat[i][j];
            mat[i][j] = temp;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    method2(mat, n, m);
    // method1(mat, n, m);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}