#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> shortestPath(const vector<vector<pii>>& graph, int start, const vector<int>& targets) {
    int N = graph.size();
    vector<int> dist(N, numeric_limits<int>::max());
    vector<int> prev(N, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if (w > dist[u]) {
            continue;
        }

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }

    int minDist = numeric_limits<int>::max();
    int targetVertex = -1;
    for (int target : targets) {
        if (dist[target] < minDist) {
            minDist = dist[target];
            targetVertex = target;
        }
    }

    vector<int> path;
    int curr = targetVertex;
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

    int start, ends;
    cin >> start >> ends;
    vector <int> to;
    for (int i = 0; i < ends; i++) {
        int x;
        cin >> x;
        to.push_back(x);
    }

    vector<int> path = shortestPath(graph, start, to);

    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
