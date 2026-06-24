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
void rec(vector<string>& v,int& ans, string& s, int i, int j,int p){
    if(i == 6 && j == 6){
        ans++;
        return;
    }
    for (int k = p; k < 48;k++){
        if((s[k] == 'R' || s[k]=='?') && j + 1 < 7 && v[i][j + 1] == '?'){
            v[i][j + 1] = 'R';
            rec(v, ans, s, i, j + 1,k+1);
            v[i][j + 1] = '?';
        }
        if((s[k] == 'L' || s[k]=='?') && j - 1 >= 0 && v[i][j - 1] == '?'){
            v[i][j - 1] = 'L';
            rec(v, ans, s, i, j - 1,k+1);
            v[i][j - 1] = '?';
        }
        if((s[k] == 'U' || s[k]=='?')&& i - 1 >= 0 && v[i - 1][j] == '?'){
            v[i - 1][j] = 'U';
            rec(v, ans, s, i - 1, j,k+1);
            v[i - 1][j] = '?';
        }
        if((s[k] == 'D' || s[k]=='?') && i + 1 < 7 && v[i + 1][j] == '?'){
            v[i + 1][j] = 'D';
            rec(v, ans, s, i + 1, j,k+1);
            v[i + 1][j] = '?';
        }
        return;
    }
}
void solve(){
        string s;
        cin >> s;
        vector<string> v(7, string(7, '?'));
        int i = 0, j = 0;
        int ans = 0;
        rec(v,ans, s, i, j,0);
        cout<<ans<<endl;
    }
int main(){
        solve();
    return 0; }