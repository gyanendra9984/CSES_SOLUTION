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
    ll ans = 0;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll x = 0;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                ans += i - x;
                mp[a[x]]--;
                if (mp[a[x]] == 0)
                    mp.erase(a[x]);
                x++;
            }
        }
    }
    ans += ((n - x) * (n - x + 1)) / 2;
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}