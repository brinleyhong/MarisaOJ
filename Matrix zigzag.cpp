#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n, m;
int id[maxn+1][maxn+1];
bool check = false;
void solve()
{
    for (int s = 2; s <= n + m; ++s)
    {
        if (s % 2 == 0)
        {
            for (int i = min(n, s - 1); i >= 1; --i)
            {
                int j = s - i;
                if (j >= 1 && j <= m)
                    cout << id[i][j] << " ";
            }
        }
        else
        {
            for (int j = min(m, s - 1); j >= 1; --j)
            {
                int i = s - j;
                if (i >= 1 && i <= n)
                    cout << id[i][j] << " ";
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> id[i][j];
    }

    solve();
    return 0;
}
