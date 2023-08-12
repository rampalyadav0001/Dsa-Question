https://practice.geeksforgeeks.org/problems/black-and-white-1587115620/1


code::-->
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other
bool isvalid(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int solve(int i, int j, int n, int m) {
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int count = 0;
    
    for (int k = 0; k < 8; k++) {
        if (isvalid(i + dx[k], j + dy[k], n, m)) {
            count++;
        }
    }
    
    return count;
}

long long numOfWays(int N, int M) {
    int mod = 1e9 + 7;  // Update the mod value for correct calculation
    long long count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp = solve(i, j, N, M) + 1;
            count = (count + N * M - temp) % mod;  // Update the count calculation
        }
    }
    
    return count;
}
