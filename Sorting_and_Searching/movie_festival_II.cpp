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
    int n, k;
    cin >> n>>k;
    vector<pair<int, int>> p(n);
    int x, y, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p[i] = {y, x};
    }
    multiset<int> s;
    sort(p.begin(), p.end());
    for (int i = 0; i < k; i++)
    {
        s.insert(0);
    }
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(s.begin(), s.end(), p[i].second);
        if(it!=s.begin()){
            it--;
            s.erase(it);
            s.insert(p[i].first);
            // cout << p[i].second << " " << p[i].first << endl;
            ans++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    solve();
    return 0;
}