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
ll solve(ll n, ll k)
{
    if (n == 1)
        return 1;

    ll first_pass = (n + 1) / 2;

    if (k <= first_pass)
    {
        ll ans = 2 * k;
        if (ans > n)
            ans %= n;
        return ans;
    }

    ll res = solve(n / 2, k - first_pass);
    if (n % 2 == 1)
    {
        return 2 * res + 1;
    }
    else
    {
        return 2 * res - 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}