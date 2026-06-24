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
 
void  rec(string s,vector<string>& ans,int i,int& n){
   if(i==n-1){
         ans.push_back(s);
         return;
   }
   for(int j=i;j<n;j++){
    bool ok = true;
     for(int k=i;k<j;k++){
         if(s[k]==s[j]){
            ok = false;
         }
      }
      if(!ok) continue;
      swap(s[i], s[j]);
      rec(s, ans, i + 1, n);
      swap(s[i], s[j]);
   }
}
void solve(){
        string s;
        cin >> s;
        int n = s.size();
        sort(s.begin(), s.end());
        vector<string> ans;
        rec(s,ans,0,n);
        sort(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(auto x:ans){
            cout << x << endl;
        }
    }
    int main()
    {
        solve();
    return 0;
    }