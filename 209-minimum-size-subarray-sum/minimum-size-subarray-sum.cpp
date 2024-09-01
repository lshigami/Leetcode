class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int minSize=INT_MAX;
        int left=0;
        for(int right=0;right<nums.size();right+=1){
            sum+=nums[right];
            while(sum>=target){
                minSize=min(minSize,right-left+1);
                sum-=nums[left++];
            }
        }
        return (minSize==INT_MAX)?0:minSize;
    }
};