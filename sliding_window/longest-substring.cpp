https://leetcode.com/problems/longest-repeating-character-replacement/description/


424. Longest Repeating Character Replacement
Solved
Medium
Topics
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.



code::
class Solution {
public:
    int characterReplacement(string s, int k) {
        int right = 0, left = 0;     // Initialize two pointers, 'left' and 'right'.
        vector<int> cnt(26);        // Create a vector to count the occurrences of each character.
        int maxlen = 0;             // Initialize the maximum length of the valid substring.

        while (right < s.size()) {   // Start a loop while 'right' is within the bounds of the string.
            cnt[s[right] - 'A']++;  // Increment the count for the current character at 'right' position.

            while (right - left + 1 - *max_element(cnt.begin(), cnt.end()) > k) {
                // If the length of the current window minus the count of the most frequent character
                // exceeds 'k', we need to shrink the window by moving 'left' pointer to the right.
                cnt[s[left] - 'A']--;  // Decrement the count for the character at 'left' position.
                left++;                // Move 'left' pointer to the right.
            }

            int len = right - left + 1;  // Calculate the length of the current valid substring.
            maxlen = max(maxlen, len);   // Update 'maxlen' if the current length is larger.
            right++;                     // Move 'right' pointer to the right to expand the window.
        } 

        return maxlen;   // Return the maximum length of the valid substring.
    }
};
