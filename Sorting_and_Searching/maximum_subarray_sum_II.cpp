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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n),psum(n,0);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        psum[i] = sum;
    }
    multiset<ll> s;
    ll ans = LLONG_MIN;
    for (int i = a-1; i < n && i < b;i++){
        s.insert(psum[i]);
    }
    ll val = *s.rbegin();
    ans = max(ans, val);
    for (int i = b; i < n;i++){
        s.insert(psum[i]);
        auto it = s.find(psum[i - (b - a + 1)]);
       if(it!=s.end()) s.erase(it);
       val = *s.rbegin();
       ans = max(ans, val - psum[i - b]);
    }
    for (int i = n - 1 - (b - a); i < n-1;i++){
        auto it = s.find(psum[i]);
        if (it != s.end())
            s.erase(it);
        val = *s.rbegin();
        ans = max(ans, val - psum[i - (a-1)]);
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}