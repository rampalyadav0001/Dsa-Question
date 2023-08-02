https://leetcode.com/problems/reverse-words-in-a-string/description/

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.



Approach: first reverse the whole string than start from 1st postion and when a space hit reverse the word;


code::-->>
#include <string>

class Solution {
public:
    void reverse(string &s, int start, int end) {
        while (start <= end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        reverse(s, 0, s.length() - 1);
        int i = 0, j = 0;
        while (j < s.length()) {
            while (s[j] != ' ' && j < s.length()) {
                j++;
            }
            reverse(s, i, j - 1);
            i = j + 1;
            j++;
        }

        // Remove extra spaces
        int newSize = 0;
        for (i = 0, j = 0; j < s.length();) {
            if (s[j] == ' ' && (j == 0 || s[j - 1] == ' ')) {
                j++;
            } else {
                s[i] = s[j];
                i++;
                j++;
            }
        }
        s.resize(i);
          while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        return s;
    }
};
