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
 
void solve(){
    int n;cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    // vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
    // for (int i = 1; i <= n;i++){
    //     dp[i][i][0] = a[i-1];
    // }
    //     for (int i = 1; i < n; i++)
    //     {
    //         for (int j = i+1; j <= n; j++)
    //         {
    //             dp[j-i][j][0] = max(dp[j-i][j - 1][1] + a[j - 1], dp[j-i + 1][j][1] + a[j-i-1]);
    //             dp[j-i][j][1] = min(dp[j-i][j - 1][0], dp[j-i + 1][j][0]);
    //         }
    //     }

    vector<vector<ll>> dp(n + 1,vector<ll>(2,0));
    vector<vector<ll>> dp1(n + 1, vector<ll>(2, 0));

    for (int i = 1; i <= n; i++)
    {
             dp[i][0] = a[i-1];
    }
         for (int i = 1; i < n; i++)
         {
            for (int j = i+1; j <= n; j++)
            {
                dp1[j][0] = max(dp[j - 1][1] + a[j - 1], dp[j][1] + a[j-i-1]);
                 dp1[j][1] = min(dp[j - 1][0], dp[j][0]);
             }
             dp = dp1;
         }

    cout << dp[n][0] << endl;
    }
int main(){
        solve();
    return 0; }