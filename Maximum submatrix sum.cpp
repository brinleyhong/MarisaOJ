#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 500;
int arr[maxn+1][maxn+1];
long long prefixsum[maxn+1][maxn+1];
long long sum[maxn+1];
long long ans = -1000000000000;
void precomp()
{
    for (int i = 1; i <= n; ++i)
    {
        prefixsum[i][0] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        prefixsum[0][i] = 0;
    }
    prefixsum[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            prefixsum[i][j] =  (long long) prefixsum[i-1][j] + prefixsum[i][j-1] - prefixsum[i-1][j-1] + arr[i][j];
        }
    }
}
void solve()
{
    for (int top = 1; top <= n; ++top)
    {
        for (int bottom = top; bottom <= n; ++bottom)
        {
            for (int j = 1; j <= m; ++j)
            {
                int a = top;
                int b = j;
                int c = bottom;
                int d = j;
                sum[j] = (long long) prefixsum[c][d] - prefixsum[a - 1][d] - prefixsum[c][b - 1] + prefixsum[a - 1][b - 1];

            }
            long long cur = 0;
            for (int j = 1; j <= m; ++j)
            {
                cur = max(sum[j], cur + sum[j]);
                ans = max(ans, cur);
            }
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    precomp();
    solve();


    return 0;
}
