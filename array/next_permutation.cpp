/*
Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
 More formally, if all the permutations of the array are sorted in one container according to their lexicographical
order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]

*/




class Solution {
    private:
    
   void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

     void reverse(vector<int>& nums, int start) {
        int i = start, j=nums.size()-1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
       int pivot=nums.size()-2;//we start from right most element and find an element which is less than its right element ie pivot element;
       while(pivot>=0&&nums[pivot]>=nums[pivot+1]){
           pivot--;
       }
    //    cout<<pivot<<endl;
       if(pivot>=0){
           int successor=nums.size()-1;  //successor element is that element which is greater than the pivot element ;
           while(successor>=0&&nums[successor]<=nums[pivot]){
               successor--;
           }
        //    cout<<successor<<endl;
        //    cout<<"Entering"<<endl;
           swap(nums,pivot,successor);//swap the pivot and successor element ;
           reverse(nums,pivot+1);//reverse the array which is right side of the pivot;
       }
       else{
           reverse(nums,0); // if the array is already increasing then reverse the whole array;
       }
    }
};