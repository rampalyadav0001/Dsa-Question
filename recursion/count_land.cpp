https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.

approach::->
calculate total one and minus thoes one which aare connected to the boundary.

mark all one connected to boundary to zero and count all ramining ones;

code::->
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int row[4]={1,-1,0,0};
  int col[4]={0,0,1,-1};
  void sol(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<bool>>&visited){
      if(i<0||i>=n||j<0||j>=m||grid[i][j]==0||visited[i][j]==true){
          return;
      }
      grid[i][j]=0;
      visited[i][j]=true;
      for(int k=0;k<4;k++){
          int p=i+row[k],q=j+col[k];
          sol(grid,p,q,n,m,visited);
      }
      
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<bool>>visited(n,vector<bool>(m,false));
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if((i==n-1||i==0||j==0||j==m-1)&&grid[i][j]==1){
                  sol(grid,i,j,n,m,visited);
              }
          }
      }
      int count=0;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==1){
                  count++;
              }
          }
      }
      return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends


another approach::-->
// Back-end complete function Template for C++

class Solution {
  public:
    // Function to perform depth-first search to mark all
    // connected 1's as 0's.
    void dfs(int i, int j, vector<vector<int>> &grid) {
        // If the current cell is out of bounds or has already
        // been visited or is a 0, return.
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or
            grid[i][j] == 0) {
            return;
        }

        // Mark the current cell as 0 and recursively call dfs
        // on adjacent cells.
        grid[i][j] = 0;
        dfs(i + 1, j, grid); // down
        dfs(i, j + 1, grid); // right
        dfs(i, j - 1, grid); // left
        dfs(i - 1, j, grid); // up
    }

    // Function to count the number of enclaves.
    int numberOfEnclaves(vector<vector<int>> &grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Perform DFS on all the border cells and mark
        // all the connected 1's as 0's.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 or j == 0 or i == n - 1 or
                    j == m - 1 and grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }

        // Count the remaining 1's in the grid which are
        // not connected to the borders.
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count += grid[i][j];
            }
        }

        // Return the count of enclaves.
        return count;
    }
};