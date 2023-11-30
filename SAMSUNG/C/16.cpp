#include <bits/stdc++.h>
using namespace std;

void prim(int V, int E, vector<pair<int, int>> graph[]) {
    bool visited[V + 1]{false};
    // pririty_queue phiên bản sort từ bé đến lớn
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int dis[V + 1]{INT_MAX};
    int res = 0;

    // Thay vì prim đỉnh bắt đầu như thường thì ta sẽ prim từng đỉnh một nếu nó chưa được thăm
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dis[i] = 0;
            q.push(make_pair(0, i));
        }
        else
            continue;

        // Prim như thường lệ
        while (!q.empty()) {
            pair<int, int> top = q.top();
            q.pop();
            int curDis = top.first;
            int u = top.second;
            if (visited[u])
                continue;

            visited[u] = true;
            res += curDis;
            for (auto v : graph[u]) {
                if (!visited[v.second])
                    q.push(make_pair(v.first, v.second));
            }
        }
    }

    cout << res << endl;
}

// Phần này để cho kruscal
int find_par(int u, int parent[])
{
    if (u != parent[u])
        parent[u] = find_par(parent[u], parent);
    return parent[u];
}

void union_par(int u, int v, int parent[])
{
    int par_u = find_par(u, parent);
    int par_v = find_par(v, parent);
    parent[par_u] = parent[par_v];
}

void kruscal(int parent[], vector<pair<int, pair<int, int>>> G) {
    int res = 0;
    int par_u, par_v;
    sort(G.begin(), G.end());
    for (auto v : G) {
        par_u = find_par(v.second.first, parent);
        par_v = find_par(v.second.second, parent);
        if (par_u != par_v) {
            res += v.first;
            union_par(par_u, par_v, parent);
        }
    }
    cout << res;
}

int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int V, E;
    cin >> V >> E;
    int u, v, w;
    vector<pair<int, int>> graph[E + 1]; // Là đồ thị sinh cho prim
    vector<pair<int, pair<int, int>>> G; // Là đồ thị sinh cho kruscal
    int parent[V + 1]; // Dành cho kruscal

    for (int i = 1; i <= V; i++)
        parent[i] = i;
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
        G.push_back(make_pair(w, make_pair(u, v)));
        G.push_back(make_pair(w, make_pair(v, u)));
    }
    prim(V, E, graph);
    kruscal(parent, G);
    return 0;
}
