class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxsum;
    }
};