https://leetcode.com/problems/number-of-good-pairs/description/?envType=daily-question&envId=2023-10-03

1512. Number of Good Pairs
Easy
4.3K
206
Companies
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

approach:-->
Count how many times each number appears. If a number appears n times, then n * (n – 1) // 2 good pairs can be made with this number.


code:->
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp)count+=((it.second*(it.second-1))/2);
        return count;
    }
};

Another Question with same approach:
https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/submissions/
2001. Number of Pairs of Interchangeable Rectangles
Medium
448
35
Companies
You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.

Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).

Return the number of pairs of interchangeable rectangles in rectangles.

 

Example 1:

Input: rectangles = [[4,8],[3,6],[10,20],[15,30]]
Output: 6
Explanation: The following are the interchangeable pairs of rectangles by index (0-indexed):
- Rectangle 0 with rectangle 1: 4/8 == 3/6.
- Rectangle 0 with rectangle 2: 4/8 == 10/20.
- Rectangle 0 with rectangle 3: 4/8 == 15/30.
- Rectangle 1 with rectangle 2: 3/6 == 10/20.
- Rectangle 1 with rectangle 3: 3/6 == 15/30.
- Rectangle 2 with rectangle 3: 10/20 == 15/30.

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
       unordered_map<double,int> mp;
       int n = rectangles.size();
       for (int i = 0; i < n; i++) {
           mp[((double)(rectangles[i][0]) / (double)(rectangles[i][1]))]++;
       } 
       long long count = 0; 
       for (auto it : mp) {
           count += ((it.second * (long long)(it.second - 1)) / 2);
       }
       return count;
    }
};
