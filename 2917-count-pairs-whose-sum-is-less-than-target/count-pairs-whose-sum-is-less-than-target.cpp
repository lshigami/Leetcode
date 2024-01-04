class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]<target){
                ans+=r-l;
                l++;
            }
            else r--;
        }
        return ans;
    }
};