https://leetcode.com/problems/longest-increasing-subsequence/description/


300. Longest Increasing Subsequence
Medium
18.8K
355
Companies
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


code::(first approach without memo)::-->

class Solution {
public:
int solve(vector<int>&nums,int index,int prev){
if(index==nums.size())return 0;

int count=0;
   if(nums[index]>prev){
       count=max(1+solve(nums,index+1,nums[index]),(0+solve(nums,index+1,prev)));
   }
   else{
       count=solve(nums,index+1,prev);
   }
return count;

}
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>())
        return solve(nums,0,INT_MIN);
    }
};


code with memo:->
class Solution {
public:
int getAns(vector<int>&arr, int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
    
    if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}

    int lengthOfLIS(vector<int>& nums) {
         vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return getAns(nums,nums.size(),0,-1,dp);
    }
};