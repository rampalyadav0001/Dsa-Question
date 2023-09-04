https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


Palindromic Partitioning
HardAccuracy: 27.82%Submissions: 96K+Points: 8
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.

code::-->
class Solution{
public:
    bool ispali(int start, int end, string & s) {

        while(start < end) {
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int f(int index, int n, string &str, vector<int>&dp) {
        if(index == n)return 0;
        
        if(dp[index]!=-1)return dp[index];
        int steps = INT_MAX;
        
        for(int j = index;j<n;j++) {
            if(ispali(index, j, str)){
                int cost = 1 + f(j+1, n, str, dp);
                steps = min(steps, cost);
            }
        }
        return dp[index] = steps;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int>dp(n+1, -1);
        return f(0, n, str, dp)-1;
    }
};

code::-->

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int count = solve(s, i, k, dp) + solve(s, k + 1, j, dp) + 1;
            ans = min(ans, count);
        }

        dp[i][j] = ans;
        return ans;
    }

    int palindromicPartition(string str) {
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(str, 0, n - 1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends