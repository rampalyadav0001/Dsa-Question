https://leetcode.com/problems/count-number-of-nice-subarrays/description/


Code
Testcase
Testcase

1248. Count Number of Nice Subarrays
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16




code ::--> replace odd no with one and even no.with zeroes and count subarray sum equal to k;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        unordered_map<int ,int>mp;
        int right=0,ans=0;
        mp[0]=1;
        int pre=0;
        while(right<nums.size()){
          pre+=nums[right];
          mp[pre]++;
          int temp=pre-k;
          if(mp[temp]>0){
              ans+=mp[temp];
          }
          right++;
        }
        return ans;
    }
};


code::
class Solution {
public:
  int numberofsubarraywithatmostkoddelement(vector<int>&nums,int k){

       int oddNo=0;
       int count=0;
       int left=0,right=0;
       while(right<nums.size()) {
        if(nums[right]%2!=0){
            oddNo++;
        }
     while(oddNo>k&&left<=right){
         if(nums[left]%2!=0){
             oddNo--;
         }
        left++;
       
        }
        count+=right-left+1;
        
       
        right++;
       }
       return count;
    }
  
    int numberOfSubarrays(vector<int>& nums, int k) {
     return numberofsubarraywithatmostkoddelement(nums,k)-numberofsubarraywithatmostkoddelement(nums,k-1);
    }
};