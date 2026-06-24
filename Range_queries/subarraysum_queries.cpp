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

void insert(vector<vector<ll>> &tree, ll l, ll r, ll i, ll idx, ll val)
{
    if(idx<l || idx>r){
        return;
    }
   if(l==r){
       tree[i] = {val,val,val,val};
       return;
   }
   ll mid=l+(r-l)/2;
    insert(tree, l, mid, 2 * i + 1, idx, val);
    insert(tree, mid + 1, r, 2 * i + 2, idx, val);
    tree[i][0] = (tree[2 * i + 1][0]+tree[2 * i + 2][0]);
    tree[i][1] = max(tree[2 * i + 1][1], tree[2 * i + 1][0] + tree[2 * i + 2][1]);
    tree[i][2] = max(tree[2 * i + 2][2], tree[2 * i + 2][0] + tree[2 * i + 1][2]);
    tree[i][3] = max({tree[2 * i + 1][3], tree[2 * i + 2][3], tree[2 * i + 1][2] + tree[2 * i + 2][1]});
}

 
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> tree(4 * n, {0ll, LLONG_MIN, LLONG_MIN, LLONG_MIN});
    for (int i = 0; i < n;i++){
        ll x;
        cin >> x;
        insert(tree, 0, n - 1, 0, i, x);
    }
    while(m--){
        ll k,x;
        cin >> k>>x;
        insert(tree, 0, n - 1, 0, k-1, x);
        cout << max(tree[0][3],0ll) << endl;
    }
    }
int main(){
        solve();
    return 0; }