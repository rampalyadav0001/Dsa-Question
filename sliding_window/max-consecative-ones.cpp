https://leetcode.com/problems/max-consecutive-ones-iii/

Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

code::-->
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right = 0, left = 0;   // Initialize two pointers, 'left' and 'right'.
        int maxlen = 0;           // Initialize the maximum length of subarray.

        while (right < nums.size()) {
            if (nums[right] == 0) {
                k--;              // Decrement 'k' when encountering a zero.
            }

            while (k < 0) {       // If 'k' becomes negative, adjust the window by moving 'left'.
                if (nums[left] == 0) {
                    k++;          // Increment 'k' when moving 'left' if it was pointing to a zero.
                }
                left++;           // Move 'left' to shrink the window.
            }

            int len = right - left + 1;   // Calculate the length of the current subarray.
            maxlen = max(maxlen, len);    // Update 'maxlen' if the current length is larger.
            right++;                      // Move 'right' to expand the window.
        }

        return maxlen;  // Return the maximum length of subarray with at most 'k' zeros.
    }
};
