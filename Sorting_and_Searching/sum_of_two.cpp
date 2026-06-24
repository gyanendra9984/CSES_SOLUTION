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
#define pb(a) push_back(a)
#define For(a) for(int i=0;i<n;i++){ cin>>a[i];}
 
void solve(){
    int n, x;cin >> n >> x;
    int p, q;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        v[i] = {p, i+1};
    }
    sort(v.begin(), v.end());
    p = 0, q = n - 1;
    while (p < q)
    {
        if ((v[p].first + v[q].first) > x)
        {
            q--;
        }
        else if ((v[p].first + v[q].first) < x)
        {
            p++;
        }
        else
        {
            cout<<v[p].second<<" "<<v[q].second;
            return;
        }
    }
    cout << "IMPOSSIBLE";
        }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }