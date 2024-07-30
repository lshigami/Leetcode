class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>ans;
        ans.push_back(cur);
        backtrack(nums,cur,ans,0);
        return ans;
    }
    void backtrack(vector<int>nums,vector<int>cur,vector<vector<int>>&ans,int start){
        for(int i=start;i<nums.size();i++){
            cur.push_back(nums[i]);
            ans.push_back(cur);
            backtrack(nums,cur,ans,i+1);
            cur.pop_back();

        }
    }

};