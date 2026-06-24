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
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n;i++){
        pre[i] = pre[i - 1] + v[i - 1];
    }
    while(q--){
        ll a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1]<< endl;
    }
}
int main(){
        solve();
    return 0; }