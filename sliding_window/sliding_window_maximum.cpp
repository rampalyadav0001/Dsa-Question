239. Sliding Window Maximum
Hard
15.3K
505
Companies
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]

Link:::-->https://leetcode.com/problems/sliding-window-maximum/description/


hint::--->>
How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window’s size.
Remove redundant elements and the queue should store only elements that need to be considered.



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // Using a deque to efficiently handle sliding window max

        vector<int> result;

        // Handling the first window
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        result.push_back(nums[q.front()]);

        // Handling the rest of the windows
        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front(); // Remove elements that are no longer in the current window
            }

            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back(); // Remove smaller elements as they won't be the maximum anymore
            }

            q.push_back(i);
            result.push_back(nums[q.front()]);
        }

        return result;
    }
};
