/*You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.



Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.*/

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &v)
    {
        int ans = 0;

        map<int, int> mp;
        int n = v.size();

        for (auto i : v)
            mp[i]++;

        for (int i = 0; i < n; i++)
        {
            vector<int> count(2001, 0);
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                count[v[j]]++;
                if (count[v[j]] == 1)
                    cnt++;
                if (cnt == mp.size())
                    ans++;
            }
        }
        return ans;
    }
};
another approach::-- -- >>
    int countCompleteSubarrays(vector<int> &nums)
{
    unordered_map<int, int> mp, all;
    for (auto n : nums)
        all[n]++; // put all elements to get the size of discrete elements
    int front = 0, back = 0, ans = 0;
    while (front < nums.size())
    {
        mp[nums[front]]++;
        while (back <= front && mp.size() == all.size())
        {
            if (--mp[nums[back]] == 0)
                mp.erase(nums[back]); // update back pointer and map untill the condition satisfy
            back++;
            ans += (nums.size() - front); // update answer - with number of array possible starting at pointer value of "back"
        }
        front++;
    }
    return ans;
}