https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/






brute-force recursion::-->
class Solution {
public:
void solve(int start,int end,int k,int &count){
    if(start==end&&k==0){
        count++;
        return;
    }
    if(k>0){
    solve(start+1,end,k-1,count);
    solve(start-1,end,k-1,count);
    }
}
    int numberOfWays(int startPos, int endPos, int k) {
       int count=0;
       solve(startPos,endPos,k,count);
       return count; 
    }
};

dp approach::-->>
class Solution {
public:
int mod=1e9+7;
    int solve(int start, int end, int k, vector<vector<int>>& dp) {
        if (start == end && k == 0) {
            return 1;
        }
        if (k < 0) {
            return 0;
        }
        if (dp[start+1000][k] != -1) {
            return dp[start+1000][k];
        }
        int right = solve(start + 1, end, k - 1, dp);
        int left = solve(start - 1, end, k - 1, dp);
        dp[start+1000][k] =( left + right)%mod;
        return dp[start+1000][k]%mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3100, vector<int>(1001, -1));
        return solve(startPos, endPos, k, dp);
    }
};
