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
bool sortby(const vector<ll> &a, const vector<ll> &b)
{
    return (a[1] < b[1]);
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    vector<ll> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin(), v.end(), sortby);
    for (int i = 0; i < n; i++)
    {
        v2[i] = v[i][1];
    }
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = v[i][2];
        }
        else
        {
            int it = lower_bound(v2.begin(), v2.end(), v[i][0]) - v2.begin();
            it--;
            if (it >= 0)
            {
                dp[i] = max(dp[i - 1], v[i][2] + dp[it]);
            }else{
                dp[i] = max(dp[i - 1], v[i][2]);
            }
        }
    }
    cout << dp[n - 1] << endl;
}
int main()
{
    solve();
    return 0;
}