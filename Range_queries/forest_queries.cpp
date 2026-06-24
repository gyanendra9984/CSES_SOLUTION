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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n, 0));
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == '*')
                a[i][j] = 1;
        }
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = 0;
        for (int j = 0; j < n; j++)
        {
            x += a[i][j];
            a[i][j] = x;
            if (i > 0)
                a[i][j] += a[i - 1][j];
        }
    }
    while (q--)
    {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--, x2--, y2--;
        int ans = a[y2][x2];
        if (x1 - 1 >= 0)
        {
            ans -= a[y2][x1 - 1];
        }
        if (y1 - 1 >= 0)
        {
            ans -= a[y1 - 1][x2];
        }
        if (x1 - 1 >= 0 && y1 - 1 >= 0)
        {
            ans += a[y1 - 1][x1 - 1];
        }
        cout << ans << endl;
    }
}
int main()
{
    solve();
    return 0;
}