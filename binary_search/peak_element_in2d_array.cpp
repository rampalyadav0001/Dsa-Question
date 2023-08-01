/*
 Find a Peak Element II

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
*/
https://www.geeksforgeeks.org/find-peak-element-2d-array/?ref=lbp


// in this question first we have to find the mid column and max element in mid column;
// This problem is mainly an extension of Find a peak element in 1D array. We apply similar Binary Search based solution here, as shown below: 

// Consider mid column and find maximum element in it.
// Let index of mid column be ‘mid’, value of maximum element in mid column be ‘max’ and maximum element be at ‘mat[max_index][mid]’. 
// If max >= A[index][mid-1] & max >= A[index][mid+1], max is a peak, return max.
// If max < mat[max_index][mid-1], recur for left half of matrix.
// If max < mat[max_index][mid+1], recur for right half of matrix.

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int stcol=0,endcol=col-1,mid,ansrow;
        while(stcol<=endcol){
              mid=stcol+(endcol-stcol)/2;
             ansrow=0;
              for(int i=0;i<row;i++){
                  ansrow=(mat[i][mid]>=mat[ansrow][mid])?i:ansrow;
              }
              bool left=mid-1>=stcol&&mat[ansrow][mid-1]>mat[ansrow][mid];//here we check is there is nay greate element in left;
              bool right=mid+1<=endcol&&mat[ansrow][mid+1]>mat[ansrow][mid];//here we check is their is any greater element in right ;
              if(!left &&  !right){
                  return {ansrow,mid};
              }
             else if(right){
                  stcol=mid+1;
              }
              else{
                  endcol=mid-1;
              }
        }
        return {-1,-1};
    }
};