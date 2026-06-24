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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0,mx=INT_MIN;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        ans += a[i];
        mx = max(mx, a[i]);
    }
    if(ans-mx>=mx){
        cout <<ans << endl;
    }else{
        cout << ans + (2 * mx - ans) << endl;
    }
    }
int main(){
        solve();
    return 0; }