#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct Graph {
    int n, m;
    vector<int> adj[10001];
    int in[100001], out[100001];
    bool visited[100001];

    Graph(int n, int m)  {
        this->n = n;
        this->m = m;
        memset(in, 100001, 0);
        memset(out, 100001, 0);
        memset(visited, 100001, false);
    }

    void printGraph() {
        for (int i = 1; i <= n; i++) {
            cout << i << " : ";
                for (int j = 0; j < adj[i].size(); j ++)  {
                    cout << adj[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void addEdge(int u, int  v) {
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }

    void dfs(Graph& g, int u) {
        g.visited[u] = true;
            for (int v : g.adj[u]) {
                if (!g.visited[v]) {
                    dfs(g, v);
                }
            }
    }
};


bool hasEulerCycle(Graph& g) {
    g.dfs(g, 1);
    for  (int u = 1; u <= g.n; u++)  {
        if (g.in[u] != g.out[u] || !g.visited[u]) {
            return false;
        }
    }
    return true;
}
void EulerCycle(Graph& g) {
    if (!hasEulerCycle(g)) {
        cout << "1 :Khong co chu trinh";
        return;
    }

    vector<int> cycle;
    int u = 1;
    queue<int> q;

    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cycle.push_back(v);

        while (g.adj[v].size() > 0) {
            int w = g.adj[v].back();
            g.adj[v].pop_back();
            q.push(w);
        }
    }

    if (cycle.size() <= g.n) {
        cout << cycle.size() << " 2: Khong co chu trinh";
        return;
    }
    cout << "chu trinh: ";
    for (int i : cycle) {
        cout << i << ' ';
    }
}


int  main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    //g.printGraph();
    EulerCycle(g);

    return  0;
}
