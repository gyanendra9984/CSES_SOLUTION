//           //XXXXXX\\          ||\\      //||
//          ||        \\         || \\    // ||
//          ||        ||         ||  \\  //  ||
//          ||                   ||   \\//   ||
//          ||   //XXX\\         ||          ||
//          ||   ||   ||   __    ||          ||   __
//          \\XXX//   ||  |__|   ||          ||  |__|
//  ||XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//ordered_set os; make ordered set
//*os.find_by_order(2) find 3rd element
//os.order_of_key(6) number of elements less than 6
 
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ordered_set s;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        s.insert(i);
    }

    ll x;
    while(n--){
        cin >> x;
        x--;
        ll idx = *s.find_by_order(x);
        s.erase(idx);
        cout << a[idx] << " ";
    }
    cout << endl;
    }
int main(){
        solve();
    return 0; }