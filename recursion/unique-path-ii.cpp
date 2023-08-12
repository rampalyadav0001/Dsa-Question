Link::-->https://leetcode.com/problems/unique-paths-ii/description/
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

solution without using dp(give tle)::->
class Solution {
public:
    void solve(vector<vector<int>>&grid,int i,int j,int m,int n,int&count){
      if(j<0||j>=n||i<0||i>=m||grid[i][j]==1){
          return;
      }
      if(i==m-1&&j==n-1){
          count++;
          return;
      }
      grid[i][j]=1;//this is for back tracking but here it not neccessary very much ;
      solve(grid,i+1,j,m,n,count);
      solve(grid,i,j+1,m,n,count);
      grid[i][j]=0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        int count=0;
        solve(obstacleGrid,0,0,row,col,count);
        return count;
    }
};


solution using dp::-->
