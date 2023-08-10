link::-->>https://practice.geeksforgeeks.org/problems/word-boggle4143/1?page=1&difficulty[]=1&category[]=Recursion&sortBy=submissions

code::-->>
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    bool dfs(vector<vector<bool>>& visited, vector<vector<char>>& board, string word, int row, int col, int i, int j, int index) {
        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] == true || word[index] != board[i][j]) {
            return false;
        }
        if (index == word.length() - 1) return true;
        if (index >= word.length()) return false;
        visited[i][j] = true;
        for (int k = 0; k < 8; k++) {
            int p = i + dx[k], q = j + dy[k];
            bool result = dfs(visited, board, word, row, col, p, q, index + 1);
            if (result == true) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int row, int col) {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    bool result = dfs(visited, board, word, row, col, i, j, 0);
                    if (result == true) return true;
                }
            }
        }
        return false; // Placed outside the loop
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        vector<string> ans;
        int row = board.size();
        int col = board[0].size();

        for (auto it : dictionary) {
            bool result = search(board, it, row, col);
            if (result == true) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends



Word Boggle
MediumAccuracy: 15.85%Submissions: 75K+Points: 4
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters

Note: While forming a word we can move to any of the 8 adjacent cells. A cell can be used only once in one word.


Example 1:

Input: 
N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
Output:
CAT
Explanation: 
C A P
A N D
T I E
Words we got is denoted using same color.
Example 2:

Input:
N = 4
dictionary = {"GEEKS","FOR","QUIZ","GO"}
R = 3, C = 3 
board = {{G,I,Z},{U,E,K},{Q,S,E}}
Output:
GEEKS QUIZ
Explanation: 
G I Z
U E K
Q S E 
Words we got is denoted using same color.