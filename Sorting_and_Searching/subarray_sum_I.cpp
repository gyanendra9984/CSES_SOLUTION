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
    vector<ll> a(n);
    map<ll, ll> mp;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    ll ans = 0,sum=0;
    mp[0] = 1;
    for (int i = 0; i < n;i++){
        sum += a[i];
        mp[sum]++;
        ans += mp[sum - x];
    }
    cout << ans << endl;
    }
int main(){
        solve();
    return 0; }