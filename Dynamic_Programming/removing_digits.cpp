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
#define mod 1000000007

void solve()
{
    int x;
    cin >> x;

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    int xx = 0;
    for (int i = 1; i <= x; i++)
    {
        xx = i;
        while (xx)
        {
            int d = xx % 10;
            if (d > 0 && i - d >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
            xx = xx / 10;
        }
    }

    cout << dp[x] << endl;
}
int main()
{
    solve();
    return 0;
}