
link::-->https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
 code:::-->>(working properly)
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    void solve(vector<vector<int>>& board, int n, vector<string>& result, string ans, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] == 0) {
            return;
        }

        if (i == n - 1 && j == n - 1) {
            result.push_back(ans);
            return;
        }
        
        int originalValue = board[i][j];
        board[i][j] = 0;  // Mark the cell as visited
        
        solve(board, n, result, ans + 'D', i + 1, j);
        solve(board, n, result, ans + 'R', i, j + 1);
        solve(board, n, result, ans + 'L', i, j - 1);
        solve(board, n, result, ans + 'U', i - 1, j);
        
        board[i][j] = originalValue;  // Backtrack by restoring the original value
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> result;
        string ans = "";
        solve(m, n, result, ans, 0, 0);
        return result;
    }
};

first approach but doesn't explore all path';
code::-->>
class Solution {
public:
    bool solve(vector<vector<int>>& board, int n, vector<string>& result, string ans, int i, int j) {
        if (i == n - 1 && j == n - 1) {
            result.push_back(ans);
            return true;
        }
        if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] == 0) {
            return false;
        }
        int temp = board[i][j];
        board[i][j] = 0; // Mark the cell as visited
        
        // Check if any of the directions lead to a valid path
        bool foundPath = solve(board, n, result, ans + 'L', i, j - 1) ||
                         solve(board, n, result, ans + 'R', i, j + 1) ||
                         solve(board, n, result, ans + 'D', i + 1, j) ||
                         solve(board, n, result, ans + 'U', i - 1, j);
        
        board[i][j] = temp; // Restore the cell value after backtracking
        
        return foundPath;
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> result;
        string ans = "";
        if (solve(m, n, result, ans, 0, 0)) {
            return result;
        } else {
            return {"-1"}; // Return -1 if a valid path is not found
        }
    }
};


another approach::
class Solution{
    public:
    void solve(vector<vector<int>>&board,int n,vector<string>&result,string ans,int i,int j,vector<vector<int>>&visited){
        if(i==n-1&&j==n-1){
            result.push_back(ans);
            return;
        }
        //down move
        if(i+1<n&&board[i][j]==1&&visited[i][j]==0){
            visited[i][j]=1;
            solve(board,n,result,ans+'D',i+1,j,visited);
            visited[i][j]=0;
        }
        //right move
         if(j+1<n&&board[i][j]==1&&visited[i][j]==0){
             visited[i][j]=1;
            solve(board,n,result,ans+'R',i,j+1,visited);
            visited[i][j]=0;
        }
        //left move
         if(j-1>=0&&board[i][j]==1&&visited[i][j]==0){
            visited[i][j]=1;
            solve(board,n,result,ans+'L',i,j-1,visited);
           visited[i][j]=0;
        }
        //up move
         if(i-1>=0&&board[i][j]==1&&visited[i][j]==0){
           visited[i][j]=1;
            solve(board,n,result,ans+'U',i-1,j,visited);
            visited[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>visited(n,vector<int>(n,0));
       vector<string>result;
       string ans="";
       solve(m,n,result,ans,0,0,visited);
       return result;
       
    }
};



extended version of previous code::-->
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    bool solve(vector<vector<int>>& board, int n, vector<string>& result, string ans, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] == 0) {
            return false;
        }

        if (i == n - 1 && j == n - 1) {
            result.push_back(ans);
            return true;
        }

        int originalValue = board[i][j];
        board[i][j] = 0;  // Mark the cell as visited

        bool foundPath = false;
        if (solve(board, n, result, ans + 'D', i + 1, j) ||
            solve(board, n, result, ans + 'R', i, j + 1) ||
            solve(board, n, result, ans + 'L', i, j - 1) ||
            solve(board, n, result, ans + 'U', i - 1, j)) {
            foundPath = true;
        }

        board[i][j] = originalValue;  // Backtrack by restoring the original value
        return foundPath;
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> result;
        string ans = "";
        if (solve(m, n, result, ans, 0, 0)) {
            return result;
        } else {
            result.clear();
            result.push_back("-1");
            return result;
        }
    }
};
