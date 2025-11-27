#include <bits/stdc++.h>
using namespace std;
int n, m, q;
const int maxn = 1000;
int arr[maxn+1][maxn+1];
long long prefixsum[maxn+1][maxn+1];
void precomp()
{
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            prefixsum[x][y] = (long long) prefixsum[x-1][y] + prefixsum[x][y-1] - prefixsum[x-1][y-1] + arr[x][y];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        prefixsum[i][0] =0;
    for (int i = 1; i <= m; ++i)
        prefixsum[0][i] = 0;
    prefixsum[0][0] = 0;
    precomp();
    for (int i = 1; i <= q; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long ans = (long long) prefixsum[c][d] - prefixsum[a - 1][d] - prefixsum[c][b - 1] + prefixsum[a - 1][b - 1];
        cout << ans << endl;
    }
}
