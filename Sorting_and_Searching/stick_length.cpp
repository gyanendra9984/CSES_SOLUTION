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
    int a[n];
    ll sum=0,ans=0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    if(n%2==1)
        sum = a[n/2];
    else
        sum = (a[(n-1) / 2] + a[n / 2]) / 2;
    for (int i = 0; i < n; i++)
    {
        ans += abs(sum - a[i]);
    }
    cout <<ans;
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }