309. Best Time to Buy and Sell Stock with Cooldown
Medium
8.9K
291
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


code::
class Solution {
public:
int solve(vector<int>&arr,int index,int buy,vector<vector<int>>&dp){
      if(index>=arr.size()){
          return 0;
      }
      if(dp[index][buy]!=-1)return dp[index][buy];
int profit=0;
    if(buy){
     profit= max(( solve(arr,index+1,0,dp) -arr[index]),0+solve(arr,index+1,1,dp));
    }
    else{
         profit=max((arr[index]+solve(arr,index+2,1,dp)),(0+solve(arr,index+1,0,dp)));   
    }

return dp[index][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};