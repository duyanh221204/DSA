#include<bits/stdc++.h>
using namespace std;
string kt(string& s)
{
    stack<char> st;
    for (char& i : s)
    {
        if (i == '(' || i == '[') st.push(i);
        else if (i == ')')
        {
            if (st.size() && st.top() == '(') st.pop();
            else return "NO";
        }
        else if (i == ']')
        {
            if (st.size() && st.top() == '[') st.pop();
            else return "NO";
        }
    }
    if (!st.size()) return "YES";
    return "NO";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline (cin, s);
        cout << kt(s) << "\n";
    }
}
