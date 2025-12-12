#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
int n, q, a[maxn+5];
ll seg[maxn*4+5];
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id] = (ll) seg[id*2] + seg[id*2+1];
}
void update(int id, int l, int r, int k, int val)
{
    if (l == r)
    {
        seg[id] = val;
        return;
    }
    int mid = (l+r)/2;
    if (k <= mid) update(id*2, l, mid, k, val);
    else update(id*2+1, mid+1, r, k, val);
    seg[id] = (ll) seg[id*2] + seg[id*2+1];
}
ll get(int id, int l, int r, int u, int v)
{
    // l r u l r v l r
    if (r < u || v < l) return 0LL;
    if (u<=l && r<=v) return seg[id];
    int mid = (l+r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i<=n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int i, x; cin >> i >> x;
            update(1, 1, n, i, x);
        }
        else
        {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
