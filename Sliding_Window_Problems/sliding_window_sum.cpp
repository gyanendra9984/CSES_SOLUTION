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
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    ll ans = 0;
    ll sum = 0, x2 = x;
    for (int i = 0; i < n;i++){
        if(i<k){
            sum += x2;
            x2 = (a * x2 + b) % c;
        }else{
            ans = ans ^ sum;
            sum -= x;
            x = (a * x + b) % c;
            sum += x2;
            x2 = (a * x2 + b) % c;
        }
    }
    cout << (ans^sum) << endl;
    }
int main(){
    int t;
    t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0; }