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
#define pb(a) push_back(a)
#define For(a) for(int i=0;i<n;i++){ cin>>a[i];}
 
void solve(){
        int n,m;cin>>n>>m;
        multiset<int> a;
        int x;
        for(int i=0;i<n;i++){
            cin >> x;
            a.insert(-x);
        }
        multiset<int>::iterator it;
        for(int i=0;i<m;i++){
            cin >> x;
            it = a.lower_bound(-x);
            if(it!=a.end()){
                cout << -*it << "\n";
                a.erase(it);
            }else{
                cout << "-1\n";
            }
        }
       
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }