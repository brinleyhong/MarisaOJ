#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e2;
bool arr[maxn+1][maxn+1];
void cover(int x1, int y1, int x2, int y2)
{
    x1 = 100 - x1 + 1;
    x2 = 100 - x2 + 1;
//    y1 = 100 - y1 + 1;
//    y2 = 100 - y2 + 1;

    int start_x = min(x2, x1);
    int start_y = min(y1, y2);
    int end_x = max(x1, x2);
    int end_y = max(y1, y2);
    for (int i = start_x; i <= end_x; ++i)
    {
        for (int j = start_y; j <= end_y; ++j)
            arr[i][j] = true;
    }
//    cout << endl;
}
int main()
{
//    cover();
    cin >> n;
    for (int i = 1; i <= maxn; ++i)
    {
        for (int j = 1; j <= maxn; ++j)
            arr[i][j] = false;
    }
    for (int i = 1; i <= n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cover(x1, y1, x2,  y2);
    }
    int cnt = 0;
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 100; ++j)
        {
            if (arr[i][j] == true)
                ++cnt;
        }
//        cout << endl;
    }
    cout << cnt;
    return 0;
}
