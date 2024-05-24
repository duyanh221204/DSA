#include<bits/stdc++.h>
using namespace std;
int par[100002];
int tim(int x)
{
    while (x != par[x]) x = par[x];
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d = 0;
        cin >> n >> m;
        pair<int, int> p[m];
        for (auto& i : p) cin >> i.first >> i.second;
        for (int i = 1; i <= n; ++i) par[i] = i;
        for (auto& i : p)
        {
            int x = tim(i.first), y = tim(i.second);
            if (x == y)
            {
                d = 1;
                cout << "YES\n";
                break;
            }
            par[x] = y;
        }
        if (!d) cout << "NO\n";
    }
}
