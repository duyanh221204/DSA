#include<bits/stdc++.h>
using namespace std;
int n, k, a[20];
string s[20];
set<string> ss;
void tt(int x)
{
    for (int i = a[x - 1] + 1; i <= n - k + x; ++i)
    {
        a[x] = i;
        if (x == k)
        {
            string h;
            for (int j = 1; j <= k; ++j) h += s[a[j]];
            ss.insert(h);
        }
        else tt(x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    tt(1);
    for (string i : ss) cout << i << "\n";
}
