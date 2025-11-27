#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn+1][maxn+1];
long long dp[maxn+1][maxn+1];
int n;
void precomp()
{
    dp[1][1] = a[1][1];
}
void solve()
{

    //dp[i][j-1], dp[i+1][j-1], dp[i-1][j-1]
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = (long long) max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[n][n];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    precomp();
    solve();
    return 0;
}
