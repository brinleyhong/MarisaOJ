#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1e2;
int arr[maxn+1][maxn+1];
int number = 0;
bool check = false;
int maxnum;
void solve(int layer) {
    //->
    for (int i = 1 + layer; i <= m - layer; ++i) {
        if (check == true)
            break;
        number++;
        arr[layer+1][i] = number;
        if (number >= maxnum)
        {
            check = true;
            break;
        }
    }
    //down
    for (int i = 2 + layer; i <= n - layer; ++i)
    {
        if (check == true)
            break;
        number++;
        arr[i][m - layer] = number;
        if (number >= maxnum)
        {
            check = true;
            break;
        }
    }
    // <-
    for (int i = m - layer - 1; i >= 1 + layer; --i)
    {
        if (check == true)
            break;
        number++;
        arr[n - layer][i] = number;
        if (number >= maxnum)
        {
            check = true;
            break;
        }
    }
    //up
    for (int i = n - layer - 1; i > layer + 1; --i)
    {
        if (check == true)
            break;
        number++;
        arr[i][layer+1] = number;
        if (number >= maxnum)
        {
            check = true;
            break;
        }
    }
}
int main()
{
    cin >> n >> m;
    maxnum = n*m;
    for (int layer = 0; layer <= max(m, n); ++layer)
    {
        if (check == true)
            break;
        solve(layer);
    }
    for (int i = 1;i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
