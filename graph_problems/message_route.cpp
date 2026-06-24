#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int n;
    vector<vector<int>> adj;

    Graph(int n_)
    {
        n = n_;
        adj.resize(n + 1);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }
};

class BFS
{
public:
    vector<int> dist;
    vector<int> predecessor;
    Graph *g;

    BFS(Graph *g_)
    {
        g = g_;
        clear();
    }

    void clear()
    {
        dist.clear();
        dist.resize(g->n + 1, -1);
        predecessor.clear();
        predecessor.resize(g->n + 1, -1);
    }

    void run(int source)
    {
        queue<int> q;
        q.push(source);
        dist[source] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : g->adj[u])
            {
                if (dist[v] == -1)
                { // Not visited
                    dist[v] = dist[u] + 1;
                    predecessor[v] = u;
                    q.push(v);
                }
            }
        }
    }

    vector<int> get_path(int target)
    {
        if (dist[target] == -1)
        {
            return {}; // Target not reachable
        }
        vector<int> path;
        for (int at = target; at != -1; at = predecessor[at])
        {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        g.add_edge(x, y);
    }

    BFS bfs(&g);
    bfs.run(1); // Starting from node 1

    if (bfs.dist[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path = bfs.get_path(n);
        cout << path.size() << endl;
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
