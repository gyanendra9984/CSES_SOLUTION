#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll a, b, c, d;
    ll p, q, r, s;
    cin >> a >> b >> c >> d >> p >> q >> r >> s;

    if ((b - d) * (__int128_t)(p - r) != (__int128_t)(a - c) * (q - s) || (((a + c) - (p + r)) * (__int128_t)(a - c)) == (-(__int128_t)(b - d) * ((b + d) - (q + s))))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}