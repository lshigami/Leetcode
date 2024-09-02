class Solution {
public:
    int atMost(vector<int>&nums,int goal){
        int sum=0;
        int left=0;
        int cnt=0;
        for(int right=0;right<nums.size();right+=1){
            sum+=(nums[right]%2);
            while(left<=right && sum>goal){
                sum-=nums[left]%2;
                left+=1;
            }
            cnt+=right-left+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};