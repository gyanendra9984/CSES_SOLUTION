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
// ll rec(int x,int n, vector<int> &dp, vector<int>& v)
// {
//     if (x == 0)
//         return 0;
//     if (x < 0)
//         return INT_MAX;
//     if (dp[x] != -1)
//         return dp[x];
//     ll ans = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         ans = min(ans,1+(rec(x - v[i],n, dp,v)));
//     }
//     return dp[x] = ans;
// }
void solve()
{
    int n,x;
    cin >> n>>x;
    vector<int> v(n);
    for (int i = 0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> dp(x + 1, INT_MAX);
    dp[0] = 0;  
    for(int i=1;i<=x;i++){
       for(int j=0;j<n;j++){
           if(i-v[j]>=0){
               dp[i]=min(dp[i],1+dp[i-v[j]]);
           }
       }
    }
    if(dp[x]==INT_MAX)
        cout << -1 << endl;
    else
    cout <<dp[x]<< endl;
}
int main()
{
    solve();
    return 0;
}