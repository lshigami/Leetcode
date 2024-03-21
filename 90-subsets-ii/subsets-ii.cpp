class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> seen;
        vector<vector<int>>ans;
        for(int x=0;x<(1<<nums.size());x++){
            vector<int>v;
            for(int i=0;i<nums.size();i++){
                if((x>>i)&1) v.push_back(nums[i]);
            }
            seen.insert(v);
        }
        for(auto x:seen){
            ans.push_back(x);
        }
        return ans;
    }
};