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
        int n,x;cin>>n;
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>x;
            s.insert(x);
        }
        cout<<s.size();
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }