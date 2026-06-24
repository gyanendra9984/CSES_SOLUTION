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
    int n1=1000000;
    vector<ll> a1(n1 + 1, 0);
    vector<ll> a2(n1 + 1, 0);
    a1[1] = 1;
    a2[1] = 1;
    for (int i = 2; i <= n1;i++){
        a1[i] = (a1[i - 1] * 2 + a2[i - 1]) % 1000000007;
        a2[i] = (a1[i - 1] + a2[i - 1] * 4) % 1000000007;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (a1[n] + a2[n]) % 1000000007 << endl;
    }
}
int main()
{
        solve();
    return 0;
}