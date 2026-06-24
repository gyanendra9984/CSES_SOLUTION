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
    int n;
    cin >> n;
    int a[n+1],ans=1,aa=1,x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = aa;
        aa++;
    }
    for (int i = 2; i <= n; i++)
    {
       if(a[i]<a[i-1])
           ans++;
    }
    cout << ans;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }