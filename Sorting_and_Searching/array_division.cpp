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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll r=0, l = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l =max(a[i],l);
        r += a[i];
    }
    ll mid,c=0,sum=0,ans=r;
    while(l<=r){
        mid = (l + r) / 2;
        c = 1,sum=0;
        for (int i = 0; i < n;i++){
            sum += a[i];
            if(sum>mid){
                sum = a[i];
                c++;
            }
        }
        if(c<=k){
            ans = min(ans, mid);
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}