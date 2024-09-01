class Solution {
public:
    int subarrayWithAtMostKDistinct(vector<int>&nums,int k){
        unordered_map<int,int>m;
        int res=0;
        int left=0;
        for(int right=0;right<nums.size();right+=1){
            m[nums[right]]+=1;
            while(m.size()>k){
                if(m[nums[left]]==1) m.erase(nums[left]);
                else m[nums[left]]-=1;
                left+=1;
            }
            res+=(right-left+1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostKDistinct(nums,k)-subarrayWithAtMostKDistinct(nums,k-1);
    }
};