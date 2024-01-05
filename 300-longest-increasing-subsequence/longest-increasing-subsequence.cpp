class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(auto x:nums){
            if(x>ans[ans.size()-1]) ans.push_back(x);
            else{
                auto it=lower_bound(ans.begin(),ans.end(),x);
                *it=x;
            }
        }
        return ans.size();
    }
};