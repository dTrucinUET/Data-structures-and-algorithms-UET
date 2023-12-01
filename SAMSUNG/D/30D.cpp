#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> longestPath(const vector<vector<pii>>& graph, int start, int end) {
    int N = graph.size();
    vector<int> dist(N, numeric_limits<int>::min());
    vector<int> prev(N, -1);

    priority_queue<pii> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if (w < dist[u]) {
            continue;
        }

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight > dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }


    vector<int> path;
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = prev[curr];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n);

   for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }

    int start, to;
    cin >> start >> to;
    vector<int> path = longestPath(graph, start, to);

    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
