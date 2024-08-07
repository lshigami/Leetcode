class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maximum = *max_element(nums.begin(),nums.end());
        long long ans=0;
        int left=0;
        int counter=0;
        //[1,3,2,3,1]
        // 0 1 2 3 4
        for(int right=0;right<nums.size();right+=1){
            if(nums[right]==maximum) counter+=1;
            while(counter==k){
                ans+=nums.size()-right;
                if(nums[left]==maximum) counter-=1;
                left+=1;
            }
        }

        return ans;
    }
};