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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
   
    for (int i = 1; i <= a;i++){
        for (int j = 1; j <= b;j++){
           if(i==1){
            dp[i][j] = j - 1;
           }else if(j==1){
               dp[i][j] = i - 1;
        }else if(i==j){
            dp[i][j] = 0;
            }else{
          for(int k=1;k<i;k++){
              dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
          }
          for (int k = 1; k < j; k++)
          {
              dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
          }
        }
    }
    }
    cout << dp[a][b] << endl;
}
int main()
{
    solve();
    return 0;
}