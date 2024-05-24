#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long d = 0;
    stack<pair<int, int>> st;
    while (n--)
    {
        int x;
        cin >> x;
        while (st.size() && x > st.top().first)
        {
            d += st.top().second;
            st.pop();
        }
        if (st.size())
        {
            if (x == st.top().first)
            {
                d += st.top().second++;
                if (st.size() > 1) ++d;
            }
            else
            {
                ++d;
                st.push({x, 1});
            }
        }
        else st.push({x, 1});
    }
    cout << d;
}
