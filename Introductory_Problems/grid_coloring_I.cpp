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
char findc(string s){
    if (s.find('A')== string::npos)
    {
        return 'A';
    }
    else if (s.find('B') == string::npos)
    {
        return 'B';
    }
    else if (s.find('C') == string::npos)
    {
        return 'C';
    }
  else
  {
      return 'D';
  }
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<string> ans(n, string(m,'.'));
    string s;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            s = a[i][j];
          if(i>0)
              s.push_back(ans[i - 1][j]);
          if (j > 0)
              s.push_back(ans[i][j-1]);
          ans[i][j] = findc(s);
        }
    }
    for (int i = 0; i < n;i++){
        cout << ans[i] << endl;
    }
    }
int main(){
        solve();
    return 0; }