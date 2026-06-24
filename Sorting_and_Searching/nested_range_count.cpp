//           //XXXXXX\\          ||\\      //||
//          ||        \\         || \\    // ||
//          ||        ||         ||  \\  //  ||
//          ||                   ||   \\//   ||
//          ||   //XXX\\         ||          ||
//          ||   ||   ||   __    ||          ||   __
//          \\XXX//   ||  |__|   ||          ||  |__|
//  ||XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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

    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, // Policy based data structures in g++
         tree_order_statistics_node_update>
        s1,s2;
    ll x, y,mm=0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i] = {x, y, i};
        s1.insert({y,mm});
        s2.insert({y, mm});
        mm++;
    }
    sort(v.begin(), v.end(), [](const query &a, const query &b)
         { 
            if(a.start == b.start)
                return a.end > b.end;
            return a.start < b.start; });

    ll ma = n - 1;
    vector<int> ans(n, 0), ans2(n, 0);

    for (int i = 0; i < n; i++)
    {
        int count = s1.order_of_key({v[i].end,mm});
        ans[v[i].idx] = count-1;
        auto it = s1.lower_bound({v[i].end,0});
        s1.erase(it);
    }
    ma = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int count = s2.order_of_key({v[i].end, 0});
        ans2[v[i].idx] = ma-count;
        ma--;
        auto it = s2.lower_bound({v[i].end, 0});
        s2.erase(it);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << ans2[i] << " ";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
