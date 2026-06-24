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

class CycleDetection
{
public:
    Graph *g;
    vector<bool> visited;
    vector<int> parent;
    vector<int> cycle_path;
    int cycle_start, cycle_end;

    CycleDetection(Graph *g_)
    {
        g = g_;
        visited.resize(g->n + 1, false);
        parent.resize(g->n + 1, -1);
        cycle_start = -1;
    }

    bool dfs(int v, int par)
    {
        visited[v] = true;
        for (int u : g->adj[v])
        {
            if (u == par)
                continue; // Skip the edge back to parent
            if (visited[u])
            {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            parent[u] = v;
            if (dfs(u, v))
                return true;
        }
        return false;
    }

    bool detect_cycle()
    {
        for (int v = 1; v <= g->n; ++v)
        {
            if (!visited[v] && dfs(v, -1))
            {
                return true;
            }
        }
        return false;
    }

    vector<int> get_cycle_path()
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
        {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }

    CycleDetection cycle_detector(&g);
    if (cycle_detector.detect_cycle())
    {
        vector<int> cycle_path = cycle_detector.get_cycle_path();
        cout << cycle_path.size() << endl;
        for (int node : cycle_path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
