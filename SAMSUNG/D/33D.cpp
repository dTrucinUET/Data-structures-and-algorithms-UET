#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumPathSum(vector<vector<int>>& mat) {
    int N = mat.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[0][0] = mat[0][0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + mat[i][0];
    }

    for (int j = 1; j < N; j++) {
        dp[0][j] = dp[0][j-1] + mat[0][j];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + mat[i][j];
        }
    }

    return dp[N-1][N-1];
}

int main() {
    vector<vector<int>> matrix;
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        vector <int> tmp;
        for (int j = 0; j < col; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        matrix.push_back(tmp);
    }
    int result = minimumPathSum(matrix);
    cout << result << endl;

    return 0;
}
