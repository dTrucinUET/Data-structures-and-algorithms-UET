#include <bits/stdc++.h>

using namespace std;

int n, m;
bool vistited[10000001];

void DFS(int u, vector <int> adj[]) {
    vistited[u] = true;
    for (int v : adj[u]) {
        if (!vistited[v]) {
            DFS(v, adj);
        }
    }
}

void BFS(int u, vector <int> adj[]) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        vistited[v] = true;
        q.pop();
        for (int x : adj[v]) {
            if (!vistited[x]) {
                q.push(x);
            }
        }
    }
}

int connectedComponents(vector <int> adj[]) {
    int cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (!vistited[v]) {
            cnt++;
            DFS(v, adj); //duyet bang tim kiem theo chieu sau
            //BFS(v, adj);   //duyet bang tim kiem theo chieu rong
        }
    }
    return cnt;
}

int main() {
    memset(vistited, false, sizeof(vistited));
    vector <int> adj[10001];
    cin >> n >> m;
    int tmp[m + 1][2];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        tmp[i][0] = x;
        tmp[i][1] = y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int x = tmp[i][0];
        int y = tmp[i][1];

        auto it1 = find(adj[x].begin(), adj[x].end(), y);
        auto it2 = find(adj[y].begin(), adj[y].end(), x);

        adj[x].erase(it1);
        adj[y].erase(it2);

        int t = connectedComponents(adj);

        if (t > 1) {
            cout << "khong la do thi lien thong canh";
            return 0;
        }

        memset(vistited, false, sizeof(vistited));
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "lien thong canh";

    return 0;
}
