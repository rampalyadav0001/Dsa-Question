Longest Palindrome in a String
Difficulty: MediumAccuracy: 23.2%Submissions: 301K+Points: 4
Given a string str, find the longest palindromic substring in str. Substring of string str: str[ i . . . . j ] where 0 ≤ i ≤ j < len(str). Return the longest palindromic substring of str.

Palindrome string: A string that reads the same backward. More formally, str is a palindrome if reverse(str) = str. In case of conflict, return the substring which occurs first ( with the least starting index).

Examples :

Input: str = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic substring is "aabbaa".


solution 1:->
class Solution {
public:
bool isPalidrome(string &s,int start,int end){
      while(start<=end){
          if(s[start]!=s[end])return false;
          start++;
          end--;
      }
      return true;
  }
    string longestPalindrome(string S) {
         int maxlength=0;
        int start=0;
        for(int i=0;i<S.size();i++){
            for(int j=i;j<S.size();j++){
                if(isPalidrome(S,i,j)&&j-i+1>maxlength){
                    maxlength=j-i+1;
                    start=i;
                }
            }
        }
        return S.substr(start,maxlength); 
    }
};

solution 2:->
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // dp[i][j] will be true if substring s[i..j] is a palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int start = 0;  // The starting index of the longest palindrome
        int maxlen = 1; // The maximum length of the palindrome found so far

        // Single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                maxlen = 2;
            }
        }

        // Check for substrings of length greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;

                // Check if the current substring s[i..j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if (len > maxlen) {
                        start = i;
                        maxlen = len;
                    }
                }
            }
        }

        // Return the longest palindrome substring
        return s.substr(start, maxlen);
    }
};


solution 3:->
class Solution {
public:
    // Function to expand around the center and return the length of the palindrome
    int expendAroundCenter(string& S, int left, int right) {
        while (left >= 0 && right < S.size() && S[left] == S[right]) {
            left--;
            right++;
        }
        // Length of the palindrome is (right - left - 1)
        return right - left - 1;
    }

    string longestPalin(string S) {
        if (S.empty()) return "";
        
        int maxlength = 0;
        int start = 0;

        for (int i = 0; i < S.size(); i++) {
            // Odd-length palindromes (centered at i)
            int oddLength = expendAroundCenter(S, i, i);
            
            // Even-length palindromes (centered between i and i+1)
            int evenLength = expendAroundCenter(S, i, i + 1);

            // Get the maximum length palindrome
            int length = max(oddLength, evenLength);

            // If we found a longer palindrome, update start and maxlength
            if (length > maxlength) {
                maxlength = length;
                start = i - (length - 1) / 2;
            }
        }

        // Return the longest palindrome substring
        return S.substr(start, maxlength);
    }
};

solution 4:->
class Solution {
public:
    string longestPalindrome(string s) {
     int n=s.length();
     int maxlen=1;
     int start=0;
     //if the substring is odd 
     for(int i=1;i<n;i++){
         int left=i-1;
         int right=i+1;
         
         while((left>=0&&right<n)&&s[left]==s[right]){
             if(maxlen<right-left+1){
                 maxlen=right-left+1;
                 start=left;
             }
             left--;
             right++;
         }
     }
     //for even substring
     for(int i=0;i<n;i++){
         int left=i;
         int right=i+1;
         while((left>=0&&right<n)&&s[left]==s[right]){
              if(maxlen<right-left+1){
                 maxlen=right-left+1;
                 start=left;
             }
             left--;
             right++;
         }
     }
     return s.substr(start,maxlen);
    }
};