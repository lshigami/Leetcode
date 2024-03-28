class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int left=0;
        int right=0;
        int ans=1;
        while(right<nums.size()){
            m[nums[right]]++;
            while(m[nums[right]]>k){
                m[nums[left++]]-=1;
            }
            ans=max(right-left+1,ans);
            right+=1;
        }
        return ans;
    }
};