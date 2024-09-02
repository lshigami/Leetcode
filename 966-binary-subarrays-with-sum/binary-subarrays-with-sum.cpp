class Solution {
public:
    int atMost(vector<int>&nums,int goal){
        int sum=0;
        int left=0;
        int cnt=0;
        for(int right=0;right<nums.size();right+=1){
            sum+=nums[right];
            while(left<=right && sum>goal){
                sum-=nums[left++];
            }
            cnt+=right-left+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};