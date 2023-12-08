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
        int n,m,k;cin>>n>>m>>k;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        int i=0,j=0,ans=0;
        while(i<n&&j<m){
           if(b[j]<=a[i]+k&&(b[j]>=a[i]-k)){
            ans++;
            j++;i++;
           }else if(b[j]<a[i]-k){
             j++;
           }else{
            i++;
           }
        }
        cout<<ans;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }