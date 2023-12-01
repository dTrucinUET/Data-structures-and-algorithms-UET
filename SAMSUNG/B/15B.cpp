#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 100001;
int n, m;
vector<int> adj[MAX];

void topo(vector<int> adj[]) {
  int inDegree[MAX];
  memset(inDegree, MAX, 0);
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      inDegree[v]++;
    }

    cout << endl;
  }

  stack<int> st;
  for (int u = 1; u <= n; u++) {
    if (inDegree[u] == 0) {
      st.push(u);
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

  for (int u : topoSort) {
    cout << u << " ";
  }
}

int main() {

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  topo(adj);

  return 0;
}


