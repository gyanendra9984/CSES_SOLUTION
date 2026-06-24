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
    int n;cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> dp;
    for (int i = 0; i < n;i++){
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if(it==dp.end()){
            dp.push_back(a[i]);
        }else{
            *it = a[i];
        }
    }
    cout << dp.size() << endl;
    }
int main(){
        solve();
    return 0; }