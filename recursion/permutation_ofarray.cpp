https://leetcode.com/problems/permutations/description/
referenceLink::-->>https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

code::==>
#include <vector>

class Solution {
public:
    void permutate(vector<int>& nums, vector<vector<int>>& result, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            permutate(nums, result, index + 1);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutate(nums, result, 0);
        return result;
    }
};
