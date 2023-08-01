560. Subarray Sum Equals K
Medium
19.2K
565
Companies
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
question Link::-->https://leetcode.com/problems/subarray-sum-equals-k/description/
reference video link::-- >> https://www.youtube.com/watch?v=20v8zSo2v18


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int res=sum-k;
            if(mp.find(res)!=mp.end()){
                ans+=mp[res];
            }
            mp[sum]++;
        }
        return ans;
    }
};