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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> mp(26, 0);
    for (int i = 0; i < n; i++)
        mp[s[i] - 'A']++;
    int j = -1;
    for (int i = 0; i < 26; i++)
    {
        if (mp[i] % 2 == 1 && j != -1)
        {
            cout << "NO SOLUTION" << endl;
            return;
        }
        else if (mp[i] % 2 == 1)
        {
            j = i;
        }
    }
    int x = 0, y = n - 1;
    for (int i = 0; i < 26; i++)
    {
        if (i != j)
        {
            while (mp[i] > 0)
            {
                s[x] = 'A' + i;
                s[y] = 'A' + i;
                x++, y--,mp[i]-=2;
            }
        }
    }
    if (j != -1)
    {
        while (mp[j] > 0)
        {
            s[x] = 'A' + j;
            s[y] = 'A' + j;
            x++, y--, mp[j] -= 2;
        }
    }
    cout << s << endl;
}
int main()
{
    solve();
    return 0;
}