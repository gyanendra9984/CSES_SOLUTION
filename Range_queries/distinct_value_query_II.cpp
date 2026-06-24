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
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

ll query(vector<ll> &tree, ll l, ll r, ll i, ll ql, ll qr)
{
    if (ql <= l && qr >= r)
    {
        return tree[i];
    }
    if (ql > r || qr < l)
    {
        return LLONG_MIN;
    }
    ll mid = l + (r - l) / 2;
    return max(query(tree, l, mid, 2 * i + 1, ql, qr), query(tree, mid + 1, r, 2 * i + 2, ql, qr));
}
// insert(tree, 0, n - 1, 0, b - 1, c);
// query(tree, 0, n - 1, 0, b - 1, c - 1);

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    map<ll, set<ll>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> tree(4 * n, -1);
    for (int i = 0; i < n; i++)
    {
        if (!mp[a[i]].empty())
        {
            ll val = *mp[a[i]].rbegin();
            insert(tree, 0, n - 1, 0, i, val);
        }
        else
        {
            insert(tree, 0, n - 1, 0, i, -1);
        }
        mp[a[i]].insert(i);
    }
    while (q--)
    {
        ll type, a1, a2;
        cin >> type >> a1 >> a2;
        if(type==2){
            a1--, a2--;
            ll idx = query(tree, 0, n - 1, 0, a1, a2);
            cout << (idx < a1 ? "YES\n" : "NO\n");
        }else{
            a1--;
            mp[a[a1]].erase(a1);
            auto it = mp[a[a1]].upper_bound(a1);
            if (it != mp[a[a1]].end()){
                int idx = *it,val=-1;
                if (it != mp[a[a1]].begin()){
                    it--;
                    val = *it;
                }
                insert(tree, 0, n - 1, 0, idx, val);
            }
            it = mp[a2].upper_bound(a1);
            if (it != mp[a2].end())
            {
                int idx = *it;
                insert(tree, 0, n - 1, 0, idx,a1);
            }
            if (mp[a2].size() > 0 && it != mp[a2].begin()){
                it--;
                int val = *it;
                insert(tree, 0, n - 1, 0, a1, val);
            }
            a[a1] = a2;
            mp[a2].insert(a1);
        }

    }
}
int main()
{
    solve();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve(){
        
    }
int main(){
    int t;cin >> t;
    while (t--){
        solve();
    }
    return 0; }