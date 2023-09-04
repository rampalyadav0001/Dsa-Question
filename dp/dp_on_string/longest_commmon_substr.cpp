https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


iterative code:
int lcs(string &str1, string &str2){
    int n=str1.size();
    int m=str2.size();
     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }
    int ans=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans=max(ans,dp[i][j]);
            } else {
                dp[i][j] =0;
            }
        }
    }
    return ans;
}


recursive code::
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcsRecursive(int i, int j, int count, string &str1, string &str2) {
    // Base case: If either of the strings is empty, return the current count
    if (i == 0 || j == 0) {
        return count;
    }

    // If the last characters of both strings match
    if (str1[i - 1] == str2[j - 1]) {
        count = lcsRecursive(i - 1, j - 1, count + 1, str1, str2);
    }

    // Recursively check the next characters in both strings
    count = max(count, max(lcsRecursive(i - 1, j, 0, str1, str2), lcsRecursive(i, j - 1, 0, str1, str2)));

    return count;
}

int lcs(string &str1, string &str2) {
    int n = str1.size();
    int m = str2.size();
    int ans = lcsRecursive(n, m, 0, str1, str2);
    return ans;
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int length = lcs(str1, str2);
    cout << "Length of Longest Common Substring: " << length << endl;
    return 0;
}
