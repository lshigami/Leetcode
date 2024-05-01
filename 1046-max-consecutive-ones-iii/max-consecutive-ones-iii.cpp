class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZero=0;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right+=1){
            if(nums[right]==0) countZero+=1;
            while(countZero>k){
                if(nums[left++]==0) countZero-=1;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};