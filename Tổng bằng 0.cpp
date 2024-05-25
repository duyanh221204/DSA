#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unordered_map<long long, int> mp;
    long long d = 0, s = 0;
    while (n--)
    {
        long long x;
        cin >> x;
        s += x;
        if (s == 0) ++d;
        d += mp[s];
        ++mp[s];
    }
    cout << d;
}
