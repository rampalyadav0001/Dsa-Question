Partition Array for Maximum Sum
https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03


Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1


code::
class Solution {
public:
    // int solve(vector<int>& arr, int k, int index,vector<int>&dp) {
    //     if (index == arr.size()) return 0;
    //     if(dp[index]!=-1)return dp[index];
    //     int res = INT_MIN;
    //     int maxVal = 0;

    //     for (int i = 0; i < k && index + i < arr.size(); ++i) {
    //         maxVal = max(maxVal, arr[index + i]);
    //         res = max(res, maxVal * (i + 1) + solve(arr, k, index + i + 1,dp));
    //     }

    //     return dp[index]=res;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     vector<int>dp(arr.size(),-1);
    //     return solve(arr, k, 0,dp);
    // }
      int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int maxVal = 0;
            for (int j = 1; j <= k && i - j + 1 >= 0; ++j) {
                maxVal = max(maxVal, arr[i - j + 1]);
                int prev = (i - j >= 0) ? dp[i - j] : 0;
                dp[i] = max(dp[i], prev + maxVal * j);
            }
        }

        return dp[n - 1];
    }
};