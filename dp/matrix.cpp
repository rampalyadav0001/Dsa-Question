link::-->https://leetcode.com/problems/01-matrix/submissions/


code::-->

this is bfs approach to travase a matrix;;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> result(row, vector<int>(col, -1));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {  // Fix: Change "i" to "j" here
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            for (auto d : dir) {
                int newx = front.first + d.first;
                int newy = front.second + d.second;
                if (newx >= 0 && newx < row && newy >= 0 && newy < col && result[newx][newy] == -1) {
                    result[newx][newy] = 1 + result[front.first][front.second];
                    q.push({newx, newy});
                }
            }
        }

        return result;
    }
};
