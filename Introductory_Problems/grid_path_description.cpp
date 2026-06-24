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
vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, -1, 1};
map<char, int> mp = {{'D', 1}, {'U', 2}, {'L', 3}, {'R', 4}};
bool vis[7][7] = {0};
string s;
int ans = 0;

bool blocked(int x, int y)
{
    if ((x == 0 || vis[x - 1][y]) && (x == 6 || vis[x + 1][y]))
    {
        if (y > 0 && !vis[x][y - 1] && y < 6 && !vis[x][y + 1])
            return true;
    }
    if ((y == 0 || vis[x][y - 1]) && (y == 6 || vis[x][y + 1]))
    {
        if (x > 0 && !vis[x - 1][y] && x < 6 && !vis[x + 1][y])
            return true;
    }
    return false;
}
void fun(int i, int j, int idx)
{
    if (i == 6 && j == 0)
    {
        if (idx == 48)
            ans++;
        return;
    }
    if (idx > 47)
    {
        return;
    }
    if (blocked(i, j))
        return;
    if (s[idx] != '?')
    {
        int xx = mp[s[idx]] - 1;
        int i1 = i + x[xx], j1 = j + y[xx];
        if (i1 >= 0 && i1 < 7 && j1 >= 0 && j1 < 7 && vis[i1][j1] == 0)
        {
            vis[i1][j1] = 1;
            fun(i1, j1, idx + 1);
            vis[i1][j1] = 0;
        }
    }

    else
    {
        for (int d = 0; d < 4; d++)
        {
            int i1 = i + x[d], j1 = j + y[d];
            if (i1 >= 0 && i1 < 7 && j1 >= 0 && j1 < 7 && vis[i1][j1] == 0)
            {
                vis[i1][j1] = 1;
                fun(i1, j1, idx + 1);
                vis[i1][j1] = 0;
            }
        }
    }
}
void solve()
{
    cin >> s;
    vis[0][0] = 1;
    int idx = 0;
    fun(0, 0, idx);
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}