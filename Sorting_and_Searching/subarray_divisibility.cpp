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
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0, sum = 0;
    mp[0] = 1;
    mp[n] = 0;
    for (int i = 0; i < n; i++)
    {
        sum =(a[i]+sum)%n;
        sum = (sum + n) % n;
        ans += mp[sum % n];
        mp[sum % n]++;
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}