class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int cnt=nums[0]==1;
        ans=max(ans,cnt);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1) {
                cnt++;
                ans=max(ans,cnt); 
            } 
            else cnt=0;
        }
        return ans;
    }
};