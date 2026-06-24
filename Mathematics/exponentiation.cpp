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
// ll fun(ll a, ll b, ll mod)
// {
//     if(b==0){
//         return 1;
//     }
//     if (b % 2 == 1)
//     {
//         return (a * fun((a * a) % mod, (b / 2), mod))%mod;
//     }
//     else
//     {
//         return (fun((a * a) % mod, b / 2, mod))%mod;
//     }
// }
ll fun(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b>0){
        if(b%2==1){
            ans = (ans * a)%mod;
        }
        a = (a * a)%mod;
        b = b / 2;
    }
    return ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
     cout << fun(a, b,1000000007) << endl;

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}