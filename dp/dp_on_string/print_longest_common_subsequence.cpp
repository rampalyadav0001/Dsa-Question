https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

in this question we basicaly print the longest common subsequence in string s1 and s2;



iterative code using dp array;


string findLCS(int n, int m, string &s1, string &s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];
    string ans(len, ' ');  
    int index = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans[index] = s1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return ans;
}


recursive code::
#include <iostream>
#include <string>

using namespace std;

// Recursive function to find the Longest Common Subsequence (LCS)
string findLCS(int i, int j, string &s1, string &s2) {
    // Base case: If either of the strings is empty, return an empty string
    if (i == 0 || j == 0) {
        return "";
    }

    // If the last characters of both strings match
    if (s1[i - 1] == s2[j - 1]) {
        return findLCS(i - 1, j - 1, s1, s2) + s1[i - 1];
    }

    // If the last characters do not match, choose the longer of the two subsequences
    string lcs1 = findLCS(i - 1, j, s1, s2);
    string lcs2 = findLCS(i, j - 1, s1, s2);

    if (lcs1.length() > lcs2.length()) {
        return lcs1;
    } else {
        return lcs2;
    }
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.length();
    int m = s2.length();
    string lcs = findLCS(n, m, s1, s2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    return 0;
}
