#include<bits/stdc++.h>
using namespace std;
int n, a[20];
string s[20];
set<string> ss;
void tt(int x)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[x] = i;
        if (x == n)
        {
            string k;
            for (int j = 1; j <= n; ++j)
            {
                if (a[j]) k += s[j];
            }
            ss.insert(k);
        }
        else tt(x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    tt(1);
    for (string i : ss) cout << i << "\n";
}
