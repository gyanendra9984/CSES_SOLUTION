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
        int n,m;cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int i=0,j=n-1,ans=0;
        while(i<n&&j>=0&&i<=j){
           if((a[i]+a[j])<=m){
            i++;j--;
           }else{
             j--;
           }
           ans++;
        }
        cout<<ans;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }