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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll i = a[0], j = a[0] * k;
    ll ans = j, md,pro=0;
    while (i <= j)
    {
        md = (i + j) / 2;
        pro = 0;
        for (int i = 0; i < n;i++){
            pro += md / a[i];
        }
        if(pro>=k){
            ans = min(ans,md);
            j = md - 1;
        }else{
            i = md + 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}