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
    int x, n;
    cin >> x >> n;
    vector<int> a(n+2),b(n+2);
    int ans[n],bb=0;
    a[0] = 0, a[1] = x;
    for (int i = 2; i < (n+2); i++)
    {
        cin >> a[i];
    }
    set<int> s(a.begin(), a.end());
    set<int>::iterator it,pre,pos;
    b = a;
    sort(b.begin(), b.end());
    for (int i = 1; i < (n+2);i++){
        bb = max(bb,(b[i] - b[i - 1]));
    }
    for (int i = n+1;i>=2;i--){
        ans[i - 2] = bb;
        it = s.find(a[i]);
        pre = next(it, -1);
        pos = next(it, 1);
        s.erase(it);
        bb = max(bb,(*pos - *pre));
    }
    for (int i = 0; i < n;i++){
        cout << ans[i]<<" ";
    }
    }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
        solve();
    return 0; }