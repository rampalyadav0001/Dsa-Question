https://leetcode.com/problems/generate-parentheses/description/


22. Generate Parentheses
Medium
18.9K
762
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


class Solution {
public:
  void solve(int open,int close, int n,vector<string>&ans,string curr ){
      if(curr.length()==2*n){
          ans.push_back(curr);
          return;
      }
      if(open<n) solve(open+1,close,n,ans,curr+"(");
      if(close<open) solve(open,close+1,n,ans,curr+")");
  }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,ans,"");
        return ans;
    }
};