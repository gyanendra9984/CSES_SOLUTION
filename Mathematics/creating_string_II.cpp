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

vector<ll> fact(1000000 + 1, 1);
ll mod = 1000000007;

ll power(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return (ans) % mod;
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> a(26, 0);
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'a']++;
    }
    ll ans = fact[n];
    for (int i = 0; i < 26; i++)
    {
        ans = (ans * power(fact[a[i]], mod - 2, mod)) % mod;
    }
    cout << ans << endl;
}
int main()
{
    for (ll i = 1; i <= 1000000; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
    solve();
    return 0;
}