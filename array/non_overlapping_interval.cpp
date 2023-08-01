link::-->>https://leetcode.com/problems/non-overlapping-intervals/description/


Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


code::==>>>
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
 sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });        int lastpoint=intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(lastpoint>intervals[i][0]){
                ans++;
            }
           else lastpoint=intervals[i][1];
        }
        return ans;
    }
};