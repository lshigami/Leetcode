class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int x=0;x<(1<<n);x++){
            vector<int>v;
            for(int i=0;i<n;i++){
                if((x>>i)&1) v.push_back(nums[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};