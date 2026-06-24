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
        ll n;cin >> n;
        ll len = 1;
        ll start = 1;
        ll cnt = 9;
        while(n>len*cnt){
            n -= len*cnt;
            len++;
            start *= 10;
            cnt *= 10;
        }
        ll num = start + (n-1)/len;
        string s = to_string(num);
        cout << s[(n-1)%len] << endl;

    }
int main(){
    int t;cin >> t;
    while (t--){
        solve();
    }
    return 0; }