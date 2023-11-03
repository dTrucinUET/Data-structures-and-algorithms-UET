#include<iostream>

using namespace std;

int LCS(int m, int n, int a[], int b[]) {
    int solutinon[m + 1][n + 1];

    for (int i = 0; i <= m; i ++) {
        for (int j = 0; j <= n; j ++) {
            if (i == 0 || j == 0) {
                solutinon[i][j] = 0;
            } else {
                if (a[i - 1] == b[j - 1]) {
                solutinon[i][j] = solutinon[i - 1][j - 1] + 1;
                } else {
                    solutinon[i][j] = max(solutinon[i - 1][j], solutinon[i][j - 1]);
                }
            }
        }
    }
    return solutinon[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for (int i = 0; i < m; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    cout << "Day con chung dai nhat: " << LCS(m, n, a, b);
    return 0;
}
