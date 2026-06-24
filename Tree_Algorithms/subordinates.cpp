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

void fun(vector<vector<int>> &v, vector<int> &ans,int x)
{
    if(v[x].size()==0){
        ans[x] = 0;
        return;
    }
    int sum = 0;
    for(auto val:v[x]){
       fun(v, ans, val);
       sum += ans[val]+1;
    }
    ans[x] = sum;
}

void solve(){
        int n;
        cin >> n;
        vector<int> ans(n+1,0);
        vector<vector<int>> v(n + 1);
        for (int i = 2; i <= n;i++){
            int x;
            cin >>x;
            v[x].push_back(i);
        }
        fun(v, ans, 1);
        for (int i = 1; i <= n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
int main(){
    int t;
    //cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0; }