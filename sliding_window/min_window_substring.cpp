/*Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;
        for (auto it : t)
        {
            mp[it]++;
        }
        int ans = INT_MAX, st = 0;
        int left = 0, right = 0, count = mp.size();
        while (right < s.length())
        {
            mp[s[right]]--;
            if (mp[s[right]] == 0)
            {
                count--;
            }
            if (count == 0)
            {
                while (count == 0)
                {
                    if ((right - left + 1) < ans)
                    {
                        ans = right - left + 1;
                        st = left;
                    }

                    mp[s[left]]++;
                    if (mp[s[left]] > 0)
                    {
                        count++;
                    }
                    left++;
                }
            }
            right++;
        }
        if (ans == INT_MAX)
            return "";
        else
            return s.substr(st, ans);
    }
};