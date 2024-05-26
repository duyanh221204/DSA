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
        int n, m, x, y, s = -2e9, d = 2e9;
        cin >> n >> m;
        int a[n + 2][m + 2], b[n + 2][m + 2] = {};
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 1) b[i][j] = b[i - 1][j] + a[i][j];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            int l[m + 2], r[m + 2];
            stack<int> st;
            for (int j = 1; j <= m; ++j)
            {
                while (st.size() && b[i][j] <= b[i][st.top()]) st.pop();
                if (st.size()) l[j] = st.top();
                else l[j] = 0;
                st.push(j);
            }
            st = {};
            for (int j = m; j >= 1; --j)
            {
                while (st.size() && b[i][j] <= b[i][st.top()]) st.pop();
                if (st.size()) r[j] = st.top();
                else r[j] = m + 1; 
                st.push(j);
            }
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] == 1)
                {
                    if (b[i][j] * (r[j] - l[j] - 1) >= s)
                    {
                        s = b[i][j] * (r[j] - l[j] - 1);
                        int cd = max(b[i][j], r[j] - l[j] - 1), cr = min(b[i][j], r[j] - l[j] - 1);
                        if (cd - cr < d)
                        {
                            d = cd - cr;
                            x = cr;
                            y = cd;
                        }
                    }
                }
            }
        }
        cout << x << " " << y << "\n";
    }
}
