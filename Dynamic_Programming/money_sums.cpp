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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sort(a.begin(), a.end());
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n;i++){
        for(int j=sum;j>=1;j--){
            if(j>=a[i]&&dp[j-a[i]]){
                dp[j] = 1;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= sum;i++){
        if(dp[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
}
int main(){
        solve();
    return 0; }