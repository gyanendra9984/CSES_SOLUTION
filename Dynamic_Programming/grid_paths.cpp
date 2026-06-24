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
    int n;
    cin >> n;
  vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }}

  vector<vector<ll>> dp(n,vector<ll>(n,0));
    if(v[0][0]=='.')dp[0][0] = 1;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(v[i][j]=='.'){
                if(i>0){
                    dp[i][j]+=(dp[i-1][j])%mod;
                }
                if(j>0){
                    dp[i][j]+=(dp[i][j-1])%mod;
                    dp[i][j] %= mod;
                }
            }
        }
    }
    
        cout << dp[n - 1][n - 1] << endl;
}
int main()
{
    solve();
    return 0;
}