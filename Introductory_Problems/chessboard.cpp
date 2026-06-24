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
bool possible(vector<string>& s,int q,int i){
    if(s[q][i]=='*'){
        return false;
    }
   for(int j=0;j<8;j++){
       if(s[j][i]=='Q' || s[q][j]=='Q'){
           return false;
       }
   }
    for(int j=1;j<8;j++){
         if(q-j>=0 && i-j>=0 && s[q-j][i-j]=='Q'){
              return false;
         }
         if(q+j<8 && i+j<8 && s[q+j][i+j]=='Q'){
              return false;
         }
         if(q-j>=0 && i+j<8 && s[q-j][i+j]=='Q'){
                return false;
        }
        if(q+j<8 && i-j>=0 && s[q+j][i-j]=='Q'){
                return false;
        }
    }
    return true;
}
void rec(vector<string>& s,int& ans,int q){
   if(q==8){
       ans++;
       return;
   }
   for (int i = 0; i < 8;i++){
      if(possible(s,q,i)){
        s[q][i] = 'Q';
        rec(s, ans, q + 1);
        s[q][i] = '.';
      }
   }
}
void solve(){
    vector<string> s(8);
    for(int i=0;i<8;i++){
        cin >> s[i];
    }
    int ans = 0;
    rec(s, ans, 0);
    cout << ans << endl;
    }
int main(){
    solve();
    return 0; }