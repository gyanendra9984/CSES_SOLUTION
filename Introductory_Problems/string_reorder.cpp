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
    string s,ans="";
    cin >> s;
    int n = s.length();
    vector<int> mp(26, 0);
    for (int i = 0; i < n;i++){
        mp[s[i] - 'A']++;
    }
    int j = -1,mx=0;
    for (int i = 0; i < n;i++){
        mx = j;
        for (int k = 0; k < 26;k++){
            if(mp[k]>0 && k!=j){
                if(mp[k]>mp[mx]){
                    mx = k;
                }
            }
        }
        if (mp[mx] == (n - i + 1) / 2 && mx != j && mp[mx] != (n - i) / 2)
        {
            ans += 'A' + mx;
            mp[mx]--;
            j = mx;
        }
        else
        {
            for (int k = 0; k < 26; k++)
            {
                if (mp[k] > 0 && k != j)
                {
                    ans += 'A' + k;
                    mp[k]--;
                    j = k;
                    break;
                }
                if (k == 25)
                {
                    cout << "-1" << endl;
                    return;
                }
            }
        }
    }
    cout << ans << endl;
    }
int main(){
        solve();
    return 0; }