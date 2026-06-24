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
    vector<pair<ll, ll>> a(n);
    ll x, y;
    for (int i = 0; i < n;i++){
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    x = 0;
    for (int i = 0; i < n;i++){
        x += a[i].first;
        ans += a[i].second- x;
    }
    cout << ans << endl;
    }
int main(){
        solve();
    return 0; }