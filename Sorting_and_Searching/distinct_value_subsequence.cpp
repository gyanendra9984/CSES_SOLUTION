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
ll mod = 1000000007;
ll power(ll a)
{
    ll res = 1;
    ll b = mod - 2;
    a %= mod;
    while (b > 0)
    {
        if (b%2==1) 
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b / 2;
    }
    return res;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 1;
    map<ll, ll> mp;
    mp[a[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            ans = (2 * ans + 1) % mod;
            mp[a[i]]++;
        }
        else
        {
            ans += (ans +1)*power(mp[a[i]]+1);
            ans = (ans) % mod;
            mp[a[i]]++;
        }
    }
    cout << ans << endl;
    }
int main(){
        solve();
    return 0; }