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
    map<int,int> mp;
    int x,ans=0,aa=0;
    for (int i = 0; i < n;i++){
        cin >> x;
        if(mp.find(x)==mp.end()){
            mp[x] = i+1;
            ans = max(ans, i + 1 - aa);
        }else{
            aa = max(aa, mp[x]);
            ans = max(ans,i+1 - aa);
            mp[x] = i+1;
        }
    }
    cout << ans;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }