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
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

ll query(vector<ll> &tree, ll l, ll r, ll i,ll x,ll n){
    if (tree[i]<x){
        return n;
    }
    if (l==r){
        return l;
    }
    ll mid = l + (r - l) / 2;
    if (tree[2 * i + 1]>=x)
        return query(tree, l, mid, 2 * i + 1, x, n);
    return query(tree, mid + 1, r, 2 * i + 2, x, n);
}
//insert(tree, 0, n - 1, 0, b - 1, c);
//query(tree, 0, n - 1, 0, b - 1, c - 1);
 
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<ll> tree(4 * n, 0);
    for (int i = 0; i < n;i++){
        cin>>a[i];
        insert(tree, 0, n - 1, 0, i, a[i]);
    }
    ll x;
    while (m--)
    {
        cin >> x;
        ll ans = query(tree, 0, n - 1, 0, x, n);
        if (ans == n)
        {
            cout << 0 << " ";
        }
        else
        {
            insert(tree, 0, n - 1, 0, ans, a[ans] - x);
            a[ans] -= x;
            cout << ans + 1 << " ";
        }
        }
    cout << endl;
    }
int main(){
        solve();
    return 0; }