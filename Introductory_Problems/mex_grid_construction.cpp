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

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        v[i][0] = i;
    }

    map<int, int> mp;
    int x = 0;
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < j;k++){
                mp[v[i][k]]++;
            }
            x = 0;
            while(mp.find(x)!=mp.end() && mp[x]>0){
                x++;
            }
            v[i][j] = x;
            mp[x]++;
            for (int k = 0; k < j; k++)
            {
                mp[v[i][k]]--;
            }
        }
        mp.clear();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}