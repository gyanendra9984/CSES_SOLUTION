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

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
 
void solve(){
    int n;
    cin >> n;
    tree<int, null_type, less<int>, rb_tree_tag,
         tree_order_statistics_node_update>
        set;
    for (int i = 1; i <= n;i++){
        set.insert(i);
    }
    int i = 1;
    while (set.size())
    {
        i =i%set.size();
        int x = *set.find_by_order(i);
        set.erase(x);
        cout << x << "\n";
        i += 1;
    }
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }