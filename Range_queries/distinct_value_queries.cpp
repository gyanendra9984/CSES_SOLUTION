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

void insert(vector<ll> &tree, ll l, ll r, ll i, ll idx, ll val)
{
    if (idx < l || idx > r)
    {
        return;
    }
    if (l == r)
    {
        tree[i] = val;
        return;
    }
    ll mid = l + (r - l) / 2;
    insert(tree, l, mid, 2 * i + 1, idx, val);
    insert(tree, mid + 1, r, 2 * i + 2, idx, val);
    tree[i] = (tree[2 * i + 1]+ tree[2 * i + 2]);
}

ll query(vector<ll> &tree, ll l, ll r, ll i, ll ql, ll qr)
{
    if (ql <= l && qr >= r)
    {
        return tree[i];
    }
    if (ql > r || qr < l)
    {
        return 0;
    }
    ll mid = l + (r - l) / 2;
    return (query(tree, l, mid, 2 * i + 1, ql, qr)+query(tree, mid + 1, r, 2 * i + 2, ql, qr));
}
// insert(tree, 0, n - 1, 0, b - 1, c);
// query(tree, 0, n - 1, 0, b - 1, c - 1);

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> tree(4 * n, 0);
    vector<vector<pair<ll, ll>>> qr(n); 

    ll a, b;
    for (ll i = 0; i < q; i++)
    {
        cin >> a >> b;
        qr[a - 1].push_back({b - 1, i}); 
    }
    vector<ll> ans(q);
    map<ll, ll> mp;
    for(ll i=n - 1; i >= 0;i--){
        if (mp[v[i]])
        {
            insert(tree, 0, n - 1, 0, mp[v[i]], 0);
        }
        mp[v[i]] = i;
        insert(tree, 0, n - 1, 0, i, 1);
        for(auto qq:qr[i]){
            ans[qq.second] = query(tree, 0, n - 1, 0, 0, qq.first);
        }
    }
    for(auto i:ans){
        cout << i << endl;
    }
}
int main()
{
    solve();
    return 0;
}