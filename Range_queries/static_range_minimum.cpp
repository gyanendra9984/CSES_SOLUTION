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
 
void construct(vector<ll>& v, vector<ll>& tree, ll l, ll r, ll i){
    if(l==r){
        tree[i] = v[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    construct(v, tree, l, mid, 2 * i + 1);
    construct(v, tree, mid + 1, r, 2 * i + 2);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
ll query(vector<ll>& tree, ll l, ll r, ll i, ll ql, ll qr){
    if(ql<=l && qr>=r){
        return tree[i];
    }
    if(ql>r || qr<l){
        return LLONG_MAX;
    }
    ll mid = l + (r - l) / 2;
    return min(query(tree, l, mid, 2 * i + 1, ql, qr), query(tree, mid + 1, r, 2 * i + 2, ql, qr));
}
void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<ll> tree(4 * n, LLONG_MAX);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    construct(v, tree, 0, n - 1, 0);
    while(q--){
        ll a, b;
        cin >> a >> b;
        cout << query(tree, 0, n - 1, 0, a - 1, b - 1) << endl;
    }

    }
int main(){
        solve();
    return 0; }