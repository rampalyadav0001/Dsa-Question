https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/
Maximum Value of an Ordered Triplet II
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
 

 code::-->
 // #include "bits/stdc++.h"
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size(); // Get the size of the input vector
    
        vector<long long> max1(n), max2(n); // Initialize two vectors to store maximum values
        max1[0] = -1; // Set the first element of max1 to -1
        // Loop through the input vector from the second element to the end
        for(long long i = 1; i < n; i++){
            // Store the maximum value between the current maximum and the previous element of the input vector
            max1[i] = max(max1[i-1],(long long) nums[i-1]);
        }
        max2[n-1] = -1; // Set the last element of max2 to -1
        // Loop through the input vector from the second last element to the beginning in reverse order
        for(long long i = n - 2; i >= 0; i--){
            // Store the maximum value between the current maximum and the next element of the input vector
            max2[i] = max(max2[i+1], (long long)nums[i+1]);
        }
        long long maxi = 0; // Initialize a variable to store the maximum triplet value
        // Loop through the input vector from the second element to the second last element
        for(long long j = 1; j < n-1; j++){
            // Calculate the triplet value for each element and store it if it's greater than the current maximum
            long long temp = (long long)(max1[j] - nums[j]) * max2[j];
            maxi = max(maxi,temp);
        }
        return maxi; // Return the maximum triplet value
    }
};
