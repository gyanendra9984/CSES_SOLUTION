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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    if(v[0]==0){
        for (int i = 1; i <= m;i++){
            dp[1][i] = 1;
        }
    }else{
        dp[1][v[0]] = 1;
    }
    for (int i = 2; i <= n;i++){
        if(v[i-1]==0){
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i - 1][j])%1000000007;
                if(j<m){
                    dp[i][j] = ( dp[i][j]+dp[i - 1][j + 1])%1000000007;
                }
                if(j>1){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1])%1000000007;
                }
            }
           
        }else{
            dp[i][v[i-1]] = dp[i - 1][v[i-1]]%1000000007;
            if(v[i-1]<m){
                dp[i][v[i-1]] = (dp[i][v[i-1]] + dp[i - 1][v[i-1] + 1])%1000000007;
            }
            if(v[i-1]>1){
                dp[i][v[i-1]] = (dp[i][v[i-1]] + dp[i - 1][v[i-1] - 1])%1000000007;
            }
        }
       
    }
    ll ans = 0;
    for (int i = 1; i <= m;i++){
        ans = (ans + dp[n][i])%1000000007;
    }
    cout << ans << endl;
}
int main(){
        solve();
    return 0; }