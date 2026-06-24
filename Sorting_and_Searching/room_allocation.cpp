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
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    vector<vector<int>> a(n,vector<int>(3,0));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    p.push({a[0][1], 1});
    int ans = 1;
    vector<int> ans2(n,1);
    for (int i = 1; i < n; i++)
    {
        pair<int, int> p2 = p.top();
        // cout << a[i].first << ' ' << p2.first << endl;
        if (a[i][0]> p2.first)
        {
            ans2[a[i][2]]=p2.second;
            p.pop();
            p.push({a[i][1], p2.second});
        }
        else
        {
            ans++;
            ans2[a[i][2]] = ans;
            p.push({a[i][1], ans});
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}