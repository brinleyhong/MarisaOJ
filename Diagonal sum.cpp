#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn+1][maxn+1];
int n,m, x, y;
int solve1()
{
    int dif = min(x,y);
    int x1 = x - dif + 1 ;
    int y1 = y -  dif + 1;
    int ans = 0;
    while (x1 <= n && y1 <= m)
    {
        ans += a[x1][y1];
        ++x1;
        ++y1;
    }
    return ans;
}
int solve2()
{
    int ans = 0;
    int dif = min(m - y, x - 1);
    int x1 = x - dif;
    int y1 = y + dif;
    while (x1 <= n && y1 >= 1)
    {
        ans += a[x1][y1];
//        cout << x1 << " " << y1 << endl;
        ++x1;
        --y1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j<=m; ++j)
            cin >> a[i][j];
    }
    int ans = solve1() + solve2() - a[x][y];
    cout << ans;
    return 0;
}
