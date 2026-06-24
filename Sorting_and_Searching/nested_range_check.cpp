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
struct query
{
    ll start, end, idx;
};
void solve()
{
    int n;
    cin >> n;
    vector<query> v(n);
    ll x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i] = {x, y, i};
    }
    sort(v.begin(), v.end(), [](const query &a, const query &b)
         { 
            if(a.start == b.start)
                return a.end > b.end;
            return a.start < b.start; });
    ll mi = v[n - 1].end + 1, ma = v[0].end - 1;
    vector<bool> ans(n, 0), ans2(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (ma >= v[i].end)
            ans2[v[i].idx] = true;
        ma = max(ma, v[i].end);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (mi <= v[i].end)
            ans[v[i].idx] = true;
        mi = min(mi, v[i].end);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans2[i] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
