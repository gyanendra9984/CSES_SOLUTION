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
    vector<ll> a(n);
    unordered_map<ll, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mp[a[i] + a[j]] = {i, j};
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mp.find(x - a[i] - a[j]) != mp.end() && mp[x - a[i] - a[j]].first > j)
            {
                cout << i + 1 << " " << j + 1 << " " << mp[x - a[i] - a[j]].first + 1<<" "<< mp[x - a[i] - a[j]].second + 1 << endl;
                return;
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