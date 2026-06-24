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
    vector<int> a(n), b(m);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
          if(a[i-1]==b[j-1]){
              dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
          }else{
              dp[i][j] = max(dp[i][j-1], dp[i - 1][j]);
          }
        }
    }
    vector<int> ans;
    int i = n, j = m;
    while(i>=1 && j>=1){
      if(a[i-1]==b[j-1]){
          ans.push_back(a[i - 1]);
          i--;
          j--;
      }else{
         if(dp[i][j-1]>=dp[i-1][j]){
             j--;
         }else{
             i--;
         }
      }
    }
    cout << dp[n][m] << endl;
    for (int i = ans.size() - 1; i >= 0;i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    }
int main(){
        solve();
    return 0; }