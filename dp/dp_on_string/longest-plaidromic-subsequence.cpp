https://leetcode.com/problems/longest-palindromic-subsequence/description/


516. Longest Palindromic Subsequence
Medium
8.9K
314
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.




code::-->> 
(reverse the string and find longest common subseques of string and its reverse one)
Explanatio::-->https://takeuforward.org/data-structure/longest-palindromic-subsequence-dp-28/


class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

      for(int i=0;i<=n;i++){
        dp[i][0]=0;
      }
      for(int j=0;j<=m;j++){
        dp[0][j]=0;
      }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
          else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
        }
      }

      return dp[n][m];

    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};


code 2nd:-->
class Solution {
public:
   

    int solve(string s, int start, int end, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        if (s[start] == s[end]) {
            dp[start][end] = 2 + solve(s, start + 1, end - 1, dp);
        } else {
            dp[start][end] = max(solve(s, start + 1, end, dp), solve(s, start, end - 1, dp));
        }

        return dp[start][end];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if(n==1)return 1;
        else
              return solve(s, 0, n - 1, dp);
    }
};


code 3rd::-->
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome of length 1.
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill the dp table in the right order (bottom-up).
        for (int cl = 2; cl <= n; cl++) {
            for (int i = 0; i < n - cl + 1; i++) {
                int j = i + cl - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};



