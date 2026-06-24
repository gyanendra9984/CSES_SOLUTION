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
 
void insert(vector<pair<ll,ll>>& tree, ll l, ll r, ll i, ll idx, ll val){
    if(idx<l || idx>r){
        return;
    }
   if(l==r){
       tree[i] = {val,val};
       return;
   }
   ll mid=l+(r-l)/2;
    insert(tree, l, mid, 2 * i + 1, idx, val);
    insert(tree, mid + 1, r, 2 * i + 2, idx, val);
    tree[i].first = max(tree[2 * i + 1].first, tree[2 * i + 1].second+tree[2 * i + 2].first);
    tree[i].second = (tree[2 * i + 1].second+tree[2 * i + 2].second);
}

pair<ll,ll> query(vector<pair<ll,ll>> &tree, ll l, ll r, ll i, ll ql, ll qr){
    if (ql <= l && qr >= r){
        return {tree[i].first,tree[i].second};
    }
    if (ql > r || qr < l){
        return {INT_MIN,0};
    }
    ll mid = l + (r - l) / 2;
    pair<ll,ll> l1 = query(tree, l, mid, 2 * i + 1, ql, qr);
    pair<ll,ll> l2 = query(tree, mid + 1, r, 2 * i + 2, ql, qr);
    if(l2.first==INT_MIN)
        return {l1.first, l1.second + l2.second};
    return {max(l1.first,l1.second+l2.first), l1.second+l2.second};
}
//insert(tree, 0, n - 1, 0, b - 1, c);
//query(tree, 0, n - 1, 0, b - 1, c - 1);
 
void solve(){
    ll n, q;
    cin >> n >> q;
    vector<pair<ll,ll>> tree(4 * n);
    ll x;
    for (int i = 0; i < n;i++){
        cin >> x;
        insert(tree, 0, n - 1, 0, i, x);
    }
    ll ty, a, b;

    while(q--){
        cin >> ty >> a >> b;
        if(ty==1){
            insert(tree, 0, n - 1, 0, a-1, b);
        }else{
            cout<<max(0ll,query(tree, 0, n - 1, 0, a-1, b-1).first)<<endl;
        }
    }
    
    }
int main(){
        solve();
    return 0; }