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

// *order_of_key(k) : Returns the number of elements strictly smaller than k.

//* find_by_order(k) : Returns the address of the element at kth index in the set while using zero
//- based indexing,
// i.e the first element is at index zero.

    void solve()
{
    int n, k;
    cin >> n >> k;
    tree<int, null_type, less<int>, rb_tree_tag, // Policy based data structures in g++
         tree_order_statistics_node_update>
        set;
    //   ** when duplicate also provide in the set
    // tree<int, null_type, less_equal<int>, rb_tree_tag, // Policy based data structures in g++
    //      tree_order_statistics_node_update>
    //     set;
    for (int i = 1; i <= n; i++)
    {
        set.insert(i);
    }
    int i = k;
    while (set.size())
    {
        i = i % set.size();
        int x = *set.find_by_order(i);
        set.erase(x);
        cout << x << "\n";
        i += k;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
