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

vector<pair<int,int>> ii = {{0,1}, {0,-1}, {1,0}, {-1,0}};
map<pair<int, int>, char> mp = {{{0, 1},'R'}, {{0, -1},'L'}, {{1, 0},'D'}, {{-1, 0},'U'}};
void bfs(pair<int, int> st, pair<int, int> en, vector<vector<bool>> &visited, vector<string> &v, map<pair<int, int>, pair<int, int>> &parent)
{
    queue<pair<int, int>> q;
    q.push(st);
    visited[st.first][st.second] = true;
    while(!q.empty()){
        pair<int, int> d = q.front();
        q.pop();
        if(d==en)
            break;
        for (auto x : ii)
        {
            pair<int, int> di = {x.first + d.first, x.second + d.second};
            if (di.first >= 0 && di.first < v.size() && di.second >= 0 && di.second < v[0].size() && v[di.first][di.second] != '#' && visited[di.first][di.second]==false)
            {
                parent[di] = d;
                visited[di.first][di.second] = true;
                q.push(di);
           }
            
        }
    }
    
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    pair<int, int> st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m;j++){
            if(v[i][j]=='A'){
                st = {i, j};
            }
            if (v[i][j] == 'B')
            {
                en = {i, j};
            }
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    map<pair<int, int>, pair<int, int>> parent;
    string ans = "",s="";
    bfs(st, en, visited, v,parent);

    if(parent.find(en)==parent.end()){
        cout << "NO" << endl;
        
    }else{
        cout << "YES" << endl;
        pair<int, int> cur = en,cur2;
        while(cur!=st){
            cur2 = parent[cur];
            ans.push_back(mp[{cur.first - cur2.first, cur.second - cur2.second}]);
            cur = cur2;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.length() << endl;
        cout << ans << endl;
    }
}
int main()
{
    solve();
    return 0;
}