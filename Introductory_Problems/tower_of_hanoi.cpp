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
 
void solve(){
    int n;cin>>n;
    vector<pair<int, int>> a1, a2;
    a1.push_back({1, 3});
    map<int, int> mp1, mp2;
    mp1[2] = 3, mp1[3] = 2, mp1[1] = 1;
    mp2[1] = 2, mp2[2] = 1, mp2[3] = 3;
    while (n > 1)
    {
       for(auto x: a1){
           a2.push_back({mp1[x.first], mp1[x.second]});
        }
        a2.push_back({1, 3});
        for (auto x : a1)
        {
            a2.push_back({mp2[x.first], mp2[x.second]});
        }
        n--;
        a1.clear();
        a1=a2;
        a2.clear();
     }
     cout<<a1.size()<<endl;
        for(auto x: a1){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
int main(){
        solve();
    return 0; }