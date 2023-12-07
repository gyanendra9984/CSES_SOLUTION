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
        ll n;cin>>n;
    while(n!=1){
     cout<<n<<" ";
     if((n%2)==0) n/=2;
     else{
        n*=3;
        n+=1;
     }
   }
   cout<<n;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }