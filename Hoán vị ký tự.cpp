#include<bits/stdc++.h>
using namespace std;
string s;
int n, d;
void tt()
{
    int x = n - 2, y = n - 1, l, r;
    while (x >= 0 && s[x] > s[x + 1]) --x;
    if (x < 0)
    {
        d = 1;
        return;
    }
    while (y >= 0 && s[x] > s[y]) --y;
    if (y < 0)
    {
        d = 1;
        return;
    }
    swap(s[x], s[y]);
    l = x + 1, r = n - 1;
    while (l < r) swap(s[l++], s[r--]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c1, c2;
    cin >> c1 >> c2;
    if (c1 > c2) swap(c1, c2);
    n = c2 - c1 + 1;
    for (char i = c1; i <= c2; ++i) s += i;
    while (!d)
    {
        cout << s << "\n";
        tt();
    }
}
