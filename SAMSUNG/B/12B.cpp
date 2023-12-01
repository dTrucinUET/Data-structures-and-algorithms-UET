#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Hàm tính sắp xếp tô pô của đồ thị
vector<int> topologicalSort(vector<vector<int>>& adj) {
  int n = adj.size();
  vector<int> inDegree(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      inDegree[j]++;
    }
  }

  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
      st.push(i);
    }
  }

  vector<int> topoSort;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    topoSort.push_back(u);

    for (int v : adj[u]) {
      inDegree[v]--;
      if (inDegree[v] == 0) {
        st.push(v);
      }
    }
  }

  return topoSort;
}


bool has(vector<vector<int>>& adj) {
  vector<int> topoSort = topologicalSort(adj);

  for (int i = 1; i < topoSort.size(); i++) {
    if (!adj[topoSort[i - 1]][topoSort[i]]) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }


  if (has(adj)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
