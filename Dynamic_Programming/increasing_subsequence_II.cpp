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

#define ll long long

const ll MOD = 1e9 + 7;

void insert(vector<ll> &tree, ll l, ll r, ll i, ll idx, ll val)
{
    if (idx < l || idx > r)
        return;

    if (l == r)
    {
        tree[i] = (tree[i] + val) % MOD;
        return;
    }

    ll mid = l + (r - l) / 2;

    insert(tree, l, mid, 2 * i + 1, idx, val);
    insert(tree, mid + 1, r, 2 * i + 2, idx, val);

    tree[i] = (tree[2 * i + 1] + tree[2 * i + 2]) % MOD;
}

ll query(vector<ll> &tree, ll l, ll r, ll i, ll ql, ll qr)
{
    if (ql > r || qr < l)
        return 0;

    if (ql <= l && r <= qr)
        return tree[i];

    ll mid = l + (r - l) / 2;

    return (query(tree, l, mid, 2 * i + 1, ql, qr) +
            query(tree, mid + 1, r, 2 * i + 2, ql, qr)) %
           MOD;
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> comp = a;

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    ll m = comp.size();

    vector<ll> tree(4 * m + 5, 0);

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ll rank =
            lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();

        ll dp = 1;

        if (rank > 0)
        {
            dp = (dp + query(tree, 0, m - 1, 0, 0, rank - 1)) % MOD;
        }

        insert(tree, 0, m - 1, 0, rank, dp);

        ans = (ans + dp) % MOD;
    }

    cout << ans << '\n';
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}