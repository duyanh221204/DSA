#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n + 2], b[n + 2], f[n + 2][2] = {};
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        f[1][1] = b[1];
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] == a[i - 1]) f[i][0] = f[i - 1][1];
            else f[i][0] = min(f[i - 1][0], f[i - 1][1]);
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + b[i];
            //cout << f[i][0] << " " << f[i][1] << "\n";
        }
        cout << min(f[n][0], f[n][1]) << "\n";
    }
}
