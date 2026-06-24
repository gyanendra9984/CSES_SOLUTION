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
        ll n, x;
        cin >> n >> x;
        vector<ll> w(n);
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        vector<pair<ll, ll>> dp(1 << n, {INT_MAX, 0});
        dp[0] = {1, 0};
        for (int i = 1; i < (1 << n);i++){
            for (int j = 0; j < n;j++){
              if(i&&(1<<j)){
                int p=i^(1<<j);
                if(dp[p].second+w[j]<=x){
                    dp[i] = min(dp[i], {dp[p].first,dp[p].second + w[j]});
              }else{
                    dp[i] = min(dp[i], {dp[p].first + 1, w[j]});
              }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
}
int main(){
        solve();
    return 0; }