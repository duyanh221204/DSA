#include<bits/stdc++.h>
using namespace std;
int k[100002], p[100002];
int tim(int x)
{
    while (x != p[x]) x = p[x];
    return x;
}
void hop(int x, int y)
{
    x = tim(x), y = tim(y);
    if (x != y)
    {
        if (k[x] < k[y]) swap(x, y);
        p[y] = x;
        k[x] += k[y];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, d, res = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        k[i] = 1;
        p[i] = i;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        hop(x, y);
    }
    d = tim(1);
    for (int i = 2; i <= n; ++i)
    {
        int z = tim(i);
        if (d != z) res = max(k[z], res);
    }
    cout << res + k[d];
}
