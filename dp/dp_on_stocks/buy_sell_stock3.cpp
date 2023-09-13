https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

123. Best Time to Buy and Sell Stock III
Hard
9K
161
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105



recursive code with comment to explain::-->


class Solution {
public:
    // The solve function is a recursive function that calculates the maximum profit.
    // It takes the following parameters:
    // - arr: The vector of stock prices.
    // - index: The current index in the array.
    // - buy: A flag indicating whether the stock can be bought (1) or not (0).
    // - transaction: The number of remaining transactions allowed.
    // - dp: A 3D memoization table to store previously calculated results.
    int solve(vector<int>& arr, int index, int buy, int transaction, vector<vector<vector<int>>>& dp) {
        // Base case 1: If there are no more transactions left or we have reached the end of the array, return 0.
        if (transaction == 0 || index == arr.size()) {
            return 0;
        }
        
        // If the result for the current state (index, buy, transaction) is already calculated, return it.
        if (dp[index][buy][transaction] != -1) {
            return dp[index][buy][transaction];
        }

        int profit = 0;
        if (buy) {
            // If we can buy, we have two options:
            // 1. Buy the stock and continue with the same transaction (subtract arr[index]).
            // 2. Do not buy and continue with the same transaction.
            // We take the maximum of these two options.
            profit = max((-arr[index] + solve(arr, index, 0, transaction, dp)), (0 + solve(arr, index + 1, 1, transaction, dp)));
        } else {
            // If we cannot buy, we have two options:
            // 1. Sell the stock (add arr[index] to profit) and continue with the other transaction.
            // 2. Do not sell and continue with the same transaction.
            // We take the maximum of these two options.
            profit = max((arr[index] + solve(arr, index + 1, 1, transaction - 1, dp)), (0 + solve(arr, index + 1, 0, transaction, dp)));
        }

        // Store the calculated profit in the memoization table and return it.
        return dp[index][buy][transaction] = profit;
    }

    // The maxProfit function is the entry point of the solution.
    // It initializes the memoization table and starts the recursive calculation.
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1))); // Initialize dp with -1 values.
        // Start the recursive calculation with index 0, the ability to buy (1), and 2 transactions allowed.
        return solve(prices, 0, 1, 2, dp);
    }
};
