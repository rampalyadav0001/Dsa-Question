https://leetcode.com/problems/rotate-string/submissions/
https://leetcode.com/problems/isomorphic-strings/description/
https://leetcode.com/problems/largest-odd-number-in-string/description/

#include <string>

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false; // If the lengths are different, 'goal' cannot be obtained by rotating 's'
        }

        s += s; // Concatenate 's' with itself to cover all possible rotations

        return s.find(goal) != string::npos; // Check if 'goal' is a substring of the concatenated 's'
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};


class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
