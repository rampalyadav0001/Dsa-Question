link::-->https://leetcode.com/problems/palindrome-partitioning/description/

code::-->
class Solution {
public:
 bool palidrome(string str,int s,int e){
   
     while(s<=e){
         if(str[s]!=str[e])return false;

         s++;
         e--;
     }
     return true;
 }
 void solve(string s,vector<vector<string>>&ds,vector<string>&ans,int index){
  if (index==s.size()){
      ds.push_back(ans);
      return;
  }
     for(int i=index;i<s.length();i++){
         if(palidrome(s,index,i)){
             ans.push_back(s.substr(index,i-index+1));
             solve(s,ds,ans,i+1);
             ans.pop_back();
         }
     }

 }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ds;
        vector<string>ans;
        string str="";
        solve(s,ds,ans,0);
        return ds;
    }
};