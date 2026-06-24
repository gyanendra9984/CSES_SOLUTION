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
    int n;cin >> n;
    vector<pair<int,int>> p(n);
    int x, y, ans = 0;
    for (int i = 0; i < n;i++){
        cin >> x >> y;
        p[i] = {y, x};
    }
     x = 0;
     sort(p.begin(), p.end());
     for (int i = 0; i < n; i++)
     {
         if (p[i].second >= x)
         {
             ans++;
             x = p[i].first;
         }
    }
    cout << ans << "\n";
    }
int main(){
        solve();
    return 0; }