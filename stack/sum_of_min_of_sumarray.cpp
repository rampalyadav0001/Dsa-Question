https://leetcode.com/problems/sum-of-subarray-minimums/description/
907. Sum of Subarray Minimums
Medium
6.7K
435
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

Approach::
Before diving into the solution, we first introduce a very important stack type, which is called monotone stack .

What is monotonous increase stack?
Roughly speaking, the elements in the an monotonous increase stack keeps an increasing order.

The typical paradigm for monotonous increase stack:
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && in_stk.top() > A[i]){
    in_stk.pop();
  }
  in_stk.push(A[i]);
}
What can monotonous increase stack do?
(1) find the previous less element of each element in a vector with O(n) time:
What is the previous less element of an element?
For example:
[3, 7, 8, 4]
The previous less element of 7 is 3.
The previous less element of 8 is 7.
The previous less element of 4 is 3.
There is no previous less element for 3.
For simplicity of notation, we use abbreviation PLE to denote Previous Less Element.

C++ code (by slitghly modifying the paradigm):
Instead of directly pushing the element itself, here for simplicity, we push the index.
We do some record when the index is pushed into the stack.
// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    in_stk.pop();
  }
  previous_less[i] = in_stk.empty()? -1: in_stk.top();
  in_stk.push(i);
}
(2) find the next less element of each element in a vector with O(n) time:
What is the next less element of an element?
For example:
[3, 7, 8, 4]
The next less element of 8 is 4.
The next less element of 7 is 4.
There is no next less element for 3 and 4.
For simplicity of notation, we use abbreviation NLE to denote Next Less Element.

C++ code (by slighly modifying the paradigm):
We do some record when the index is poped out from the stack.
// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    auto x = in_stk.top(); in_stk.pop();
    next_less[x] = i;
  }
  in_stk.push(i);
}
How can the monotonous increase stack be applied to this problem?
For example:
Consider the element 3 in the following vector:

                            [2, 9, 7, 8, 3, 4, 6, 1]
			     |                    |
	             the previous less       the next less 
	                element of 3          element of 3
After finding both NLE and PLE of 3, we can determine the
distance between 3 and 2(previous less) , and the distance between 3 and 1(next less).
In this example, the distance is 4 and 3 respectively.

How many subarrays with 3 being its minimum value?
The answer is 4*3.

9 7 8 3 
9 7 8 3 4 
9 7 8 3 4 6 
7 8 3 
7 8 3 4 
7 8 3 4 6 
8 3 
8 3 4 
8 3 4 6 
3 
3 4 
3 4 6
How much the element 3 contributes to the final answer?
It is 3*(4*3).
What is the final answer?
Denote by left[i] the distance between element A[i] and its PLE.
Denote by right[i] the distance between element A[i] and its NLE.

The final answer is,
sum(A[i]*left[i]*right[i] )

code::=>

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> prev_smaller(n), next_smaller(n);

        // Calculate the distance to the previous smaller element for each element in the array.
        for (int i = 0; i < n; i++) {
            int curr_ind = i;
            while (!s1.empty() && arr[s1.top()] >= arr[curr_ind]) {
                s1.pop();
            }
            prev_smaller[i] = (s1.empty()) ? i + 1 : i - s1.top();
            s1.push(curr_ind);
        }

        // Calculate the distance to the next smaller element for each element in the array.
        for (int i = n - 1; i >= 0; i--) { 
            int curr_index = i;
            while (!s2.empty() && arr[s2.top()] > arr[curr_index]) { 
                s2.pop();
            }
            next_smaller[i] = (s2.empty()) ? n - i : s2.top() - i;
            s2.push(curr_index);
        }

        int ans = 0;
        int MOD = 1000000007; // Define the modulus value

        // Calculate the sum of minimum values for all subarrays and prevent overflow.
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * next_smaller[i] * prev_smaller[i]) % MOD;
        }
        return ans;
    }
};

