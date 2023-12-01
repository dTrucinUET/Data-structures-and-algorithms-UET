#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;
};

class Graph {
    int V; // Số lượng đỉnh
    vector<Edge> edges; // Danh sách các cạnh

public:
    Graph(int V) : V(V) {}

    void addEdge(int source, int destination, int weight) {
        Edge edge = {source, destination, weight};
        edges.push_back(edge);
    }

    // Hàm tìm gốc của đỉnh i trong cây bao trùm nhỏ nhất
    int findRoot(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return findRoot(parent, parent[i]);
    }

    // Hàm gộp hai cây có gốc là root1 và root2
    void unionTrees(vector<int>& parent, vector<int>& rank, int root1, int root2) {
        if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }

    // Hàm tìm cây bao trùm nhỏ nhất bằng thuật toán Vyssotsky
    void vyssotskyMST() {
        vector<Edge> mst; // Danh sách các cạnh trong cây bao trùm nhỏ nhất
        vector<int> parent(V); // Danh sách cha của các đỉnh
        vector<int> rank(V, 0); // Danh sách rank của các đỉnh

        // Khởi tạo danh sách cha, ban đầu mỗi đỉnh đều là cha của chính nó
        for (int i = 0; i < V; i++)
            parent[i] = i;

        // Sắp xếp các cạnh theo trọng số tăng dần
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        // Duyệt qua từng cạnh
        for (const Edge& edge : edges) {
            int root1 = findRoot(parent, edge.source);
            int root2 = findRoot(parent, edge.destination);

            // Nếu cạnh không tạo chu trình
            if (root1 != root2) {
                // Thêm cạnh vào cây bao trùm nhỏ nhất
                mst.push_back(edge);
                // Gộp hai cây lại
                unionTrees(parent, rank, root1, root2);
            }
        }

        // In cây bao trùm nhỏ nhất
        cout << "Cay bao trum nho nhat:\n";
        for (const Edge& edge : mst) {
            cout << edge.source << ' ';
        }
    }
};

int main() {
    int n, m; // Số lượng đỉnh và cạnh
    cin >> n >> m;

    Graph graph(n);

    // Nhập thông tin về các cạnh
    for (int i = 0; i < m; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    // Tính cây bao trùm nhỏ nhất bằng thuật toán Vyssotsky
    graph.vyssotskyMST();

    return 0;
}
