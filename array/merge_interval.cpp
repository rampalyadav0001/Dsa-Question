https://leetcode.com/problems/merge-intervals/description/
56. Merge Intervals
Medium
20.1K
676
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Ist approach--->>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        for(int i=0;i<intervals.size();i++){
            if(merged.empty()||merged.back()[1]<intervals[i][0]){// NO overlaped interval present;
                merged.push_back(intervals[i]);
            }
            else{
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
        }
        return merged;
    }
};

secondapproach::-->>
#include <vector>
#include <algorithm>

class Solution {
public:
  

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> mergedInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= mergedInterval[1]) {
                // Merge the current interval with the mergedInterval
                mergedInterval[1] = max(mergedInterval[1], intervals[i][1]);
            } else {
                // Add the mergedInterval to the result and start a new mergedInterval
                result.push_back(mergedInterval);
                mergedInterval = intervals[i];
            }
        }

        // Add the last mergedInterval to the result
        result.push_back(mergedInterval);

        return result;
    }
};