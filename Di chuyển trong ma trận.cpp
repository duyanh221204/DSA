#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 2][n + 2];
    long long dp[n + 2][n + 2] = {};
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1) dp[i][j] = dp[i][j - 1];
            else if (j == 1) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] += a[i][j];
        }
    }
    cout << dp[n][m];
}
