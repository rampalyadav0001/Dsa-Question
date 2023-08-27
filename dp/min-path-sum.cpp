LInk::-->https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1


code::-->>
#include <bits/stdc++.h> 

int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp) {
    if (i == m - 1 && j == n - 1) {
        return grid[i][j];
    }
    if ( i >= m || j >= n) {
        return INT_MAX;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int right = solve(grid, i, j + 1, m, n, dp);
    int down = solve(grid, i + 1, j, m, n, dp);
    
    int ans = grid[i][j]+min(right, down);
    
    return dp[i][j] = ans;
}

int minSumPath(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    return solve(grid, 0, 0, row, col, dp);
}
