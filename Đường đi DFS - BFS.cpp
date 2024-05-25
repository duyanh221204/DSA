#include<bits/stdc++.h>
using namespace std;
int k1[1002], k2[1002], p1[1002], p2[1002];
vector<vector<int>> g(1002);
void dfs(int x)
{
    k1[x] = 1;
    for (int& i : g[x])
    {
        if (!k1[i])
        {
            p1[i] = x;
            dfs(i);
        }
    }
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    k2[x] = 1;
    while (q.size())
    {
        int m = q.front();
        q.pop();
        for (int& i : g[m])
        {
            if (!k2[i])
            {
                k2[i] = 1;
                p2[i] = m;
                q.push(i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i)
    {
        if (!k1[i]) cout << "-1";
        else
        {
            stack<int> st;
            int x = i;
            while (x != 1)
            {
                st.push(x);
                x = p1[x];
            }
            cout << "1 ";
            while (st.size())
            {
                cout << st.top() << " ";
                st.pop();
            }
        }
        cout << "\n";
        for (int j = 1; j <= n; ++j) k2[j] = p2[j] = 0;
        bfs(i);
        if (!k2[1]) cout << "-1";
        else
        {
            stack<int> st;
            int x = 1;
            while (x != i)
            {
                st.push(x);
                x = p2[x];
            }
            cout << i << " ";
            while (st.size())
            {
                cout << st.top() << " ";
                st.pop();
            }
        }
        cout << "\n";
    }
}
