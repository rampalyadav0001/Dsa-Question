https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

122. Best Time to Buy and Sell Stock II
Medium
12.4K
2.6K
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104


recursive code with comments::->
class Solution {
public:
  // The solve function is a recursive function that calculates the maximum profit.
  // It takes the following parameters:
  // - arr: The vector of stock prices.
  // - index: The current index in the array.
  // - buy: A flag indicating whether the stock can be bought (1) or not (0).
  // - dp: A 2D memoization table to store previously calculated results.
  int solve(vector<int>& arr, int index, int buy, vector<vector<int>>& dp) {
    // Base case: If we have reached the end of the array, return 0.
    if (index == arr.size()) {
      return 0;
    }
    // If the result for the current state (index, buy) is already calculated, return it.
    if (dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;
    if (buy) {
      // If we can buy, we have two options:
      // 1. Buy the stock and move to the next day (subtract arr[index]).
      // 2. Do not buy and move to the next day.
      // We take the maximum of these two options.
      profit = max((solve(arr, index + 1, 0, dp) - arr[index]), (0 + solve(arr, index + 1, 1, dp)));
    } else {
      // If we cannot buy, we have two options:
      // 1. Sell the stock (add arr[index] to profit) and move to the next day (change buy to 1).
      // 2. Do not sell and move to the next day.
      // We take the maximum of these two options.
      profit = max((arr[index] + solve(arr, index + 1, 1, dp)), (0 + solve(arr, index + 1, 0, dp)));
    }

    // Store the calculated profit in the memoization table and return it.
    return dp[index][buy] = profit;
  }

  // The maxProfit function is the entry point of the solution.
  // It initializes the memoization table and starts the recursive calculation.
  int maxProfit(vector<int>& prices) {
    // Initialize the memoization table with -1 values.
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // Start the recursive calculation with index 0 and the ability to buy (1).
    return solve(prices, 0, 1, dp);
  }
};


iterative code::->
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n-1;i++){
    if(prices[i]<prices[i+1]){
        profit+=prices[i+1]-prices[i];
    }
        }
        return profit;
    }
};