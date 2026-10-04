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
void solve2(int n,string s){
    if (n == 0)
    {
        cout << s <<endl;
        return;
    }
    solve2(n - 1, s + "0");
    solve2(n - 1, s + "1");
}
void solve(){
    int n;
    cin >> n;
    solve2(n, "");
    }
int main(){
        solve();
    return 0; }