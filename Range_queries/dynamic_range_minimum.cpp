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
void insert(vector<ll>& tree, ll l, ll r, ll i, ll idx, ll val){
    if(idx<l || idx>r){
        return;
    }
   if(l==r){
       tree[i] = val;
       return;
   }
   ll mid=l+(r-l)/2;
    insert(tree, l, mid, 2 * i + 1, idx, val);
    insert(tree, mid + 1, r, 2 * i + 2, idx, val);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

ll query(vector<ll> &tree, ll l, ll r, ll i, ll ql, ll qr)
{
    if (ql <= l && qr >= r)
    {
        return tree[i];
    }
    if (ql > r || qr < l)
    {
        return LLONG_MAX;
    }
    ll mid = l + (r - l) / 2;
    return min(query(tree, l, mid, 2 * i + 1, ql, qr), query(tree, mid + 1, r, 2 * i + 2, ql, qr));
}
void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<ll> tree(4 * n, LLONG_MAX);
    for(int i=0;i<n;i++){
        insert(tree, 0, n - 1, 0, i, v[i]);
    }
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            insert(tree, 0, n - 1, 0, b - 1, c);
        }else{
            cout << query(tree, 0, n - 1, 0, b - 1, c - 1) << endl;
        }
    }

}
int main(){
        solve();
    return 0; }