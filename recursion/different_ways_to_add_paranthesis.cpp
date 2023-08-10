link::-->>https://leetcode.com/problems/different-ways-to-add-parentheses/



241. Different Ways to Add Parentheses
Medium
5K
235
Companies
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10



code::--->>

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        for(int i=0;i<expression.length();i++){
            char ch=expression[i];
            if(ch=='*'||ch=='-'||ch=='+'){
                string a=expression.substr(0,i);
                string b=expression.substr(i+1);
                vector<int> v1=diffWaysToCompute(a);
                vector<int> v2=diffWaysToCompute(b);
                for(auto x:v1){
                    for(auto y:v2){
                        if(ch=='*'){
                          ans.push_back(x*y);
                        }
                        else if(ch=='+'){
                          ans.push_back(x+y);
                        }
                        else if(ch=='-'){
                          ans.push_back(x-y);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
        ans.push_back(atoi(expression.c_str()));
        }
        return ans;
    }
};