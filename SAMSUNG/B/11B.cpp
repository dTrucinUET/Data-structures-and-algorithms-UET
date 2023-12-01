#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 100001;
int n, m;
vector<int> adj[MAX];

bool hasHamiltonianPath(vector<int> adj[]) {
  int inDegree[MAX];
  memset(inDegree, MAX, 0);
  for (int u = 1; u <= n; u++) {
    //cout << u << " : ";
    for (int v : adj[u]) {
      //cout << v << ' ';
      inDegree[v]++;
      //cout << " in " << v << ' ' << inDegree[v];
    }

    cout << endl;
  }

  stack<int> st;
  for (int u = 1; u <= n; u++) {
    if (inDegree[u] == 0) {
      st.push(u);
    }
  }
  //cout << "stack: " << st.empty() << endl;
  vector<int> topoSort;
  while (!st.empty()) {
    //cout << "run\n";
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

  for (int i = 1; i < topoSort.size(); i++) {
    cout << i << ' ';
    if (!adj[topoSort[i - 1]][topoSort[i]]) {
      return false;
    }
  }

  return true;
}

int main() {

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  bool hasPath = hasHamiltonianPath(adj);
  if (hasPath) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

