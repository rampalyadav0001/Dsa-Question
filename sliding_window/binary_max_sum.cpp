930. Binary Subarrays With Sum
LINK::-->>https://leetcode.com/problems/binary-subarrays-with-sum/description/
    Medium 2.4K 71 Companies
        Given a binary array nums and an integer goal,
    return the number of non - empty subarrays with a sum goal.

                               A subarray is a contiguous part of the array.

                               Example 1 :

    Input : nums = [ 1, 0, 1, 0, 1 ],
            goal = 2 Output : 4 Explanation : The 4 subarrays are bolded and underlined below : [ 1, 0, 1, 0, 1 ]
                                                                                                    [1, 0, 1, 0, 1]
                                                                                                    [1, 0, 1, 0, 1]
                                                                                                    [1, 0, 1, 0, 1]Example 2 :

    Input : nums = [ 0, 0, 0, 0, 0 ],
            goal = 0 Output : 15

                   sol using hashMap::-- >>
                   reference video link::-- >> https://www.youtube.com/watch?v=20v8zSo2v18
                                                       class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> mp;
        int prefixsum = 0;
        mp[0] = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixsum += nums[i];
            int rsum = prefixsum - goal; // here we check lets suppose 0 se 5 index tuk ka sum x ha and 0 se 10 tuk ka sum x+k hai(k is target sum)  than hamara target sum 5 se 10 index ke beech lie karega .
            if (mp.find(rsum) != mp.end())
            {
                ans += mp[rsum];
            }

            mp[prefixsum]++;
        }

        return ans;
    }
};

sliding window approach::-- >
    no of subarray of sum k = no.of subarray of sum at most k - no.of subarray of sum atmost k - 1;

no.of subarray is == size of the window
                             ie..no.of subarray possible btween index 1 to 5 is 5 -
                         1 + 1 = 5({
                                       nums[1],
                                   },
                                   {nums[1], nums[2]}, {nums[1], nums[2], nums[3]}, {nums[1], nums[2], nums[3], nums[4]}, {nums[1], nums[2], nums[3], nums[4], nums[5]})

    class Solution
{
public:
    int atmostsum(vector<int> &nums, int goal)
    {
        int left = 0, right = 0;
        int sum = 0, ans = 0;
        while (right < nums.size())
        {
            sum += nums[right++];
            while (left < right && sum > goal)
            {
                sum -= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmostsum(nums, goal) - atmostsum(nums, goal - 1);
    }
};
