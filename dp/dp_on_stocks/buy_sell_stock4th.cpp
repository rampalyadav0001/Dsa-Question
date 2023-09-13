https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/


188. Best Time to Buy and Sell Stock IV
Hard
7K
201
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 


 code::
 class Solution {
public:
int solve(vector<int>&arr,int index,int buy,int transation,vector<vector<vector<int>>>&dp){
    if(transation==0||index==arr.size())return 0;
    if(dp[index][buy][transation]!=-1)return dp[index][buy][transation];

    if(buy){
   return  dp[index][buy][transation]=max((-arr[index]+solve(arr,index+1,0,transation,dp)),(0+solve(arr,index+1,1,transation,dp)));
    }
    else{
 return dp[index][buy][transation]=max((arr[index]+solve(arr,index+1,1,transation-1,dp)),(0+solve(arr,index+1,0,transation,dp)));
    }

}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};