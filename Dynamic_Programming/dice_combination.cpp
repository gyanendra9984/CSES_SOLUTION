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
// int rec(int n, vector<int>& dp)
// {
//     if (n == 0)
//         return 1;
//     if (n < 0)
//         return 0;
//     if (dp[n] != -1)
//         return dp[n];
//     ll ans=0;
//     for(int i=1;i<=6;i++){
//         ans+=(rec(n-i,dp))%mod;
//     }
//     return dp[n]=(ans)%mod;
// }
void solve(){
    int n;
    cin >> n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for (int j = 1;j<=6;j++){
          if(i-j>=0){
            dp[i]=(dp[i]+dp[i-j])%mod;
          }
        }
    }
    cout<<dp[n]<<endl;
    }
int main(){
        solve();
    return 0; }