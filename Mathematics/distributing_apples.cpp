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
    vector<ll> fact(2000000 + 1, 1);
    ll mod = 1000000007;
    fact[0] = 1;
    for (ll i = 1; i <= 2000000; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }

    ll n, m;
    cin >> n >> m;
    ll ans = ((fact[n+m-1] * power(fact[m], mod - 2, mod)) % mod * power(fact[n-1], mod - 2, mod)) % mod;
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}