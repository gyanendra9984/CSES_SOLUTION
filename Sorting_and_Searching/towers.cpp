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

void solve()
{
    int n;
    cin >> n;
    int x,ans=0;
    multiset<int> mm;
    multiset<int>::iterator it;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        it = mm.upper_bound(x);
    if(it!=mm.end()){
       mm.erase(it);
    }else{
        ans++;
    }
    mm.insert(x);
}
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}