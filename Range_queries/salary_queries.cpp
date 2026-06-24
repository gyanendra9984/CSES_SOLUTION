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
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ordered_set os; make ordered set
//*os.find_by_order(2) find 3rd element
// os.order_of_key(6) number of elements less than 6

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    ordered_set s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert({a[i],i});
    }
    char ch;
    int x, y;
    while (q--)
    {
        cin >> ch >> x >> y;
        if(ch =='!'){
            x--;
            s.erase({a[x],x});
            s.insert({y,x});
            a[x] = y;
        }else{
            ll ans = s.order_of_key({y+1,0})-s.order_of_key({x,0});
            cout << ans << endl;
        }
    }
}
int main()
{
    solve();
    return 0;
}