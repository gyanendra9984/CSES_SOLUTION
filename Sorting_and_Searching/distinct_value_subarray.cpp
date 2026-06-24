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
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    map<ll, ll> mp;
    ll j = 0,ans=1;
    mp[a[0]]++;
    for (ll i = 1; i < n;i++){
        mp[a[i]]++;
        while(i-j+1>mp.size()){
            mp[a[j]]--;
            if(mp[a[j]]==0)
                mp.erase(a[j]);
            j++;
        }
        ans += i - j + 1;
        // cout << ans<<" "<< endl;
    }
    cout << ans << endl;
    }
int main(){
        solve();
    return 0; }