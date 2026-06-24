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

void bfs(int i,vector<bool> &visited , vector<vector<int>> &adj){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        for(auto x : adj[val]){
            if(visited[x]==false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n * m);
    vector<string> v(n);

    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(v[i][j]=='.'){
                adj[i * m + j].push_back(i * m + j);
                if( i+1<n && v[i+1][j]=='.'){
                    adj[i * m + j].push_back((i + 1) * m + j);
                }
                if (j+1<m && v[i][j+1] == '.')
                {
                    adj[i * m + j].push_back(i * m + j+1);
                }
                if (i>=1 && v[i - 1][j] == '.')
                {
                    adj[i * m + j].push_back((i - 1) * m + j);
                }
                if (j>=1 && v[i][j-1] == '.')
                {
                    adj[i * m + j].push_back(i * m + j - 1);
                }
            }
        }
    }

    vector<bool> visited(n * m, false);
    int ans = 0;
    for (int i = 0; i < n * m;i++){
        if(adj[i].size()>0 && visited[i]==false){
            ans++;
            bfs(i,visited,adj);
        }
    }

       
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}