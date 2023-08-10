link::-->https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/0


Flood fill Algorithm
MediumAccuracy: 41.11%Submissions: 92K+Points: 4
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.



code::-->

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void helper(int i,int j,int m,int n,int color,int newcolor,vector<vector<int>>& image ){
    if(i<0||j<0||i>=m||j>=n||image[i][j]!=color||image[i][j]==newcolor)return;
    image[i][j]=newcolor;
    helper(i-1,j,m,n,color,newcolor,image);
     helper(i+1,j,m,n,color,newcolor,image);
      helper(i,j-1,m,n,color,newcolor,image);
       helper(i,j+1,m,n,color,newcolor,image);
 
    
}

  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        
        int stcol=image[sr][sc];
        helper(sr,sc,m,n,stcol,newColor,image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends