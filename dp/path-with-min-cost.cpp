https://leetcode.com/problems/path-with-minimum-effort/description/?envType=daily-question&envId=2023-09-16




1631. Path With Minimum Effort
Medium
4.8K
163
Companies
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].



code::-->
class Solution
{
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    // we have defined the change in coordinate if they move in specific directions 

    bool isvalid(int x, int y, int n, int mid)
    {
        return (x >= 0 && x < n && y >= 0 && y < mid);
        // to check whether on which path we are moving is valid or not 
    }


    bool bfs(vector<vector<int>> heights, int k)
    {
        queue<pair<int, int>> q;
        // queue to perform the BFS logic 
        q.push({0, 0});
        // initially push the first cell of matrix 
        vector<vector<bool>> visited(101, vector<bool>(101, false));
        // make a visisted array initially with all the value false initially 
        visited[0][0] = 1;
        // since it visited , makr it a true  

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            // pick out the front 
            q.pop();
            int cx = curr.first;
            int cy = curr.second;
            // get the current x and y 
            if (cx == heights.size() - 1 && cy == heights[0].size() - 1)
                return true;
            // if we are reached the last index we are done
            // else just go in all 4 direction and check conditions  
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + cx;
                int y = dy[i] + cy;
                // each time make new x , y 
                if (isvalid(x, y, heights.size(), heights[0].size()) && !visited[x][y])
                {
                    // if that x,y is valid , just check tah absolute difference is less tha tha mid or not 
                    if (abs(heights[cx][cy] - heights[x][y]) <= k)
                    {
                        visited[x][y] = true;
                        // if yes visit that node 
                        q.push({x, y});
                        // push it in queue 
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // we have similar binary search template  

        int low = 0;
        int high = 1e6;
        int ans = -1;

        // set high and low  

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // get a mid 
            // apply bfs over that mid value 
            if (bfs(heights, mid))
            {
                // if that bfs on that value return true , it might be our answer , so store it 
                ans = mid;
                high = mid - 1;
                // since we want want min value , high=mid-1
            }
            else
            {
                low = mid + 1;
                // else increase the value and check for it 
            }
        }
        return ans;
        //  return the ans 
    }
};

