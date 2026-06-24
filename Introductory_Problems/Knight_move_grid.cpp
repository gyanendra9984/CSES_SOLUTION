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
vector<pair<int, int>> check = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, 2}, {1, -2}};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int x = 0; x < check.size(); x++)
        {
            int i1 = p.first + check[x].first, j1 = p.second + check[x].second;
            if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < n)
            {
                if (dp[i1][j1] == -1)
                {
                    dp[i1][j1] = 1 + dp[p.first][p.second];
                    q.push({i1, j1});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}