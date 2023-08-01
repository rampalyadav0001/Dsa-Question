. Maximum Points You Can Obtain from Cards
Medium
5.5K
202
Companies
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
LINK::-->https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/


approach::-->>
Let the sum of all points be total_pts. You need to remove a sub-array from cardPoints with length n - k.
Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow)


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int answer=INT_MIN,total_points=0,n=cardPoints.size(),windowsum=0;
      for(auto it:cardPoints)total_points+=it;
      for(int i=0;i<n-k;i++){
          windowsum+=cardPoints[i];
      }
      answer=max(answer,total_points-windowsum);
      for(int i=n-k;i<n;i++){
          windowsum-=cardPoints[i-(n-k)];
          windowsum+=cardPoints[i];
          answer=max(answer,total_points-windowsum);
      }
      return answer;
    }
};