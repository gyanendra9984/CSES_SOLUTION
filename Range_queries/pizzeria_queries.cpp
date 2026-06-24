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

ll query(vector<ll> &tree, ll l, ll r, ll i, ll ql, ll qr){
    if (ql <= l && qr >= r){
        return tree[i];
    }
    if (ql > r || qr < l){
        return INT_MAX;
    }
    ll mid = l + (r - l) / 2;
    return min(query(tree, l, mid, 2 * i + 1, ql, qr), query(tree, mid + 1, r, 2 * i + 2, ql, qr));
}
//insert(tree, 0, n - 1, 0, b - 1, c);
//query(tree, 0, n - 1, 0, b - 1, c - 1);
 
void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> tree1(4 * n, INT_MAX),tree2(4*n,INT_MAX);
    ll val;
    for (int i = 0; i < n;i++){
        cin >> val;
        insert(tree1, 0, n - 1, 0, i, val+i+1);
        insert(tree2, 0, n - 1, 0, i, val + n-i);
    }
    ll ty, k, x;
    while(q--){
        cin >> ty;
        if(ty==1){
            cin >> k >> x;
            k--;
            insert(tree1, 0, n - 1, 0, k, x + k+1);
            insert(tree2, 0, n - 1, 0, k, x + n - k);
        }else{
            cin >> k;
            k--;
            ll ans1 = query(tree1, 0, n - 1, 0, k, n-1)-k-1;
            ll ans2 = query(tree2, 0, n - 1, 0, 0, k)-n+k;
            cout << min(ans1, ans2) << endl;
        }
    }
    }
int main(){
        solve();
    return 0; }