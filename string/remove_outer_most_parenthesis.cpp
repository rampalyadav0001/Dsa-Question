https://leetcode.com/problems/remove-outermost-parentheses/description/Remove 


Remove Outermost Parentheses
Easy
2.3K
1.5K
Companies
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".


approach::-->when we find an open paranthesis we put it on the stack and when we find closed parantheis we remove the open paranthesis from the stack except the outer most parathesis(if stack size is one that paranthesis is outermost);

class Solution {
public:
    string removeOuterParentheses(string s) {
       stack<char>st;
       string ans;
       for(int i=0;i<s.size();i++){
           if(s[i]=='('){
               st.push(s[i]);
               if(st.size()>1){
                   ans+=s[i];
               }
               
               }
           else{
               if(st.size()>1&&!st.empty()){
                   st.pop();
                   ans+=s[i];
                   
               }
               else{
                   st.pop();
               }
           }
       }
       return ans;
    }
};