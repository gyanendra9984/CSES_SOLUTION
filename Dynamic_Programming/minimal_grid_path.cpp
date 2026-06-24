//           //XXXXXX\\          ||\\      //||
//          ||        \\         || \\    // ||
//          ||        ||         ||  \\  //  ||
//          ||                   ||   \\//   ||
//          ||   //XXX\\         ||          ||
//          ||   ||   ||   __    ||          ||   __
//          \\XXX//   ||  |__|   ||          ||  |__|
//  ||XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string ans = "";
    ans.push_back(v[0][0]);
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    dp[0][0] = 1;
    int p1, q1;
    for (int i = 0; i < n-1; i++)
    {
        char mn = 'Z';
        for (int j = 0; j <= i; j++)
        {
            p1 = i-j, q1 =j;
            if (dp[p1][q1]==1 && p1 < (n - 1) && q1 < n)
            {
                mn = min(mn, v[p1 + 1][q1]);
            }
            if (dp[p1][q1] == 1 && q1 < (n - 1) && p1 < n)
            {
                mn = min(mn, v[p1][q1 + 1]);
            }
        }

        for (int j = 0; j <= i; j++)
        {
            p1 = i - j, q1 = j;
            if (p1 < (n - 1) && q1 < n && v[p1 + 1][q1] == mn)
            {
                dp[p1 + 1][q1] = 1;
            }
            if (q1 < (n - 1) && p1 < n && v[p1][q1 + 1] == mn)
            {
                dp[p1][q1+1] = 1;
            }
        }
        ans += mn;
    }
    for (int j = n-1; j >0; j--)
    {
        char mn = 'Z';
        for (int i = 0; i<=j; i++)
        {
            int p1 = i, q1 = j-i;
            if (dp[p1][q1] == 1 && p1 < (n - 1) && q1 < n)
            {
                mn = min(mn, v[p1 + 1][q1]);
            }
            if (dp[p1][q1] == 1 && q1 < (n - 1) && p1 < n)
            {
                mn = min(mn, v[p1][q1 + 1]);
            }
        }
        for (int i = 0; i <= j; i++)
        {
            int p1 = i, q1 = j - i;
            if (p1 < (n - 1) && q1 < n && v[p1 + 1][q1] == mn)
            {
                mn = min(mn, v[p1 + 1][q1]);
            }
            if (q1 < (n - 1) && p1 < n && v[p1][q1 + 1] == mn)
            {
                mn = min(mn, v[p1][q1 + 1]);
            }
        }
        ans += mn;
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}