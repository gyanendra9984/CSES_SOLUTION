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
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            ll sum = a[l].first + a[r].first + a[i].first;
            if (sum== x)
            {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << endl;
                return;
            }
            else if (sum > x)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    solve();
    return 0;
}