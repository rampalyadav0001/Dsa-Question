https://leetcode.com/problems/edit-distance/description/



72. Edit Distance
Medium
13.7K
173
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.




code::(recursive+tabulation)::-->
class Solution {
public:
int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
    if(j==0)return i;
    if(i==0)return j;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1])return solve(s1,s2,i-1,j-1,dp);
    else{
        return min((1+solve(s1,s2,i-1,j,dp)),min((1+solve(s1,s2,i,j-1,dp)),(1+solve(s1,s2,i-1,j-1,dp))));
    }
}
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // return solve(word1,word2,word1.length(),word2.length(),dp);
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=0+dp[i-1][j-1];
                else{
                    dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
      return dp[n][m];
    }
};



recursive code::->(memoryLimit Excedeed)
class Solution {
public:
int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
    if(j<0)return i+1;
    if(i<0)return j+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return solve(s1,s2,i-1,j-1,dp);
    else{
        return min((1+solve(s1,s2,i-1,j,dp)),min((1+solve(s1,s2,i,j-1,dp)),(1+solve(s1,s2,i-1,j-1,dp))));
    }
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,word1.length()-1,word2.length()-1,dp);
    }
};


recursive code with shifting value of i and j::-->
class Solution {
public:
int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
    if(j==0)return i;
    if(i==0)return j;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1])return solve(s1,s2,i-1,j-1,dp);
    else{
        return min((1+solve(s1,s2,i-1,j,dp)),min((1+solve(s1,s2,i,j-1,dp)),(1+solve(s1,s2,i-1,j-1,dp))));
    }
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,word1.length(),word2.length(),dp);

    }
};