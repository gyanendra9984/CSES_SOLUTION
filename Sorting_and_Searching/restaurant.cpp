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
#define pb(a) push_back(a)
#define For(a) for(int i=0;i<n;i++){ cin>>a[i];}
 
void solve(){
        int n;cin>>n;
        vector<pair<int,int>> a(2*n);
        int x,y,ans=0,aa=0;
        for(int i=0;i<2*n;i=i+2){
            cin>>x>>y;
            a[i] = {x,1};
            a[i+1] = {y,-1};
        }
        sort(a.begin(),a.end());
        for (int i = 0;i < 2*n;i++){
            aa += a[i].second;
            ans = max(ans, aa);
        }
            cout << ans;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }