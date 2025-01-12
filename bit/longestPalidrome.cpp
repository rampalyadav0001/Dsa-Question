https://www.geeksforgeeks.org/problems/longest-substring-whose-character-rearranged-can-form-a-palindrome/1

Longest substring to form a Palindrome
Difficulty: HardAccuracy: 42.22%Submissions: 8K+Points: 8
Given a string S which only contains lowercase alphabets. Find the length of the longest substring of S such that the characters in it can be rearranged to form a palindrome.


Example 1:

Input:
S = "aabe"
Output:
3
Explanation:
The substring "aab" can be rearranged to
"aba" which is the longest palindrome
possible for this String.



class Solution {
public:
    int longestSubstring(string S) {
        int mask = 0;
        unordered_map<int, int> mp;
        mp[mask] = -1; // Start with an initial mask at index -1
        int maxlength = 0;
        
        for (int i = 0; i < S.size(); i++) {
            // Calculate the bit position corresponding to the current character
            int bit = S[i] - 'a';
            mask ^= (1 << bit);  // Toggle the bit corresponding to the character
            
            // If the current mask has been seen before, calculate the length
            if (mp.find(mask) != mp.end()) {
                maxlength = max(maxlength, i - mp[mask]);
            } else {
                mp[mask] = i;  // Store the first occurrence of this mask
            }
            
            // Check for all possible masks where exactly one bit differs
            for (int j = 0; j < 26; j++) {
                int newmask = mask ^ (1 << j);
                if (mp.find(newmask) != mp.end()) {
                    maxlength = max(maxlength, i - mp[newmask]);
                }
            }
        }
        return maxlength;
    }
};
